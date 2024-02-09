#include "mama.h"

#define DO_THROW_STRING(v)           \
  M->stack.push(create_string((v))); \
  I = MaInstruction{OP_THROW};       \
  goto i_start;

namespace mavka::mama {
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
          M->stack.push(*I.args.constant);
          break;
        }
        case OP_INITCALL: {
          const auto cell = M->stack.top();
          M->stack.pop();

          const auto frame = M->call_stack.top();

          if (cell.type == MA_CELL_OBJECT) {
            const auto object = cell.v.object;

            if (object->type == MA_OBJECT_DIIA_NATIVE) {
              M->call_stack.push(
                  new MaCallFrame{.scope = frame->scope,
                                  .diia_native = object,
                                  .return_index = I.args.initcall->index});
              break;
            }
            if (object->type == MA_OBJECT_DIIA) {
              M->call_stack.push(
                  new MaCallFrame{.scope = frame->scope,
                                  .diia = object,
                                  .return_index = I.args.initcall->index});
              break;
            }
            if (object->type == MA_OBJECT_STRUCTURE) {
              M->call_stack.push(
                  new MaCallFrame{.scope = frame->scope,
                                  .structure = object,
                                  .return_index = I.args.initcall->index});
              break;
            }
          }
          DO_THROW_STRING("Неможливо викликати \"" + getcelltypename(cell) +
                          "\".")
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
            const auto result =
                frame->diia_native->d.diia_native->fn(M, frame->scope);
            M->stack.push(result);
            frame->args.clear();
            M->call_stack.pop();
            break;
          }
          if (frame->diia) {
            frame->scope = new MaScope(frame->diia->d.diia->scope);
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
          if (cell.type == MA_CELL_OBJECT &&
              cell.v.object != M->no_cell.v.object) {
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
          }
          if (cell.type == MA_CELL_NUMBER && cell.v.number == 0.0) {
            M->i = I.args.jumpiffalse;
            goto start;
          }
          if (cell.type == MA_CELL_OBJECT &&
              cell.v.object == M->no_cell.v.object) {
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
          const auto structure_cell = create_structure();
          ma_object_set(structure_cell.v.object, "назва",
                        create_string(I.args.struct_->name));
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
        case OP_EQ: {
          const auto right = M->stack.top();
          M->stack.pop();
          const auto left = M->stack.top();
          M->stack.pop();

          if (left.type == MA_CELL_NUMBER && right.type == MA_CELL_NUMBER) {
            if (left.v.number == right.v.number) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            if (left.v.object == right.v.object) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          }
          break;
        }
        case OP_GET_ELEMENT: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto key = M->stack.top();
          M->stack.pop();

          M->stack.push(MA_MAKE_EMPTY());
          break;
        }
        case OP_SET_ELEMENT: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto value = M->stack.top();
          M->stack.pop();
          const auto key = M->stack.top();
          M->stack.pop();

          //

          break;
        }
        // case OP_EACH_SIMPLE: {
        //   const auto to = M->stack.top();
        //   M->stack.pop();
        //   const auto from = M->stack.top();
        //   M->stack.pop();
        //   const auto call_stack_value = M->call_stack.top();
        //
        //   for (long i = from.v.integer; i <= to.v.integer; ++i) {
        //     call_stack_value->scope->set_variable(I->strval,
        //                                           MA_MAKE_INTEGER(i));
        //   }
        //   break;
        // }
        // case OP_STRUCT_PARAM: {
        //   const auto cell = M->stack.top();
        //   cell.v.object->d.structure->params.push_back(I->strval);
        //   break;
        // }
        // case OP_DIIA_PARAM: {
        //   const auto cell = M->stack.top();
        //   cell.v.object->d.structure->params.push_back(I->strval);
        //   break;
        // }
        case OP_METHOD: {
          const auto structure_cell = M->stack.top();
          M->stack.pop();

          DO_THROW_STRING("Має бути структурою.")
          break;
        }
        // case OP_METHOD_PARAM: {
        //   const auto cell = M->stack.top();
        //   cell.v.object->d.structure->params.push_back(I->strval);
        //   break;
        // }
        case OP_NOT: {
          const auto value = M->stack.top();
          M->stack.pop();
          if (value.type == MA_CELL_NUMBER) {
            if (value.v.number == 0.0) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else if (value.type == MA_CELL_EMPTY) {
            M->stack.push(M->yes_cell);
          } else if (value.v.object == M->no_cell.v.object) {
            M->stack.push(M->yes_cell);
          } else if (value.v.object == M->yes_cell.v.object) {
            M->stack.push(M->no_cell);
          } else {
            M->stack.push(M->no_cell);
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
