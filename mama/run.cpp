#include "mama.h"

namespace mavka::mama {
#include "interpreter/do_ADD.h"
#include "interpreter/do_AND.h"
#include "interpreter/do_BAND.h"
#include "interpreter/do_BNOT.h"
#include "interpreter/do_BOR.h"
#include "interpreter/do_CALL.h"
#include "interpreter/do_CLEAR_ARGS.h"
#include "interpreter/do_DIV.h"
#include "interpreter/do_DIVDIV.h"
#include "interpreter/do_EACH_SIMPLE.h"
#include "interpreter/do_EQ.h"
#include "interpreter/do_GE.h"
#include "interpreter/do_GET.h"
#include "interpreter/do_GET_ELEMENT.h"
#include "interpreter/do_GT.h"
#include "interpreter/do_JUMP.h"
#include "interpreter/do_JUMP_IF_FALSE.h"
#include "interpreter/do_LE.h"
#include "interpreter/do_LIST.h"
#include "interpreter/do_LIST_APPEND.h"
#include "interpreter/do_LOAD.h"
#include "interpreter/do_LOAD_ARG.h"
#include "interpreter/do_LT.h"
#include "interpreter/do_MOD.h"
#include "interpreter/do_MUL.h"
#include "interpreter/do_NE.h"
#include "interpreter/do_NEGATIVE.h"
#include "interpreter/do_OR.h"
#include "interpreter/do_POSITIVE.h"
#include "interpreter/do_POW.h"
#include "interpreter/do_PUSH_NUMBER.h"
#include "interpreter/do_PUSH_STRING.h"
#include "interpreter/do_RETURN.h"
#include "interpreter/do_SET.h"
#include "interpreter/do_SET_ARG.h"
#include "interpreter/do_SET_ELEMENT.h"
#include "interpreter/do_SHL.h"
#include "interpreter/do_SHR.h"
#include "interpreter/do_STORE.h"
#include "interpreter/do_STORE_DIIA.h"
#include "interpreter/do_SUB.h"
#include "interpreter/do_THROW.h"
#include "interpreter/do_XOR.h"

  void run(MaMa* M, MaScope* S, MaCode* C) {
    for (M->i = 0; M->i < C->instructions.size(); ++M->i) {
      const auto I = C->instructions[M->i];
      // print_instruction_with_index(M->i, I);

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
          do_JUMP_IF_FALSE(M, I->numval);
          break;
        }
        case OP_JUMP: {
          do_JUMP(M, I->numval);
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
          do_CALL(M);
          break;
        }
        case OP_RETURN: {
          do_RETURN(M);
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
        case OP_STORE_DIIA: {
          do_STORE_DIIA(M, I->numval, I->strval);
          break;
        }
        case OP_GET: {
          do_GET(M, I->strval);
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
        default: {
          std::cout << "unsupported instruction " << I->op << std::endl;
          return;
        }
      }
    }

    if (M->do_throw) {
      const auto value = M->stack.top();
      M->stack.pop();
      print_cell(value);
    }
  }
} // namespace mavka::mama
