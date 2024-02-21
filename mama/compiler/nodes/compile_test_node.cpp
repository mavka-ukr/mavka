#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_test_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::TestNode* test_node) {
    if (test_node->op == "&&" || test_node->op == "і") {
      const auto left = compile_node(M, code, test_node->left);
      if (left.error) {
        return left;
      }
      code->instructions.push_back(MaInstruction{OP_E_JUMP_IF_FALSE});
      const auto jump_if_false_instruction_index = code->instructions.size() - 1;
      code->instructions.push_back(MaInstruction::pop());
      const auto right = compile_node(M, code, test_node->right);
      if (right.error) {
        return right;
      }
      code->instructions[jump_if_false_instruction_index].args.jumpiffalse =
          code->instructions.size();
    } else if (test_node->op == "||" || test_node->op == "або") {
      const auto left = compile_node(M, code, test_node->left);
      if (left.error) {
        return left;
      }
      code->instructions.push_back(MaInstruction{OP_E_JUMP_IF_TRUE});
      const auto jump_if_true_instruction_index = code->instructions.size() - 1;
      code->instructions.push_back(MaInstruction::pop());
      const auto right = compile_node(M, code, test_node->right);
      if (right.error) {
        return right;
      }
      code->instructions[jump_if_true_instruction_index].args.jumpiftrue = code->instructions.size();
    } else {
      return error(ast::make_ast_some(test_node),
                   "Невідома вказівка \"" + test_node->op + "\".");
    }
    return success();
  }
} // namespace mavka::mama