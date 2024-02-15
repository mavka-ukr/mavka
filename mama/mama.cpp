#include "mama.h"

#define DO_THROW_STRING(v)              \
  M->stack.push(create_string(M, (v))); \
  M->ready_to_throw = true;             \
  goto i_start;

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
    if (M->diia_native_throw) {                                   \
      M->diia_native_throw = false;                               \
      M->ready_to_throw = true;                                   \
      goto i_start;                                               \
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
    if (M->diia_native_throw) {                                \
      M->diia_native_throw = false;                            \
      throw std::runtime_error("shit");                        \
      return;                                                  \
    }                                                          \
  } else {                                                     \
    (cell).v.object->properties[propname] = value;             \
  }

namespace mavka::mama {
  inline void restore_stack(MaMa* M, size_t stack_size) {
    while (M->stack.size() > stack_size) {
      M->stack.pop();
    }
  }

  void run(MaMa* M, size_t start_index) {
    M->i = start_index;
    auto size = M->code.size();
    for (;;) {
    start:
      if (M->i >= size) {
        return;
      }
      auto I = M->code[M->i];

    i_start:
      if (M->ready_to_throw) {
        M->ready_to_throw = false;
        std::vector<std::pair<size_t, size_t>> trace;
        while (!M->frames.empty()) {
          READ_TOP_FRAME();
          FRAME_POP();
          if (frame->type == FRAME_TYPE_CALL) {
            if (frame->data.call->line && frame->data.call->column) {
              trace.push_back(
                  {frame->data.call->line, frame->data.call->column});
            }
          } else if (frame->type == FRAME_TYPE_TRY) {
            M->i = frame->data.try_->catch_index;
            goto start;
          }
        }
        std::cout << "Не вдалось зловити: " << cell_to_string(M->stack.top())
                  << std::endl;
        for (const auto& [line, column] : trace) {
          std::cout << "  " << line << ":" << column << std::endl;
        }
        return;
      }

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
          if (initcall(M, I.args.initcall->args_type, cell,
                       {.return_index = I.args.initcall->return_index,
                        .line = I.args.initcall->line,
                        .column = I.args.initcall->column})) {
            break;
          }
          DO_THROW_CANNOT_CALL_CELL(cell);
        }
        case OP_PUSH_ARG: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          FRAME_PUSH_ARG(frame, value);
          break;
        }
        case OP_STORE_ARG: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          FRAME_SET_ARG(frame, I.args.store->name, value);
          break;
        }
        case OP_CALL: {
        repeat_op_call:
          READ_TOP_FRAME();
          const auto call_data = frame->data.call;
          if (call_data->type == FRAME_CALL_TYPE_DIIA) {
            const auto diia = call_data->o.diia;
            if (diia->d.diia->me) {
              frame->scope->set_variable("я", MA_MAKE_OBJECT(diia->d.diia->me));
            }
            for (int i = 0; i < diia->d.diia->params.size(); ++i) {
              const auto& param = diia->d.diia->params[i];
              const auto arg_value = FRAME_GET_ARG(
                  call_data->args, i, param.name, param.default_value);
              frame->scope->set_variable(param.name, arg_value);
            }
            M->i = diia->d.diia->index;
            goto start;
          }
          if (call_data->type == FRAME_CALL_TYPE_DIIA_NATIVE) {
            const auto diia_native = call_data->o.diia_native;
            diia_native->d.diia_native->fn(M, diia_native->d.diia_native->me,
                                           call_data->args);
          check_diia_native_result:
            if (M->diia_native_throw) {
              M->diia_native_throw = false;
              throw std::runtime_error("shit");
              return;
            }
            FRAME_POP();
            const auto result = M->stack.top();
            restore_stack(M, call_data->restore_stack_size);
            PUSH(result);
            if (M->diia_native_callback) {
              const auto diia_native_callback = M->diia_native_callback;
              M->diia_native_callback = nullptr;
              diia_native_callback(M);
              if (M->diia_native_repeat) {
                goto repeat_op_call;
              } else {
                goto check_diia_native_result;
              }
            }
            break;
          }
          if (call_data->type == FRAME_CALL_TYPE_STRUCTURE) {
            const auto structure = call_data->o.structure;
            const auto object_cell =
                create_object(M, MA_OBJECT, structure, nullptr);
            for (int i = 0; i < structure->d.structure->params.size(); ++i) {
              const auto& param = structure->d.structure->params[i];
              const auto arg_value = FRAME_GET_ARG(
                  call_data->args, i, param.name, param.default_value);
              ma_object_set(object_cell.v.object, param.name, arg_value);
            }
            PUSH(object_cell);
            FRAME_POP();
            break;
          }
          DO_THROW_STRING("Неможливо викликати.")
        }
        case OP_RETURN: {
          auto frame = M->frames.top();
          FRAME_POP();
          while (frame->type != FRAME_TYPE_CALL) {
            frame = M->frames.top();
            FRAME_POP();
          }
          const auto result = M->stack.top();
          restore_stack(M, frame->data.call->restore_stack_size);
          PUSH(result);
          DEBUG_LOG("returning to " + std::to_string(M->i));
          M->i = frame->data.call->return_index;
          goto start;
        }
        case OP_DIIA: {
          READ_TOP_FRAME();
          const auto diia_cell =
              create_diia(M, I.args.diia->name, I.args.diia->index, nullptr);
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
          if (IS_OBJECT(cell)) {
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
          const auto cf_data =
              new MaFrameTryData{.catch_index = I.args.try_->catch_index};
          FRAME_PUSH(MaFrame::try_(frame->scope, cf_data));
          break;
        }
        case OP_TRY_DONE: {
          FRAME_POP();
          M->i = I.args.trydone->index;
          break;
        }
        case OP_THROW: {
          M->ready_to_throw = true;
          goto i_start;
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
          if (IS_OBJECT(structure_cell)) {
            if (IS_OBJECT_STRUCTURE(structure_cell)) {
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
          const auto cf_data =
              new MaFrameModuleData{.module = module_cell.v.object,
                                    .restore_stack_size = M->stack.size()};
          FRAME_PUSH(MaFrame::module(module_scope, cf_data));
          frame->scope->set_variable(I.args.module->name, module_cell);
          break;
        }
        case OP_GIVE: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          if (frame->type == FRAME_TYPE_MODULE) {
            frame->data.module->module->properties.insert_or_assign(
                I.args.give->name, value);
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
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
            if (!initcall(M, MA_ARGS_POSITIONED, diia_cell,
                          {.return_index = M->i + 1})) {
              DO_THROW_CANNOT_CALL_CELL(diia_cell);
            }
            READ_TOP_FRAME();
            FRAME_PUSH_ARG(frame, right);
            I = MaInstruction::call();
            goto i_start;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_RIGHT, left);
          }
          break;
        }
        case OP_TAKE: {
          const auto rawpath = I.args.take->path;
          if (!std::filesystem::exists(rawpath)) {
            DO_THROW_STRING("Не вдалося прочитати файл \"" + rawpath + "\".");
            return;
          }
          const auto path =
              std::filesystem::canonical(I.args.take->path).string();
          const auto stdpath = std::filesystem::path(path);
          if (!stdpath.has_filename()) {
            DO_THROW_STRING("Не вдалося прочитати файл \"" + path + "\".");
            return;
          }
          const auto name = stdpath.stem().string();

          if (M->loaded_file_modules.contains(name)) {
            PUSH(MA_MAKE_OBJECT(M->loaded_file_modules[name]));
            break;
          } else {
            auto file = std::ifstream(path);
            if (!file.is_open()) {
              DO_THROW_STRING("Не вдалося прочитати файл \"" + path + "\".");
              return;
            }
            const auto source = std::string(std::istreambuf_iterator(file),
                                            std::istreambuf_iterator<char>());
            const auto parser_result = parser::parse(source, path);
            if (!parser_result.errors.empty()) {
              const auto error = parser_result.errors[0];
              DO_THROW_STRING(error.path + ":" + std::to_string(error.line) +
                              ":" + std::to_string(error.column) + ": " +
                              error.message);
              return;
            }
            M->code.push_back({OP_JUMP});
            const auto jump_out_of_module_index = M->code.size() - 1;
            const auto module_code_index = M->code.size();
            M->code.push_back(
                MaInstruction::module(new MaModuleInstructionArgs(name)));
            M->code.push_back(MaInstruction::keepmodule());
            const auto body_compilation_result =
                compile_body(M, parser_result.program_node->body);
            if (body_compilation_result.error) {
              DO_THROW_STRING(
                  path + ":" +
                  std::to_string(body_compilation_result.error->line) + ":" +
                  std::to_string(body_compilation_result.error->column) + ": " +
                  body_compilation_result.error->message);
              return;
            }
            M->code.push_back(MaInstruction::loadmodule());
            M->code.push_back(MaInstruction::moduledone());
            if (I.args.take->jump_to) {
              M->code.push_back(MaInstruction::jump(I.args.take->jump_to));
            }
            M->code[jump_out_of_module_index].args.jump = M->code.size();
            size = M->code.size();
            M->i = module_code_index;
            goto start;
          }
          break;
        }
        case OP_KEEP_MODULE: {
          READ_TOP_FRAME();
          const auto current_module_path =
              frame->data.module->module->d.module->name;
          M->loaded_file_modules.insert_or_assign(current_module_path,
                                                  frame->data.module->module);
          break;
        }
        case OP_LOAD_MODULE: {
          READ_TOP_FRAME();
          PUSH(MA_MAKE_OBJECT(frame->data.module->module));
          break;
        }
        case OP_MODULE_LOAD: {
          TOP_VALUE(module_cell);
          OBJECT_GET(module_cell, value, I.args.moduleload->name);
          READ_TOP_FRAME();
          frame->scope->set_variable(I.args.moduleload->as, value);
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

  bool initcall(MaMa* M,
                MaArgsType args_type,
                MaCell cell,
                MaInitcallOptions options) {
    READ_TOP_FRAME();

    const auto args = new MaArgs(args_type);

  repeat:
    if (IS_OBJECT(cell)) {
      const auto object = cell.v.object;

      if (IS_OBJECT_DIIA(cell)) {
        const auto cf_data = new MaCallFrameCallData({
            .type = FRAME_CALL_TYPE_DIIA,
            .o =
                {
                    .diia = object,
                },
            .return_index = options.return_index,
            .args = args,
            .line = options.line,
            .column = options.column,
            .restore_stack_size = M->stack.size(),
        });
        const auto scope = new MaScope(object->d.diia->scope);
        FRAME_PUSH(MaFrame::call(scope, cf_data));
        return true;
      }
      if (IS_OBJECT_DIIA_NATIVE(cell)) {
        const auto cf_data = new MaCallFrameCallData({
            .type = FRAME_CALL_TYPE_DIIA_NATIVE,
            .o =
                {
                    .diia_native = object,
                },
            .return_index = options.return_index,
            .args = args,
            .line = options.line,
            .column = options.column,
            .restore_stack_size = M->stack.size(),
        });
        FRAME_PUSH(MaFrame::call(frame->scope, cf_data));
        return true;
      }
      if (object->properties.contains(MAG_CALL)) {
        cell = object->properties[MAG_CALL];
        goto repeat;
      }
      if (IS_OBJECT_STRUCTURE(cell)) {
        const auto cf_data = new MaCallFrameCallData({
            .type = FRAME_CALL_TYPE_STRUCTURE,
            .o =
                {
                    .structure = object,
                },
            .return_index = options.return_index,
            .args = args,
            .line = options.line,
            .column = options.column,
            .restore_stack_size = M->stack.size(),
        });
        FRAME_PUSH(MaFrame::call(frame->scope, cf_data));
        return true;
      }
    }

    return false;
  }
} // namespace mavka::mama
