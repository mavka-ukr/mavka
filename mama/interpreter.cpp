#include "mama.h"

#define DO_THROW_STRING(v)           \
  M->stack.push(create_string((v))); \
  I = new MaInstruction(OP_THROW);   \
  goto i_start;

namespace mavka::mama {
  void run(MaMa* M, MaCode* C) {
    M->i = 0;
    const auto size = C->instructions.size();
    for (;;) {
    start:
      if (M->i >= size) {
        return;
      }
      MaInstruction* I = C->instructions[M->i];

    i_start:
      DEBUG_DO(print_instruction_with_index(M->i, I))

      switch (I->op) {
        case OP_PUSH_NUMBER: {
          M->stack.push(MA_MAKE_NUBMER(I->numval));
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
          if (left_cell.type == MA_CELL_NUMBER &&
              right_cell.type == MA_CELL_NUMBER) {
            M->stack.push(create_string(left_cell.v.object->string +
                                        right_cell.v.object->string));
            break;
          }
          DO_THROW_STRING("Неможливо додати " + getcelltypename(left_cell) +
                          " до " + getcelltypename(right_cell))
          break;
        }
        case OP_STORE: {
          const auto value = M->stack.top();
          M->stack.pop();

          const auto call_stack_value = M->call_stack.top();
          call_stack_value->scope->set_variable(I->strval, value);
          break;
        }
        case OP_LOAD: {
          const auto call_stack_value = M->call_stack.top();
          const auto scope = call_stack_value->scope;
          if (scope->has_variable(I->strval)) {
            M->stack.push(scope->get_variable(I->strval));
          } else {
            DO_THROW_STRING("Субʼєкт \"" + I->strval + "\" не визначено.")
          }
          break;
        }
        case OP_PUSH_STRING: {
          M->stack.push(create_string(I->strval));
          break;
        }
        case OP_JUMP_IF_FALSE: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_NUMBER) {
            if (cell.v.number == 0.0) {
              M->i = I->numval;
              goto start;
            }
          } else if (cell.type == MA_CELL_EMPTY) {
            M->i = I->numval;
            goto start;
          } else if (cell.v.object == M->no_cell.v.object) {
            M->i = I->numval;
            goto start;
          }
          break;
        }
        case OP_JUMP_IF_TRUE: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_NUMBER) {
            if (cell.v.number != 0.0) {
              M->i = I->numval;
              goto start;
            }
          } else if (cell.v.object == M->yes_cell.v.object) {
            M->i = I->numval;
            goto start;
          }
          break;
        }
        case OP_JUMP: {
          M->i = I->numval;
          goto start;
          break;
        }
        case OP_THROW: {
          while (!M->call_stack.empty()) {
            const auto call_stack_value = M->call_stack.top();
            M->call_stack.pop();
            if (call_stack_value->catch_index != 0) {
              M->i = call_stack_value->catch_index;
              goto start;
            }
          }
          std::cout << "Не вдалось зловити: " << cell_to_string(M->stack.top())
                    << std::endl;
          return;
          break;
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
        case OP_INITCALL: {
          const auto diia_cell = M->stack.top();
          M->stack.pop();
          const auto current_call_stack_value = M->call_stack.top();
          const auto diia_scope = new MaScope(current_call_stack_value->scope);
          const auto new_call_stack_value = new MaCallStackValue();
          new_call_stack_value->cell = diia_cell;
          new_call_stack_value->scope = diia_scope;
          new_call_stack_value->return_index = I->numval;
          new_call_stack_value->catch_index = 0;
          M->call_stack.push(new_call_stack_value);
          break;
        }
        case OP_CALL: {
          const auto call_stack_value = M->call_stack.top();
          const auto cell = call_stack_value->cell;
          const auto diia_scope = call_stack_value->scope;
          auto args = call_stack_value->args;

          DO_THROW_STRING("Неможливо викликати \"" + getcelltypename(cell) +
                          "\".")
          break;
        }
        case OP_RETURN: {
          auto call_stack_value = M->call_stack.top();
          M->call_stack.pop();
          while (call_stack_value->catch_index != 0) {
            call_stack_value = M->call_stack.top();
            M->call_stack.pop();
          }
          M->i = call_stack_value->return_index;
          DEBUG_LOG("returning to " + std::to_string(M->i))
          goto start;
          break;
        }
        case OP_POP: {
          M->stack.pop();
          break;
        }
        case OP_SET_ARG: {
          const auto value = M->stack.top();
          M->stack.pop();

          const auto current_call_stack_value = M->call_stack.top();

          current_call_stack_value->args.insert_or_assign(I->strval, value);
          break;
        }
        case OP_LIST: {
          M->stack.push(create_list());
          break;
        }
        case OP_LIST_APPEND: {
          const auto value = M->stack.top();
          M->stack.pop();
          const auto cell = M->stack.top();

          const auto list = cell.v.object->d.list;
          list->append(value);
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
        case OP_DIIA: {
          M->stack.push(create_diia(I->numval));
          break;
        }
        case OP_GET: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell.type == MA_CELL_OBJECT) {
            const auto object = cell.v.object;
            const auto value = ma_object_get(object, I->strval);
            M->stack.push(value);
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
            const auto object = cell.v.object;
            ma_object_set(object, I->strval, value);
          }
          break;
        }
        case OP_EACH_SIMPLE: {
          const auto to = M->stack.top();
          M->stack.pop();
          const auto from = M->stack.top();
          M->stack.pop();
          const auto call_stack_value = M->call_stack.top();

          for (long i = from.v.integer; i <= to.v.integer; ++i) {
            call_stack_value->scope->set_variable(I->strval,
                                                  MA_MAKE_INTEGER(i));
          }
          break;
        }
        case OP_DICT: {
          M->stack.push(create_dict());
          break;
        }
        case OP_DICT_SET: {
          const auto value = M->stack.top();
          M->stack.pop();
          const auto cell = M->stack.top();
          const auto dict = cell.v.object->d.dict;

          dict->set(I->strval, value);
          break;
        }
        case OP_STRUCT: {
          const auto structure_cell = create_structure();
          structure_cell.v.object->name = I->strval;
          M->stack.push(structure_cell);
          break;
        }
        case OP_STRUCT_PARAM: {
          const auto cell = M->stack.top();
          cell.v.object->params.push_back(I->strval);
          break;
        }
        case OP_DIIA_PARAM: {
          const auto cell = M->stack.top();
          cell.v.object->params.push_back(I->strval);
          break;
        }
        case OP_TRY: {
          const auto call_stack_value = M->call_stack.top();
          const auto new_call_stack_value = new MaCallStackValue();
          new_call_stack_value->cell = call_stack_value->cell;
          new_call_stack_value->scope = call_stack_value->scope;
          new_call_stack_value->return_index = call_stack_value->return_index;
          new_call_stack_value->catch_index = I->numval;
          M->call_stack.push(new_call_stack_value);
          break;
        }
        case OP_TRY_DONE: {
          const auto call_stack_value = M->call_stack.top();
          call_stack_value->catch_index = 0;
          break;
        }
        case OP_METHOD: {
          const auto structure_cell = M->stack.top();
          M->stack.pop();

          DO_THROW_STRING("Має бути структурою.")
          break;
        }
        case OP_METHOD_PARAM: {
          const auto cell = M->stack.top();
          cell.v.object->params.push_back(I->strval);
          break;
        }
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
          std::cout << "unsupported instruction " << getopname(I->op)
                    << std::endl;
          return;
        }
      }

      M->i++;
    }
  }
} // namespace mavka::mama
