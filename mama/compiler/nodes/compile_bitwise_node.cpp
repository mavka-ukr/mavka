#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_bitwise_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::BitwiseNode* bitwise_node) {
    const auto left = compile_node(M, code, bitwise_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, code, bitwise_node->right);
    if (right.error) {
      return right;
    }
    if (bitwise_node->op == "^") {
      code->instructions.push_back(MaInstruction{OP_XOR});
    } else if (bitwise_node->op == "|") {
      code->instructions.push_back(MaInstruction{OP_BOR});
    } else if (bitwise_node->op == "&") {
      code->instructions.push_back(MaInstruction{OP_BAND});
    } else if (bitwise_node->op == "<<") {
      code->instructions.push_back(MaInstruction{OP_SHL});
    } else if (bitwise_node->op == ">>") {
      code->instructions.push_back(MaInstruction{OP_SHR});
    }
    return success();
  }
} // namespace mavka::mama
