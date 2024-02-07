#include "mama.h"

namespace mavka::mama {
  void run(MaMa* M, MaScope* S, MaCode* C) {
    M->i = 0;
    const auto size = C->instructions.size();
    for (;;) {
    start:
      if (M->i >= size) {
        return;
      }
      if (M->do_throw) {
        const auto value = M->stack.top();
        M->stack.pop();
        print_cell(value);
        return;
      }
    i_start:
      const auto I = C->instructions[M->i];

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
          M->stack.push(M->empty_cell);
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
          M->stack.push(M->empty_cell);
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
          M->stack.push(M->empty_cell);
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
            M->stack.push(M->empty_cell);
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
          M->do_throw = true;
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
        case OP_CALL: {
          const auto cell = M->stack.top();
          M->stack.pop();
          const auto call_stack_value = M->call_stack.top();
          const auto diia_scope = new MaScope(call_stack_value->scope);
          const auto return_index = M->i + 1;
          M->call_stack.push(
              new MaCallStackValue(cell, diia_scope, return_index));
          if (cell->type == MA_DIIA_NATIVE) {
            const auto diia_native = cell->cast_diia_native();
            diia_native->value(cell, M, diia_scope);
            M->call_stack.pop();
          } else if (cell->type == MA_DIIA) {
            const auto diia = cell->cast_diia();
            int i = 0;
            for (const auto& param : diia->params) {
              if (M->aR.contains(param.first)) {
                diia_scope->set_variable(param.first, M->aR[param.first]);
              } else if (M->aR.contains(std::to_string(i))) {
                diia_scope->set_variable(param.first, M->aR[std::to_string(i)]);
              }
              ++i;
            }
            M->aR.clear();
            M->i = cell->cast_diia()->index;
            goto start;
          } else if (cell->type == MA_STRUCTURE) {
            const auto structure = cell->cast_structure();
            const auto object_cell = create_object();
            const auto object = object_cell->cast_object();
            int i = 0;
            for (const auto& param : structure->params) {
              if (M->aR.contains(param.first)) {
                object->set(param.first, M->aR[param.first]);
              } else if (M->aR.contains(std::to_string(i))) {
                object->set(param.first, M->aR[std::to_string(i)]);
              }
              ++i;
            }
            M->aR.clear();
            M->stack.push(object_cell);
          }
          break;
        }
        case OP_RETURN: {
          const auto call_stack_value = M->call_stack.top();
          M->call_stack.pop();
          M->i = call_stack_value->return_index;
          DEBUG_LOG("returning to " + std::to_string(M->i))
          goto start;
          break;
        }
        case OP_LOAD_ARG: {
          const auto call_stack_value = M->call_stack.top();
          if (M->aR.contains(I->strval)) {
            call_stack_value->scope->set_variable(I->strval, M->aR[I->strval]);
          } else if (M->aR.contains(std::to_string(I->numval))) {
            call_stack_value->scope->set_variable(
                I->strval, M->aR[std::to_string(I->numval)]);
          } else {
            call_stack_value->scope->set_variable(I->strval, M->empty_cell);
          }

          break;
        }
        case OP_POP: {
          M->stack.pop();
          break;
        }
        case OP_SET_ARG: {
          const auto value = M->stack.top();
          M->stack.pop();

          M->aR.insert_or_assign(I->strval, value);
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
          list->value.push_back(value);
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
              if (index >= 0 && index < list->value.size()) {
                M->stack.push(list->value[index]);
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
              if (index >= 0) {
                if (index >= list->value.size()) {
                  list->value.resize(index + 1);
                }
                list->value[index] = value;
              }
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
              const auto length = cell->cast_list()->value.size();
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
          M->stack.push(create_structure());
          break;
        }
        case OP_STRUCT_PARAM: {
          const auto cell = M->stack.top();
          cell->cast_structure()->params.insert_or_assign(I->strval, nullptr);
          break;
        }
        case OP_DIIA_PARAM: {
          const auto cell = M->stack.top();
          cell->cast_diia()->params.insert_or_assign(I->strval, nullptr);
          break;
        }
        default: {
          std::cout << "unsupported instruction " << I->op << std::endl;
          return;
        }
      }

      M->i++;
    }
  }
} // namespace mavka::mama
