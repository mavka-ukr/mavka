#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_bitwise_node(
      MaMa* M,
      const mavka::ast::BitwiseNode* bitwise_node) {
    const auto left = compile_node(M, bitwise_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, bitwise_node->right);
    if (right.error) {
      return right;
    }
    if (bitwise_node->op == "^") {
      M->code.push_back(MaInstruction::xor_());
    } else if (bitwise_node->op == "|") {
      M->code.push_back(MaInstruction::bor());
    } else if (bitwise_node->op == "&") {
      M->code.push_back(MaInstruction::band());
    } else if (bitwise_node->op == "<<") {
      M->code.push_back(MaInstruction::shl());
    } else if (bitwise_node->op == ">>") {
      M->code.push_back(MaInstruction::shr());
    }
    return success();
  }
} // namespace mavka::mama
