#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_bitwise_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto bitwise_node = ast_value->data.BitwiseNode;
    const auto left = compile_node(M, code, bitwise_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, code, bitwise_node->right);
    if (right.error) {
      return right;
    }
    if (bitwise_node->op == ast::BITWISE_XOR) {
      code->instructions.push_back(MaInstruction::xor_());
    } else if (bitwise_node->op == ast::BITWISE_OR) {
      code->instructions.push_back(MaInstruction::bor());
    } else if (bitwise_node->op == ast::BITWISE_AND) {
      code->instructions.push_back(MaInstruction::band());
    } else if (bitwise_node->op == ast::BITWISE_SHIFT_LEFT) {
      code->instructions.push_back(MaInstruction::shl());
    } else if (bitwise_node->op == ast::BITWISE_SHIFT_RIGHT) {
      code->instructions.push_back(MaInstruction::shr());
    }
    return success();
  }
} // namespace mavka::mama
