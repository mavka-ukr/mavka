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
          M->stack.push(create_number(I->numval));
          break;
        }
        case OP_ADD: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(
                create_number(left_cell->number() + right_cell->number()));
            break;
          }
          if (left_cell->type == MA_STRING && right_cell->type == MA_STRING) {
            M->stack.push(
                create_string(left_cell->string() + right_cell->string()));
            break;
          }
          DO_THROW_STRING("Неможливо додати " + getcelltypename(left_cell) +
                          " до " + getcelltypename(right_cell))
          break;
        }
        case OP_SUB: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(
                create_number(left_cell->number() - right_cell->number()));
            break;
          }
          DO_THROW_STRING("Неможливо відняти " + getcelltypename(right_cell) +
                          " від " + getcelltypename(left_cell))
          break;
        }
        case OP_MUL: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(
                create_number(left_cell->number() * right_cell->number()));
            break;
          }
          DO_THROW_STRING("Неможливо помножити " + getcelltypename(left_cell) +
                          " на " + getcelltypename(right_cell))
          break;
        }
        case OP_DIV: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(
                create_number(left_cell->number() / right_cell->number()));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_MOD: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(
                std::fmod(left_cell->number(), right_cell->number())));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_DIVDIV: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(
                std::floor(left_cell->number() / right_cell->number())));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_POW: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(
                std::pow(left_cell->number(), right_cell->number())));
            break;
          }
          M->stack.push(M->empty_cell);
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
          const auto value = call_stack_value->scope->get_variable(I->strval);
          if (value != nullptr) {
            M->stack.push(value);
          } else {
            DO_THROW_STRING("Субʼєкт \"" + I->strval + "\" не визначено.")
          }
          break;
        }
        case OP_PUSH_STRING: {
          M->stack.push(create_string(I->strval));
          break;
        }
        case OP_XOR: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(left_cell->number_long() ^
                                        right_cell->number_long()));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_BAND: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(left_cell->number_long() &
                                        right_cell->number_long()));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_BOR: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(left_cell->number_long() |
                                        right_cell->number_long()));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_SHL: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(left_cell->number_long()
                                        << right_cell->number_long()));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_SHR: {
          const auto right_cell = M->stack.top();
          M->stack.pop();
          const auto left_cell = M->stack.top();
          M->stack.pop();

          if (left_cell->type == MA_NUMBER && right_cell->type == MA_NUMBER) {
            M->stack.push(create_number(left_cell->number_long() >>
                                        right_cell->number_long()));
            break;
          }
          M->stack.push(M->empty_cell);
          break;
        }
        case OP_JUMP_IF_FALSE: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell->type == MA_NUMBER) {
            if (cell->number() == 0) {
              M->i = I->numval;
              goto start;
            }
          } else if (cell->type == MA_NO) {
            M->i = I->numval;
            goto start;
          }
          break;
        }
        case OP_JUMP_IF_TRUE: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell->type == MA_NUMBER) {
            if (cell->number() != 0) {
              M->i = I->numval;
              goto start;
            }
          } else if (cell->type == MA_YES) {
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

          if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
            if (left->number() == right->number()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else if (left->type == MA_STRING && right->type == MA_STRING) {
            if (left->string() == right->string()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            if (left == right) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          }
          break;
        }
        case OP_NE: {
          const auto right = M->stack.top();
          M->stack.pop();
          const auto left = M->stack.top();
          M->stack.pop();

          if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
            if (left->number() != right->number()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else if (left->type == MA_STRING && right->type == MA_STRING) {
            if (left->string() != right->string()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            if (left != right) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          }
          break;
        }
        case OP_LT: {
          const auto right = M->stack.top();
          M->stack.pop();
          const auto left = M->stack.top();
          M->stack.pop();

          if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
            if (left->number() < right->number()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            M->stack.push(M->no_cell);
          }
          break;
        }
        case OP_LE: {
          const auto right = M->stack.top();
          M->stack.pop();
          const auto left = M->stack.top();
          M->stack.pop();

          if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
            if (left->number() <= right->number()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            M->stack.push(M->no_cell);
          }
          break;
        }
        case OP_GT: {
          const auto right = M->stack.top();
          M->stack.pop();
          const auto left = M->stack.top();
          M->stack.pop();

          if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
            if (left->number() > right->number()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            M->stack.push(M->no_cell);
          }
          break;
        }
        case OP_GE: {
          const auto right = M->stack.top();
          M->stack.pop();
          const auto left = M->stack.top();
          M->stack.pop();

          if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
            if (left->number() >= right->number()) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else {
            M->stack.push(M->no_cell);
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

          if (cell->type == MA_DIIA_NATIVE) {
            const auto diia_native = cell->cast_diia_native();
            const auto result = diia_native->value(nullptr, M, diia_scope);
            M->stack.push(result);
            M->call_stack.pop();
          } else if (cell->type == MA_DIIA) {
            const auto diia = cell->cast_diia();
            if (diia->me) {
              diia_scope->set_variable("я", diia->me);
            }
            long i = 0;
            for (const auto& name : diia->params) {
              if (args.contains(name)) {
                diia_scope->set_variable(name, args[name]);
              } else if (args.contains(std::to_string(i))) {
                diia_scope->set_variable(name, args[std::to_string(i)]);
              }
              ++i;
            }
            M->i = cell->cast_diia()->index;
            goto start;
          } else if (cell->type == MA_STRUCTURE) {
            if (M->number_structure_cell == cell) {
              const auto arg = args["0"];
              if (arg->type == MA_STRING) {
                M->call_stack.pop();
                M->stack.push(create_number(std::stod(arg->string())));
              } else if (arg->type == MA_NUMBER) {
                M->call_stack.pop();
                M->stack.push(arg);
              } else {
                DO_THROW_STRING("Неможливо перетворити на число \"" +
                                getcelltypename(arg) + "\".")
              }
            } else if (M->text_structure_cell == cell) {
              const auto arg = args["0"];
              if (arg->type == MA_STRING) {
                M->call_stack.pop();
                M->stack.push(arg);
              } else if (arg->type == MA_NUMBER) {
                M->call_stack.pop();
                std::string str = std::to_string(arg->number());
                M->stack.push(create_string(str));
              } else {
                DO_THROW_STRING("Неможливо петворити на текст \"" +
                                getcelltypename(arg) + "\".")
              }
            } else {
              const auto structure = cell->cast_structure();
              const auto object_cell = create_object(cell);
              const auto object = object_cell->cast_object();
              int i = 0;
              for (const auto& param : structure->params) {
                if (args.contains(param)) {
                  object->set(param, args[param]);
                } else if (args.contains(std::to_string(i))) {
                  object->set(param, args[std::to_string(i)]);
                }
                ++i;
              }
              M->call_stack.pop();
              M->stack.push(object_cell);
            }
          } else {
            DO_THROW_STRING("Неможливо викликати \"" + getcelltypename(cell) +
                            "\".")
          }
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

          const auto list = cell->cast_list();
          list->append(value);
          break;
        }
        case OP_GET_ELEMENT: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto key = M->stack.top();
          M->stack.pop();

          if (cell->type == MA_LIST) {
            const auto list = cell->cast_list();
            if (key->type == MA_NUMBER) {
              const auto index = key->number_long();
              if (index >= 0 && index < list->size()) {
                M->stack.push(list->get(index));
              } else {
                M->stack.push(M->empty_cell);
              }
            } else {
              M->stack.push(M->empty_cell);
            }
          } else if (cell->type == MA_DICT) {
            const auto value = cell->cast_dict()->get(key);
            if (value) {
              M->stack.push(value);
            } else {
              M->stack.push(M->empty_cell);
            }
          } else if (cell->type == MA_STRING) {
            if (key->type == MA_NUMBER) {
              const auto index = key->number_long();
              const auto str = cell->string();
              if (index >= 0 && index < str.length()) {
                const auto substr = str.substr(index, 1);
                M->stack.push(create_string(substr));
              } else {
                M->stack.push(M->empty_cell);
              }
            } else {
              M->stack.push(M->empty_cell);
            }
          } else {
            M->stack.push(M->empty_cell);
          }
          break;
        }
        case OP_SET_ELEMENT: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto value = M->stack.top();
          M->stack.pop();
          const auto key = M->stack.top();
          M->stack.pop();

          if (cell->type == MA_LIST) {
            const auto list = cell->cast_list();
            if (key->type == MA_NUMBER) {
              const auto index = key->number_long();
              list->set(index, value);
            }
          } else if (cell->type == MA_DICT) {
            const auto dict = cell->cast_dict();
            dict->set(key, value);
          }
          break;
        }
        case OP_NEGATIVE: {
          const auto value = M->stack.top();
          M->stack.pop();

          if (value->type == MA_NUMBER) {
            M->stack.push(create_number(-value->number()));
          } else {
            M->stack.push(M->empty_cell);
          }
          break;
        }
        case OP_POSITIVE: {
          const auto value = M->stack.top();
          M->stack.pop();

          if (value->type == MA_NUMBER) {
            M->stack.push(create_number(+value->number()));
          } else {
            M->stack.push(M->empty_cell);
          }
          break;
        }
        case OP_DIIA: {
          M->stack.push(create_diia(I->numval));
          break;
        }
        case OP_GET: {
          const auto cell = M->stack.top();
          M->stack.pop();
          if (cell->type == MA_OBJECT) {
            const auto object = cell->cast_object();
            const auto value = object->get(I->strval);
            if (value != nullptr) {
              M->stack.push(value);
            } else {
              M->stack.push(M->empty_cell);
            }
          } else if (cell->type == MA_LIST) {
            if (I->strval == "довжина") {
              const auto length = cell->cast_list()->size();
              M->stack.push(create_number(length));
            } else if (I->strval == "додати") {
              auto diia_native_fn = [&cell](MaCell* self, MaMa* M, MaScope* S) {
                const auto current_call_stack_value = M->call_stack.top();
                const auto value = current_call_stack_value->args["0"];
                cell->cast_list()->append(value);
                return M->empty_cell;
              };
              const auto diia_native = new MaDiiaNative();
              diia_native->value = diia_native_fn;
              const auto diia_native_cell =
                  new MaCell(MA_DIIA_NATIVE, diia_native);
              M->stack.push(diia_native_cell);
            } else {
              M->stack.push(M->empty_cell);
            }
          } else if (cell->type == MA_STRING) {
            if (I->strval == "довжина") {
              const auto length = cell->cast_string()->value.length();
              M->stack.push(create_number(length));
            } else {
              M->stack.push(M->empty_cell);
            }
          } else {
            M->stack.push(M->empty_cell);
          }
          break;
        }
        case OP_SET: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto value = M->stack.top();
          M->stack.pop();

          if (cell->type == MA_OBJECT) {
            const auto object = cell->cast_object();
            object->set(I->strval, value);
          }
          break;
        }
        case OP_EACH_SIMPLE: {
          const auto to = M->stack.top();
          M->stack.pop();
          const auto from = M->stack.top();
          M->stack.pop();
          const auto call_stack_value = M->call_stack.top();

          for (long i = from->number_long(); i <= to->number_long(); ++i) {
            call_stack_value->scope->set_variable(I->strval, create_number(i));
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
          const auto dict = cell->cast_dict();

          dict->set(I->strval, value);
          break;
        }
        case OP_STRUCT: {
          const auto structure_cell = create_structure();
          structure_cell->cast_structure()->name = I->strval;
          M->stack.push(structure_cell);
          break;
        }
        case OP_STRUCT_PARAM: {
          const auto cell = M->stack.top();
          cell->cast_structure()->params.push_back(I->strval);
          break;
        }
        case OP_DIIA_PARAM: {
          const auto cell = M->stack.top();
          cell->cast_diia()->params.push_back(I->strval);
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
          if (structure_cell->type == MA_STRUCTURE) {
            const auto structure = structure_cell->cast_structure();
            const auto method = new MaMethod();
            method->index = I->numval;
            structure->methods.insert_or_assign(I->strval, method);
            M->stack.push(new MaCell(MA_METHOD, method));
          } else {
            DO_THROW_STRING("Має бути структурою.")
          }
          break;
        }
        case OP_METHOD_PARAM: {
          const auto cell = M->stack.top();
          cell->cast_method()->params.push_back(I->strval);
          break;
        }
        case OP_NOT: {
          const auto value = M->stack.top();
          M->stack.pop();
          if (value->type == MA_NUMBER) {
            if (value->number() == 0) {
              M->stack.push(M->yes_cell);
            } else {
              M->stack.push(M->no_cell);
            }
          } else if (value->type == MA_NO) {
            M->stack.push(M->yes_cell);
          } else if (value->type == MA_YES) {
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
