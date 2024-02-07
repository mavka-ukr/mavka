#include "../mama.h"

#define MAMA_PRINT_DEBUG 1

namespace mavka::mama {
#include "instructions/do_ADD.h"
#include "instructions/do_AND.h"
#include "instructions/do_BAND.h"
#include "instructions/do_BNOT.h"
#include "instructions/do_BOR.h"
#include "instructions/do_CLEAR_ARGS.h"
#include "instructions/do_DICT.h"
#include "instructions/do_DICT_SET.h"
#include "instructions/do_DIV.h"
#include "instructions/do_DIVDIV.h"
#include "instructions/do_EACH_SIMPLE.h"
#include "instructions/do_EQ.h"
#include "instructions/do_GE.h"
#include "instructions/do_GET.h"
#include "instructions/do_GET_ELEMENT.h"
#include "instructions/do_GT.h"
#include "instructions/do_LE.h"
#include "instructions/do_LIST.h"
#include "instructions/do_LIST_APPEND.h"
#include "instructions/do_LOAD.h"
#include "instructions/do_LOAD_ARG.h"
#include "instructions/do_LT.h"
#include "instructions/do_MOD.h"
#include "instructions/do_MUL.h"
#include "instructions/do_NE.h"
#include "instructions/do_NEGATIVE.h"
#include "instructions/do_OR.h"
#include "instructions/do_POSITIVE.h"
#include "instructions/do_POW.h"
#include "instructions/do_PUSH_DIIA.h"
#include "instructions/do_PUSH_NUMBER.h"
#include "instructions/do_PUSH_STRING.h"
#include "instructions/do_SET.h"
#include "instructions/do_SET_ARG.h"
#include "instructions/do_SET_ELEMENT.h"
#include "instructions/do_SHL.h"
#include "instructions/do_SHR.h"
#include "instructions/do_STORE.h"
#include "instructions/do_SUB.h"
#include "instructions/do_THROW.h"
#include "instructions/do_XOR.h"

  void run(MaMa* M, MaScope* S, MaCode* C) {
    M->i = 0;
    const auto size = C->instructions.size();
    for (;;) {
    start:
      if (M->i >= size) {
        return;
      }
      const auto I = C->instructions[M->i];
#if MAMA_PRINT_DEBUG == 1
      print_instruction_with_index(M->i, I);
#endif

      if (M->do_throw) {
        const auto value = M->stack.top();
        M->stack.pop();
        print_cell(value);
        return;
      }

      switch (I->op) {
        case OP_PUSH_NUMBER: {
          do_PUSH_NUMBER(M, I->numval);
          break;
        }
        case OP_ADD: {
          do_ADD(M);
          break;
        }
        case OP_SUB: {
          do_SUB(M);
          break;
        }
        case OP_MUL: {
          do_MUL(M);
          break;
        }
        case OP_DIV: {
          do_DIV(M);
          break;
        }
        case OP_MOD: {
          do_MOD(M);
          break;
        }
        case OP_DIVDIV: {
          do_DIVDIV(M);
          break;
        }
        case OP_POW: {
          do_POW(M);
          break;
        }
        case OP_STORE: {
          do_STORE(M, I->strval);
          break;
        }
        case OP_LOAD: {
          do_LOAD(M, I->strval);
          break;
        }
        case OP_PUSH_STRING: {
          do_PUSH_STRING(M, I->strval);
          break;
        }
        case OP_XOR: {
          do_XOR(M);
          break;
        }
        case OP_BAND: {
          do_BAND(M);
          break;
        }
        case OP_BOR: {
          do_BOR(M);
          break;
        }
        case OP_SHL: {
          do_SHL(M);
          break;
        }
        case OP_SHR: {
          do_SHR(M);
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
        case OP_JUMP: {
          M->i = I->numval;
          goto start;
          break;
        }
        case OP_THROW: {
          do_THROW(M);
          break;
        }
        case OP_EQ: {
          do_EQ(M);
          break;
        }
        case OP_NE: {
          do_NE(M);
          break;
        }
        case OP_LT: {
          do_LT(M);
          break;
        }
        case OP_LE: {
          do_LE(M);
          break;
        }
        case OP_GT: {
          do_GT(M);
          break;
        }
        case OP_GE: {
          do_GE(M);
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
            const auto object_cell = create_object({});
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
#if MAMA_PRINT_DEBUG == 1
          std::cout << "returning to " << M->i << std::endl;
#endif
          goto start;
          break;
        }
        case OP_LOAD_ARG: {
          do_LOAD_ARG(M, I->numval, I->strval);
          break;
        }
        case OP_POP: {
          M->stack.pop();
          break;
        }
        case OP_SET_ARG: {
          do_SET_ARG(M, I->strval);
          break;
        }
        case OP_LIST: {
          do_LIST(M);
          break;
        }
        case OP_LIST_APPEND: {
          do_LIST_APPEND(M);
          break;
        }
        case OP_GET_ELEMENT: {
          do_GET_ELEMENT(M);
          break;
        }
        case OP_SET_ELEMENT: {
          do_SET_ELEMENT(M);
          break;
        }
        case OP_NEGATIVE: {
          do_NEGATIVE(M);
          break;
        }
        case OP_POSITIVE: {
          do_POSITIVE(M);
          break;
        }
        case OP_DIIA: {
          do_PUSH_DIIA(M, I->numval, I->strval);
          break;
        }
        case OP_GET: {
          do_GET(M, I->strval);
          break;
        }
        case OP_SET: {
          do_SET(M, I->strval);
          break;
        }
        case OP_EACH_SIMPLE: {
          do_EACH_SIMPLE(M, I->strval);
          break;
        }
        case OP_CLEAR_ARGS: {
          do_CLEAR_ARGS(M);
          break;
        }
        case OP_DICT: {
          do_DICT(M);
          break;
        }
        case OP_DICT_SET: {
          do_DICT_SET(M, I->strval);
          break;
        }
        case OP_STRUCT: {
          M->stack.push(create_structure({}));
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
