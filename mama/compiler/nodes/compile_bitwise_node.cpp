#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_bitwise_node(
      MaCode* C,
      const mavka::ast::BitwiseNode* bitwise_node) {
    const auto left = compile_node(C, bitwise_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(C, bitwise_node->right);
    if (right->error) {
      return right;
    }
    if (bitwise_node->op == "^") {
      C->instructions.push_back(new MaInstruction(OP_XOR));
    } else if (bitwise_node->op == "|") {
      C->instructions.push_back(new MaInstruction(OP_BOR));
    } else if (bitwise_node->op == "&") {
      C->instructions.push_back(new MaInstruction(OP_BAND));
    } else if (bitwise_node->op == "<<") {
      C->instructions.push_back(new MaInstruction(OP_SHL));
    } else if (bitwise_node->op == ">>") {
      C->instructions.push_back(new MaInstruction(OP_SHR));
    }
    return success();
  }
} // namespace mavka::mama
