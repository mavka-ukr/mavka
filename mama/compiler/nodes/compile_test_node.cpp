#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_test_node(MaMa* M,
                                        const mavka::ast::TestNode* test_node) {
    if (test_node->op == "&&" || test_node->op == "і") {
      const auto left = compile_node(M, test_node->left);
      if (left.error) {
        return left;
      }
      M->code.push_back(MaInstruction{OP_E_JUMP_IF_FALSE});
      const auto jump_if_false_instruction_index = M->code.size() - 1;
      M->code.push_back(MaInstruction{OP_POP});
      const auto right = compile_node(M, test_node->right);
      if (right.error) {
        return right;
      }
      M->code[jump_if_false_instruction_index].args.jumpiffalse =
          M->code.size();
    } else if (test_node->op == "||" || test_node->op == "або") {
      const auto left = compile_node(M, test_node->left);
      if (left.error) {
        return left;
      }
      M->code.push_back(MaInstruction{OP_E_JUMP_IF_TRUE});
      const auto jump_if_true_instruction_index = M->code.size() - 1;
      M->code.push_back(MaInstruction{OP_POP});
      const auto right = compile_node(M, test_node->right);
      if (right.error) {
        return right;
      }
      M->code[jump_if_true_instruction_index].args.jumpiftrue = M->code.size();
    }
    return success();
  }
} // namespace mavka::mama