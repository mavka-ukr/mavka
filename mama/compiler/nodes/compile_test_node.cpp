#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_test_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::ASTValue* ast_value) {
    const auto test_node = ast_value->data.TestNode;
    if (test_node->op == ast::TEST_AND) {
      const auto left = compile_node(M, code, test_node->left);
      if (left.error) {
        return left;
      }
      code->instructions.push_back(MaInstruction{VEJumpIfFalse});
      const auto jump_if_false_instruction_index =
          code->instructions.size() - 1;
      code->instructions.push_back(MaInstruction::pop());
      const auto right = compile_node(M, code, test_node->right);
      if (right.error) {
        return right;
      }
      code->instructions[jump_if_false_instruction_index].args.jumpiffalse =
          code->instructions.size();
    } else if (test_node->op == ast::TEST_OR) {
      const auto left = compile_node(M, code, test_node->left);
      if (left.error) {
        return left;
      }
      code->instructions.push_back(MaInstruction{VEJumpIfTrue});
      const auto jump_if_true_instruction_index = code->instructions.size() - 1;
      code->instructions.push_back(MaInstruction::pop());
      const auto right = compile_node(M, code, test_node->right);
      if (right.error) {
        return right;
      }
      code->instructions[jump_if_true_instruction_index].args.jumpiftrue =
          code->instructions.size();
    }
    return success();
  }
} // namespace mavka::mama