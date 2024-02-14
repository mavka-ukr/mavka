#include "mama.h"

#define DO_THROW_STRING(v)              \
  M->stack.push(create_string(M, (v))); \
  I = MaInstruction{OP_THROW};          \
  goto i_start;

#define HANDLE_THROW()                                                  \
  std::vector<std::pair<size_t, size_t>> trace;                         \
  while (!M->call_stack.empty()) {                                      \
    READ_TOP_FRAME();                                                   \
    FRAME_POP();                                                        \
    if (frame->line && frame->column) {                                 \
      trace.push_back({frame->line, frame->column});                    \
    }                                                                   \
    const auto catch_index = frame->catch_index;                        \
    if (catch_index) {                                                  \
      trace.clear();                                                    \
      M->i = catch_index;                                               \
      goto start;                                                       \
    }                                                                   \
  }                                                                     \
  std::cout << "Не вдалось зловити: " << cell_to_string(M->stack.top()) \
            << std::endl;                                               \
  for (const auto& [line, column] : trace) {                            \
    std::cout << "  " << line << ":" << column << std::endl;            \
  }

#define DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(varname, cell)                 \
  DO_THROW_STRING("Дію \"" + std::string(varname) +                       \
                  "\" не визначено для типу \"" + getcelltypename(cell) + \
                  "\".")

#define DO_THROW_PROP_NOT_DEFINED_FOR_TYPE(varname, cell)                 \
  DO_THROW_STRING("Властивість \"" + std::string(varname) +               \
                  "\" не визначено для типу \"" + getcelltypename(cell) + \
                  "\".")

#define DO_THROW_CANNOT_CALL_CELL(cell) \
  DO_THROW_STRING("Неможливо викликати \"" + getcelltypename(cell) + "\".")

#define OBJECT_GET(cell, varname, propname)                       \
  MaCell varname{};                                               \
  if ((cell).v.object->get) {                                     \
    varname = (cell).v.object->get(M, (cell).v.object, propname); \
    if (M->need_to_throw) {                                       \
      M->need_to_throw = false;                                   \
      HANDLE_THROW();                                             \
      return;                                                     \
    }                                                             \
  } else {                                                        \
    if ((cell).v.object->properties.contains(propname)) {         \
      varname = (cell).v.object->properties[propname];            \
    } else {                                                      \
      DO_THROW_PROP_NOT_DEFINED_FOR_TYPE(propname, cell)          \
    }                                                             \
  }

#define OBJECT_SET(cell, propname, value)                      \
  if ((cell).v.object->set) {                                  \
    (cell).v.object->set(M, (cell).v.object, propname, value); \
    if (M->need_to_throw) {                                    \
      M->need_to_throw = false;                                \
      HANDLE_THROW();                                          \
      return;                                                  \
    }                                                          \
  } else {                                                     \
    (cell).v.object->properties[propname] = value;             \
  }

namespace mavka::mama {
  void print_stack(std::stack<MaCell> stack) {
    std::cout << "--- STACK ---" << std::endl;
    while (!stack.empty()) {
      std::cout << cell_to_string(stack.top()) << std::endl;
      stack.pop();
    }
    std::cout << "--- END STACK ---" << std::endl;
  }

  void run(MaMa* M, MaCode* code) {
    M->i = 0;
    const auto size = code->instructions.size();
    for (;;) {
    start:
      if (M->i >= size) {
        return;
      }
      auto I = code->instructions[M->i];

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
          if (initcall(M, cell, I.args.initcall->index, nullptr)) {
            READ_TOP_FRAME();
            frame->line = I.args.initcall->line;
            frame->column = I.args.initcall->column;
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
            frame->diia_native->d.diia_native->fn(
                M, frame->diia_native->d.diia_native->me, frame->args);
            if (M->need_to_throw) {
              M->need_to_throw = false;
              HANDLE_THROW();
              return;
            }
            FRAME_POP();
            if (M->diia_native_redirect) {
              const auto diia_native_redirect = M->diia_native_redirect;
              M->diia_native_redirect = nullptr;
              const auto diia_native_redirect_result =
                  diia_native_redirect(M, I);
              if (M->need_to_throw) {
                M->need_to_throw = false;
                HANDLE_THROW();
                return;
              }
              if (diia_native_redirect_result) {
                goto i_start;
              }
            }
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
            run(M, frame->diia->d.diia->code);
            goto start;
          }
          if (frame->structure) {
            const auto object_cell =
                create_object(M, MA_OBJECT, frame->structure, nullptr);
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
          if (frame->return_callback) {
            frame->return_callback(M);
            break;
          }
          DEBUG_LOG("returning to " + std::to_string(M->i));
          M->i = frame->return_index;
          goto start;
        }
        case OP_DIIA: {
          READ_TOP_FRAME();
          const auto diia_cell =
              create_diia(M, I.args.diia->name,
                          M->diia_bodies[I.args.diia->code_index], nullptr);
          diia_cell.v.object->d.diia->scope = frame->scope;
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
            OBJECT_GET(cell, value, I.args.get->name);
            PUSH(value);
            break;
          }
          DO_THROW_PROP_NOT_DEFINED_FOR_TYPE(I.args.get->name, cell);
          break;
        }
        case OP_SET: {
          POP_VALUE(cell);
          POP_VALUE(value);
          if (IS_OBJECT(cell)) {
            if (IS_OBJECT_STRING(cell)) {
              break;
            }
            OBJECT_SET(cell, I.args.set->name, value);
            break;
          }
          break;
        }
        case OP_E_SETR: {
          POP_VALUE(value);
          TOP_VALUE(cell);
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
          HANDLE_THROW();
          return;
        }
        case OP_LIST: {
          PUSH(create_list(M));
          break;
        }
        case OP_LIST_APPEND: {
          POP_VALUE(value);
          TOP_VALUE(list_cell);
          list_cell.v.object->d.list->append(value);
          break;
        }
        case OP_DICT: {
          PUSH(create_dict(M));
          break;
        }
        case OP_DICT_SET: {
          POP_VALUE(value);
          TOP_VALUE(dict_cell);
          dict_cell.v.object->d.dict->set(create_string(M, I.args.dictset->key),
                                          value);
          break;
        }
        case OP_STRUCT: {
          const auto structure_cell = create_structure(M, I.args.struct_->name);
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
          const auto module_cell = create_module(M, I.args.module->name);
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
            OBJECT_GET(left, diia_cell, MAG_GREATER);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_GREATER_EQUAL);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_LESSER);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_LESSER_EQUAL);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER_EQUAL, left);
          }
          break;
        }
        case OP_CONTAINS: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_CONTAINS);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_CONTAINS, left);
          }
          break;
        }
        case OP_IS: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_EMPTY(left)) {
            if (IS_EMPTY(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          if (IS_NUMBER(left)) {
            if (right.v.object == M->number_structure_object) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          if (IS_YES(left) || IS_NO(left)) {
            if (right.v.object == M->logical_structure_object) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          if (IS_OBJECT(right) && IS_OBJECT(left)) {
            if (right.v.object == left.v.object->structure) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          PUSH_NO();
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
            OBJECT_GET(value, diia_cell, MAG_NEGATIVE);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(value, diia_cell, MAG_POSITIVE);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(value, diia_cell, MAG_BW_NOT);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_ADD);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_SUB);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_MUL);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_DIV);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_MOD);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_DIVDIV);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_POW);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_BW_XOR);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_BW_OR);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_BW_AND);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_BW_SHIFT_LEFT);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
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
            OBJECT_GET(left, diia_cell, MAG_BW_SHIFT_RIGHT);
            if (!initcall(M, diia_cell, M->i + 1, nullptr)) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            frame->args.insert_or_assign("0", right);
            I = MaInstruction{OP_CALL};
            goto i_start;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_RIGHT, left);
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
