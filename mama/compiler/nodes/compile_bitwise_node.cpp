#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_bitwise_node(
      MaMa* M,
      const mavka::ast::BitwiseNode* bitwise_node) {
    const auto left = compile_node(M, bitwise_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(M, bitwise_node->right);
    if (right->error) {
      return right;
    }
    if (bitwise_node->op == "^") {
      M->instructions.push_back(MaInstruction{OP_XOR});
    } else if (bitwise_node->op == "|") {
      M->instructions.push_back(MaInstruction{OP_BOR});
    } else if (bitwise_node->op == "&") {
      M->instructions.push_back(MaInstruction{OP_BAND});
    } else if (bitwise_node->op == "<<") {
      M->instructions.push_back(MaInstruction{OP_SHL});
    } else if (bitwise_node->op == ">>") {
      M->instructions.push_back(MaInstruction{OP_SHR});
    }
    return success();
  }
} // namespace mavka::mama
