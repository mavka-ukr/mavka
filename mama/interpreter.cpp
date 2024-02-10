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

#define PUSH_EMPTY() M->stack.push(MA_MAKE_EMPTY())
#define PUSH_NUMBER(v) M->stack.push(MA_MAKE_NUBMER((v)))
#define PUSH_YES() M->stack.push(MA_MAKE_YES())
#define PUSH_NO() M->stack.push(MA_MAKE_NO())

#define POP_VALUE(name)             \
  const auto name = M->stack.top(); \
  M->stack.pop();

#define OBJECT_STRING_DATA(cell) (cell).v.object->d.string->data

namespace mavka::mama {
  inline bool initcall(MaMa* M, MaCell cell, size_t return_index) {
    const auto frame = M->call_stack.top();

  repeat_op_initcall:
    if (cell.type == MA_CELL_OBJECT) {
      const auto object = cell.v.object;

      if (object->type == MA_OBJECT_DIIA_NATIVE) {
        M->call_stack.push(new MaCallFrame{.scope = frame->scope,
                                           .diia_native = object,
                                           .return_index = return_index});
        return true;
      }
      if (object->type == MA_OBJECT_DIIA) {
        M->call_stack.push(new MaCallFrame{.scope = frame->scope,
                                           .diia = object,
                                           .return_index = return_index});
        return true;
      }
      if (object->type == MA_OBJECT_STRUCTURE) {
        M->call_stack.push(new MaCallFrame{.scope = frame->scope,
                                           .structure = object,
                                           .return_index = return_index});
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
          M->stack.pop();
          break;
        }
        case OP_CONSTANT: {
          M->stack.push(M->constants[I.args.constant]);
          break;
        }
        case OP_NUMBER: {
          M->stack.push(MA_MAKE_NUBMER(I.args.number));
          break;
        }
        case OP_EMPTY: {
          M->stack.push(MA_MAKE_EMPTY());
          break;
        }
        case OP_YES: {
          M->stack.push(MA_MAKE_YES());
          break;
        }
        case OP_NO: {
          M->stack.push(MA_MAKE_NO());
          break;
        }
        case OP_INITCALL: {
          auto cell = M->stack.top();
          M->stack.pop();
          if (initcall(M, cell, I.args.initcall->index)) {
            break;
          }
          DO_THROW_CANNOT_CALL_CELL(cell);
        }
        case OP_STORE_ARG: {
          const auto value = M->stack.top();
          M->stack.pop();
          const auto frame = M->call_stack.top();
          frame->args.insert_or_assign(I.args.store->name, value);
          break;
        }
        case OP_CALL: {
          const auto frame = M->call_stack.top();
          if (frame->diia_native) {
            const auto result = frame->diia_native->d.diia_native->fn(
                M, frame->diia_native->d.diia_native->me, frame->args);
            M->stack.push(result);
            frame->args.clear();
            M->call_stack.pop();
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
            M->stack.push(object_cell);
            frame->args.clear();
            M->call_stack.pop();
            break;
          }
          DO_THROW_STRING("Неможливо викликати.")
        }
        case OP_RETURN: {
          auto frame = M->call_stack.top();
          M->call_stack.pop();
          while (frame->catch_index != 0) {
            frame = M->call_stack.top();
            M->call_stack.pop();
          }
          M->i = frame->return_index;
          DEBUG_LOG("returning to " + std::to_string(M->i))
          goto start;
        }
        case OP_DIIA: {
          const auto diia_cell = create_diia(I.args.diia->index);
          diia_cell.v.object->d.diia->scope = M->call_stack.top()->scope;
          ma_object_set(diia_cell.v.object, "назва",
                        create_string(I.args.diia->name));
          M->stack.push(diia_cell);
          break;
        }
        case OP_DIIA_PARAM: {
          const auto default_value_cell = M->stack.top();
          M->stack.pop();
          const auto diia_cell = M->stack.top();
          diia_cell.v.object->d.diia->params.push_back(
              MaDiiaParam{.name = I.args.diiaparam->name,
                          .default_value = default_value_cell});
          break;
        }
        case OP_STORE: {
          const auto value = M->stack.top();
          M->stack.pop();
          const auto frame = M->call_stack.top();
          frame->scope->set_variable(I.args.store->name, value);
          break;
        }
        case OP_LOAD: {
          const auto frame = M->call_stack.top();
          const auto scope = frame->scope;
          if (scope->has_variable(I.args.load->name)) {
            M->stack.push(scope->get_variable(I.args.load->name));
            break;
          }
          DO_THROW_STRING("Субʼєкт \"" + I.args.load->name + "\" не визначено.")
        }
        case OP_JUMP: {
          M->i = I.args.jump;
          goto start;
        }
        case OP_JUMP_IF_TRUE: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_NUMBER && cell.v.number != 0.0) {
            M->i = I.args.jumpiftrue;
            goto start;
          }
          if (cell.type != MA_CELL_NO) {
            M->i = I.args.jumpiftrue;
            goto start;
          }
          break;
        }
        case OP_JUMP_IF_FALSE: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_EMPTY) {
            M->i = I.args.jumpiffalse;
            goto start;
          } else if (cell.type == MA_CELL_NUMBER) {
            if (cell.v.number == 0.0) {
              M->i = I.args.jumpiffalse;
              goto start;
            }
          } else if (cell.type == MA_CELL_NO) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          break;
        }
        case OP_E_JUMP_IF_TRUE: {
          const auto cell = M->stack.top();
          if (cell.type == MA_CELL_NUMBER) {
            if (cell.v.number != 0.0) {
              M->i = I.args.jumpiftrue;
              goto start;
            }
          } else if (cell.type != MA_CELL_NO) {
            M->i = I.args.jumpiftrue;
            goto start;
          }
          break;
        }
        case OP_E_JUMP_IF_FALSE: {
          const auto cell = M->stack.top();
          if (cell.type == MA_CELL_EMPTY) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          if (cell.type == MA_CELL_NUMBER && cell.v.number == 0.0) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          if (cell.type == MA_CELL_NO) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          break;
        }
        case OP_GET: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_OBJECT) {
            M->stack.push(ma_object_get(cell.v.object, I.args.get->name));
          } else {
            M->stack.push(MA_MAKE_EMPTY());
          }
          break;
        }
        case OP_GET1: {
          const auto cell = M->stack.top();
          if (cell.type == MA_CELL_OBJECT) {
            M->stack.push(ma_object_get(cell.v.object, I.args.get->name));
          } else {
            M->stack.push(MA_MAKE_EMPTY());
          }
          break;
        }
        case OP_SET: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto value = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_OBJECT) {
            ma_object_set(cell.v.object, I.args.set->name, value);
          }
          break;
        }
        case OP_TRY: {
          const auto frame = M->call_stack.top();
          M->call_stack.push(new MaCallFrame{
              .scope = frame->scope, .catch_index = I.args.try_->catch_index});
          break;
        }
        case OP_TRY_DONE: {
          M->call_stack.pop();
          M->i = I.args.trydone->index;
          break;
        }
        case OP_THROW: {
          while (!M->call_stack.empty()) {
            const auto frame = M->call_stack.top();
            M->call_stack.pop();
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
          M->stack.push(create_list());
          break;
        }
        case OP_LIST_APPEND: {
          const auto value = M->stack.top();
          M->stack.pop();
          const auto list_cell = M->stack.top();
          list_cell.v.object->d.list->append(value);
          break;
        }
        case OP_DICT: {
          M->stack.push(create_dict());
          break;
        }
        case OP_DICT_SET: {
          const auto value = M->stack.top();
          M->stack.pop();
          const auto dict_cell = M->stack.top();
          dict_cell.v.object->d.dict->set(create_string(I.args.dictset->key),
                                          value);
          break;
        }
        case OP_STRUCT: {
          const auto structure_cell = create_structure(I.args.struct_->name);
          M->stack.push(structure_cell);
          break;
        }
        case OP_STRUCT_PARAM: {
          const auto default_value_cell = M->stack.top();
          M->stack.pop();
          const auto structure_cell = M->stack.top();
          structure_cell.v.object->d.structure->params.push_back(
              MaDiiaParam{.name = I.args.diiaparam->name,
                          .default_value = default_value_cell});
          break;
        }
        case OP_STRUCT_METHOD: {
          const auto diia_cell = M->stack.top();
          M->stack.pop();
          const auto structure_cell = M->stack.top();
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
          const auto frame = M->call_stack.top();
          const auto module_cell = create_module(I.args.module->name);
          const auto module_scope = new MaScope(frame->scope);
          M->call_stack.push(new MaCallFrame{.scope = module_scope,
                                             .module = module_cell.v.object});
          frame->scope->set_variable(I.args.module->name, module_cell);
          break;
        }
        case OP_GIVE: {
          const auto frame = M->call_stack.top();
          const auto value = M->stack.top();
          M->stack.pop();
          if (frame->module) {
            frame->module->properties.insert_or_assign(I.args.give->name,
                                                       value);
            break;
          }
          DO_THROW_STRING("Неможливо дати \"" + I.args.give->name + "\".")
        }
        case OP_MODULE_DONE: {
          M->call_stack.pop();
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
              const auto frame = M->call_stack.top();
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
              const auto frame = M->call_stack.top();
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
              const auto frame = M->call_stack.top();
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
              const auto frame = M->call_stack.top();
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
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell.type == MA_CELL_NUMBER &&
              right_cell.type == MA_CELL_NUMBER) {
            M->stack.push(
                MA_MAKE_NUBMER(left_cell.v.number + right_cell.v.number));
            break;
          }
          if (left_cell.type == MA_CELL_OBJECT &&
              right_cell.type == MA_CELL_OBJECT) {
            if (left_cell.v.object->type == MA_OBJECT_STRING &&
                right_cell.v.object->type == MA_OBJECT_STRING) {
              M->stack.push(create_string(left_cell.v.object->d.string->data +
                                          right_cell.v.object->d.string->data));
              break;
            }
          }
          DO_THROW_STRING("Неможливо додати " + getcelltypename(left_cell) +
                          " до " + getcelltypename(right_cell))
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
