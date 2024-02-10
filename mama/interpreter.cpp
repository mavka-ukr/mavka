#include "mama.h"

#define DO_THROW_STRING(v)           \
  M->stack.push(create_string((v))); \
  I = MaInstruction{OP_THROW};       \
  goto i_start;

#define DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(name, type)                    \
  DO_THROW_STRING("Дію \"" + std::string(name) +                          \
                  "\" не визначено для типу \"" + getcelltypename(type) + \
                  "\".")

#define DO_THROW_CANNOT_CALL_CELL(cell) \
  DO_THROW_STRING("Неможливо викликати \"" + getcelltypename(cell) + "\".")

#define IS_EMPTY(cell) ((cell).type == MA_CELL_EMPTY)
#define IS_NUMBER(cell) ((cell).type == MA_CELL_NUMBER)
#define IS_YES(cell) ((cell).type == MA_CELL_YES)
#define IS_NO(cell) ((cell).type == MA_CELL_NO)
#define IS_OBJECT(cell) ((cell).type == MA_CELL_OBJECT)
#define IS_OBJECT_STRING(cell) (cell).v.object->type == MA_OBJECT_STRING

#define PUSH(cell) M->stack.push(cell)
#define PUSH_EMPTY() PUSH(MA_MAKE_EMPTY())
#define PUSH_NUMBER(v) PUSH(MA_MAKE_NUBMER((v)))
#define PUSH_YES() PUSH(MA_MAKE_YES())
#define PUSH_NO() PUSH(MA_MAKE_NO())

#define TOP() M->stack.top();
#define TOP_VALUE(name) const auto name = TOP();
#define POP() M->stack.pop();
#define POP_VALUE(name)    \
  const auto name = TOP(); \
  POP();

#define OBJECT_STRING_DATA(cell) (cell).v.object->d.string->data

#define READ_TOP_FRAME() const auto frame = M->call_stack.top();
#define FRAME_POP() M->call_stack.pop();
#define FRAME_PUSH(frame) M->call_stack.push(frame);

namespace mavka::mama {
  inline bool initcall(MaMa* M, MaCell cell, const size_t return_index) {
    READ_TOP_FRAME();

  repeat_op_initcall:
    if (cell.type == MA_CELL_OBJECT) {
      const auto object = cell.v.object;

      if (object->type == MA_OBJECT_DIIA_NATIVE) {
        FRAME_PUSH(new MaCallFrame({.scope = frame->scope,
                                    .diia_native = object,
                                    .return_index = return_index}));
        return true;
      }
      if (object->type == MA_OBJECT_DIIA) {
        FRAME_PUSH(new MaCallFrame({.scope = frame->scope,
                                    .diia = object,
                                    .return_index = return_index}));
        return true;
      }
      if (object->type == MA_OBJECT_STRUCTURE) {
        FRAME_PUSH((new MaCallFrame{.scope = frame->scope,
                                    .structure = object,
                                    .return_index = return_index}));
        return true;
      }
      if (object->type == MA_OBJECT) {
        cell = ma_object_get(object, MAG_CALL);
        goto repeat_op_initcall;
      }
    }

    return false;
  }

  void run(MaMa* M) {
    M->i = 0;
    const auto size = M->code.size();
    for (;;) {
    start:
      if (M->i >= size) {
        return;
      }
      auto I = M->code[M->i];

    i_start:
      DEBUG_DO(print_instruction_with_index(M->i, I))

      switch (I.op) {
        case OP_POP: {
          POP();
          break;
        }
        case OP_CONSTANT: {
          PUSH(M->constants[I.args.constant]);
          break;
        }
        case OP_NUMBER: {
          PUSH_NUMBER(I.args.number);
          break;
        }
        case OP_EMPTY: {
          PUSH_EMPTY();
          break;
        }
        case OP_YES: {
          PUSH_YES();
          break;
        }
        case OP_NO: {
          PUSH_NO();
          break;
        }
        case OP_INITCALL: {
          POP_VALUE(cell);
          if (initcall(M, cell, I.args.initcall->index)) {
            break;
          }
          DO_THROW_CANNOT_CALL_CELL(cell);
        }
        case OP_STORE_ARG: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          frame->args.insert_or_assign(I.args.store->name, value);
          break;
        }
        case OP_CALL: {
          READ_TOP_FRAME();
          if (frame->diia_native) {
            const auto result = frame->diia_native->d.diia_native->fn(
                M, frame->diia_native->d.diia_native->me, frame->args);
            PUSH(result);
            frame->args.clear();
            FRAME_POP();
            break;
          }
          if (frame->diia) {
            frame->scope = new MaScope(frame->diia->d.diia->scope);
            if (frame->diia->d.diia->me) {
              frame->scope->set_variable(
                  "я",
                  MaCell{MA_CELL_OBJECT, {.object = frame->diia->d.diia->me}});
            }
            for (int i = 0; i < frame->diia->d.diia->params.size(); ++i) {
              const auto& param = frame->diia->d.diia->params[i];
              if (frame->args.contains(std::to_string(i))) {
                frame->scope->set_variable(param.name,
                                           frame->args[std::to_string(i)]);
              } else if (frame->args.contains(param.name)) {
                frame->scope->set_variable(param.name, frame->args[param.name]);
              } else {
                frame->scope->set_variable(param.name, param.default_value);
              }
            }
            frame->args.clear();
            M->i = frame->diia->d.diia->index;
            goto start;
          }
          if (frame->structure) {
            const auto object_cell = create_object(frame->structure);
            for (int i = 0; i < frame->structure->d.structure->params.size();
                 ++i) {
              const auto& param = frame->structure->d.structure->params[i];
              if (frame->args.contains(std::to_string(i))) {
                ma_object_set(object_cell.v.object, param.name,
                              frame->args[std::to_string(i)]);
              } else if (frame->args.contains(param.name)) {
                ma_object_set(object_cell.v.object, param.name,
                              frame->args[param.name]);
              } else {
                ma_object_set(object_cell.v.object, param.name,
                              param.default_value);
              }
            }
            PUSH(object_cell);
            frame->args.clear();
            FRAME_POP();
            break;
          }
          DO_THROW_STRING("Неможливо викликати.")
        }
        case OP_RETURN: {
          auto frame = M->call_stack.top();
          FRAME_POP();
          while (frame->catch_index != 0) {
            frame = M->call_stack.top();
            FRAME_POP();
          }
          DEBUG_LOG("returning to " + std::to_string(M->i));
          M->i = frame->return_index;
          goto start;
        }
        case OP_DIIA: {
          READ_TOP_FRAME();
          const auto diia_cell = create_diia(I.args.diia->index);
          diia_cell.v.object->d.diia->scope = frame->scope;
          ma_object_set(diia_cell.v.object, "назва",
                        create_string(I.args.diia->name));
          PUSH(diia_cell);
          break;
        }
        case OP_DIIA_PARAM: {
          POP_VALUE(default_value_cell);
          TOP_VALUE(diia_cell);
          diia_cell.v.object->d.diia->params.push_back(
              MaDiiaParam{.name = I.args.diiaparam->name,
                          .default_value = default_value_cell});
          break;
        }
        case OP_STORE: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          frame->scope->set_variable(I.args.store->name, value);
          break;
        }
        case OP_LOAD: {
          READ_TOP_FRAME();
          const auto scope = frame->scope;
          if (scope->has_variable(I.args.load->name)) {
            PUSH(scope->get_variable(I.args.load->name));
            break;
          }
          DO_THROW_STRING("Субʼєкт \"" + I.args.load->name + "\" не визначено.")
        }
        case OP_JUMP: {
          M->i = I.args.jump;
          goto start;
        }
        case OP_JUMP_IF_TRUE: {
          POP_VALUE(cell);
          if (IS_NUMBER(cell) && cell.v.number != 0.0) {
            M->i = I.args.jumpiftrue;
            goto start;
          }
          if (!IS_NO(cell)) {
            M->i = I.args.jumpiftrue;
            goto start;
          }
          break;
        }
        case OP_JUMP_IF_FALSE: {
          POP_VALUE(cell);
          if (IS_EMPTY(cell)) {
            M->i = I.args.jumpiffalse;
            goto start;
          } else if (IS_NUMBER(cell)) {
            if (cell.v.number == 0.0) {
              M->i = I.args.jumpiffalse;
              goto start;
            }
          } else if (IS_NO(cell)) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          break;
        }
        case OP_E_JUMP_IF_TRUE: {
          TOP_VALUE(cell);
          if (IS_NUMBER(cell)) {
            if (cell.v.number != 0.0) {
              M->i = I.args.jumpiftrue;
              goto start;
            }
          } else if (!IS_NO(cell)) {
            M->i = I.args.jumpiftrue;
            goto start;
          }
          break;
        }
        case OP_E_JUMP_IF_FALSE: {
          TOP_VALUE(cell);
          if (IS_EMPTY(cell)) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          if (IS_NUMBER(cell) && cell.v.number == 0.0) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          if (IS_NO(cell)) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          break;
        }
        case OP_GET: {
          POP_VALUE(cell);
          if (cell.type == MA_CELL_OBJECT) {
            PUSH(ma_object_get(cell.v.object, I.args.get->name));
          } else {
            PUSH_EMPTY();
          }
          break;
        }
        case OP_SET: {
          POP_VALUE(cell);
          POP_VALUE(value);
          if (IS_OBJECT(cell)) {
            ma_object_set(cell.v.object, I.args.set->name, value);
          }
          break;
        }
        case OP_TRY: {
          READ_TOP_FRAME();
          FRAME_PUSH((new MaCallFrame{
              .scope = frame->scope, .catch_index = I.args.try_->catch_index}));
          break;
        }
        case OP_TRY_DONE: {
          FRAME_POP();
          M->i = I.args.trydone->index;
          break;
        }
        case OP_THROW: {
          while (!M->call_stack.empty()) {
            READ_TOP_FRAME();
            FRAME_POP();
            const auto catch_index = frame->catch_index;
            if (catch_index) {
              M->i = catch_index;
              goto start;
            }
          }
          std::cout << "Не вдалось зловити: " << cell_to_string(M->stack.top())
                    << std::endl;
          return;
        }
        case OP_LIST: {
          PUSH(create_list());
          break;
        }
        case OP_LIST_APPEND: {
          POP_VALUE(value);
          TOP_VALUE(list_cell);
          list_cell.v.object->d.list->append(value);
          break;
        }
        case OP_DICT: {
          PUSH(create_dict());
          break;
        }
        case OP_DICT_SET: {
          POP_VALUE(value);
          TOP_VALUE(dict_cell);
          dict_cell.v.object->d.dict->set(create_string(I.args.dictset->key),
                                          value);
          break;
        }
        case OP_STRUCT: {
          const auto structure_cell = create_structure(I.args.struct_->name);
          PUSH(structure_cell);
          break;
        }
        case OP_STRUCT_PARAM: {
          POP_VALUE(default_value_cell);
          TOP_VALUE(structure_cell);
          structure_cell.v.object->d.structure->params.push_back(
              MaDiiaParam{.name = I.args.diiaparam->name,
                          .default_value = default_value_cell});
          break;
        }
        case OP_STRUCT_METHOD: {
          POP_VALUE(diia_cell);
          TOP_VALUE(structure_cell);
          if (structure_cell.type == MA_CELL_OBJECT) {
            if (structure_cell.v.object->type == MA_OBJECT_STRUCTURE) {
              structure_cell.v.object->d.structure->methods.push_back(
                  diia_cell.v.object);
              break;
            }
          }
          DO_THROW_STRING("Неможливо створити метод для типу " +
                          getcelltypename(structure_cell))
        }
        case OP_MODULE: {
          READ_TOP_FRAME();
          const auto module_cell = create_module(I.args.module->name);
          const auto module_scope = new MaScope(frame->scope);
          FRAME_PUSH((new MaCallFrame{.scope = module_scope,
                                      .module = module_cell.v.object}));
          frame->scope->set_variable(I.args.module->name, module_cell);
          break;
        }
        case OP_GIVE: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          if (frame->module) {
            frame->module->properties.insert_or_assign(I.args.give->name,
                                                       value);
            break;
          }
          DO_THROW_STRING("Неможливо дати \"" + I.args.give->name + "\".")
        }
        case OP_MODULE_DONE: {
          FRAME_POP();
          break;
        }
        case OP_EQ: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_EMPTY(left)) {
            if (IS_EMPTY(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_YES(left)) {
            if (IS_YES(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_NO(left)) {
            if (IS_NO(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number == right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              PUSH_NO();
            }
          } else if (IS_OBJECT(left)) {
            if (IS_OBJECT_STRING(left)) {
              if (IS_OBJECT(right) && IS_OBJECT_STRING(right)) {
                if (OBJECT_STRING_DATA(left) == OBJECT_STRING_DATA(right)) {
                  PUSH_YES();
                } else {
                  PUSH_NO();
                }
              } else {
                PUSH_NO();
              }
            } else {
              if (left.v.object == right.v.object) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            }
          } else {
            PUSH_NO();
          }
          break;
        }
        case OP_GT: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number > right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_GREATER) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_GREATER)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_GREATER);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GREATER, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GREATER, left);
          }
          break;
        }
        case OP_GE: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number >= right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_GREATER_EQUAL) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_GREATER_EQUAL)) {
              const auto diia_cell =
                  ma_object_get(left.v.object, MAG_GREATER_EQUAL);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GREATER_EQUAL, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GREATER_EQUAL, left);
          }
          break;
        }
        case OP_LT: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number < right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_LESSER) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_LESSER)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_LESSER);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER, left);
          }
          break;
        }
        case OP_LE: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number <= right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_LESSER_EQUAL) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_LESSER_EQUAL)) {
              const auto diia_cell =
                  ma_object_get(left.v.object, MAG_LESSER_EQUAL);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER_EQUAL, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER_EQUAL, left);
          }
          break;
        }
        case OP_NOT: {
          POP_VALUE(value);
          if (IS_EMPTY(value)) {
            PUSH_YES();
          } else if (IS_NUMBER(value)) {
            if (value.v.number == 0.0) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_YES(value)) {
            PUSH_NO();
          } else if (IS_NO(value)) {
            PUSH_YES();
          } else {
            PUSH_NO();
          }
          break;
        }
        case OP_NEGATIVE: {
          POP_VALUE(value);
          if (IS_NUMBER(value)) {
            PUSH_NUMBER(-value.v.number);
          } else if (IS_OBJECT(value)) {
            if (value.v.object->properties.contains(MAG_NEGATIVE)) {
              const auto diia_cell =
                  ma_object_get(value.v.object, MAG_NEGATIVE);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_NEGATIVE, value);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_NEGATIVE, value);
          }
          break;
        }
        case OP_POSITIVE: {
          POP_VALUE(value);
          if (IS_NUMBER(value)) {
            PUSH_NUMBER(value.v.number * -1);
          } else if (IS_OBJECT(value)) {
            if (value.v.object->properties.contains(MAG_POSITIVE)) {
              const auto diia_cell =
                  ma_object_get(value.v.object, MAG_POSITIVE);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_POSITIVE, value);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_POSITIVE, value);
          }
          break;
        }
        case OP_BNOT: {
          POP_VALUE(value);
          if (IS_NUMBER(value)) {
            PUSH_NUMBER(
                static_cast<double>(~static_cast<long>(value.v.number)));
          } else if (IS_OBJECT(value)) {
            if (value.v.object->properties.contains(MAG_BW_NOT)) {
              const auto diia_cell = ma_object_get(value.v.object, MAG_BW_NOT);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_NOT, value);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_NOT, value);
          }
          break;
        }
        case OP_ADD: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number + right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_ADD) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (IS_OBJECT_STRING(left)) {
              if (IS_NUMBER(right)) {
                PUSH(create_string(OBJECT_STRING_DATA(left) +
                                   ma_number_to_string(right.v.number)));
              } else if (IS_OBJECT(right) && IS_OBJECT_STRING(right)) {
                PUSH(create_string(OBJECT_STRING_DATA(left) +
                                   OBJECT_STRING_DATA(right)));
              } else {
                DO_THROW_STRING("Дія \"" + std::string(MAG_ADD) +
                                "\" для типу \"текст\" "
                                "очікує параметром значення типу \"текст\".")
              }
            } else if (left.v.object->properties.contains(MAG_ADD)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_ADD);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_ADD, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_ADD, left);
          }
          break;
        }
        case OP_SUB: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number - right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_SUB) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_SUB)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_SUB);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_SUB, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_SUB, left);
          }
          break;
        }
        case OP_MUL: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number * right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_MUL) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_MUL)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_MUL);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_MUL, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_MUL, left);
          }
          break;
        }
        case OP_DIV: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number / right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_DIV) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_DIV)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_DIV);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_DIV, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_DIV, left);
          }
          break;
        }
        case OP_MOD: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(fmod(left.v.number, right.v.number));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_MOD) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_MOD)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_MOD);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_MOD, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_MOD, left);
          }
          break;
        }
        case OP_DIVDIV: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(floor(left.v.number / right.v.number));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_DIVDIV) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_DIVDIV)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_DIVDIV);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_DIVDIV, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_DIVDIV, left);
          }
          break;
        }
        case OP_POW: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(pow(left.v.number, right.v.number));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_POW) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_POW)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_POW);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_POW, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_POW, left);
          }
          break;
        }
        case OP_XOR: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) ^
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_XOR) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_BW_XOR)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_BW_XOR);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_XOR, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_XOR, left);
          }
          break;
        }
        case OP_BOR: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) |
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_OR) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_BW_OR)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_BW_OR);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_OR, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_OR, left);
          }
          break;
        }
        case OP_BAND: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) &
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_AND) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_BW_AND)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_BW_AND);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_AND, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_AND, left);
          }
          break;
        }
        case OP_SHL: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number)
                                      << static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_SHIFT_LEFT) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_BW_SHIFT_LEFT)) {
              const auto diia_cell =
                  ma_object_get(left.v.object, MAG_BW_SHIFT_LEFT);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_LEFT, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_LEFT, left);
          }
          break;
        }
        case OP_SHR: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) >>
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_SHIFT_RIGHT) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_BW_SHIFT_RIGHT)) {
              const auto diia_cell =
                  ma_object_get(left.v.object, MAG_BW_SHIFT_RIGHT);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_RIGHT, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_RIGHT, left);
          }
          break;
        }
        case OP_GET_ELEMENT: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_GET_ELEMENT)) {
              const auto diia_cell =
                  ma_object_get(left.v.object, MAG_GET_ELEMENT);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GET_ELEMENT, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GET_ELEMENT, left);
          }
          break;
        }
        case OP_SET_ELEMENT: {
          POP_VALUE(value);
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_OBJECT(left)) {
            if (left.v.object->properties.contains(MAG_SET_ELEMENT)) {
              const auto diia_cell = ma_object_get(left.v.object, MAG_SET_ELEMENT);
              if (!initcall(M, diia_cell, M->i + 1)) {
                DO_THROW_CANNOT_CALL_CELL(diia_cell);
              }
              READ_TOP_FRAME();
              frame->args.insert_or_assign("0", right);
              frame->args.insert_or_assign("1", value);
              I = MaInstruction{OP_CALL};
              goto i_start;
            } else {
              DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_SET_ELEMENT, left);
            }
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_SET_ELEMENT, left);
          }
          break;
        }
        default: {
          std::cout << "unsupported instruction " << getopname(I.op)
                    << std::endl;
          return;
        }
      }

      M->i++;
    }
  }
} // namespace mavka::mama
