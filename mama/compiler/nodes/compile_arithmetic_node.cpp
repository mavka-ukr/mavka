#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_arithmetic_node(
      MaCode* C,
      const mavka::ast::ArithmeticNode* arithmetic_node) {
    const auto left = compile_node(C, arithmetic_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(C, arithmetic_node->right);
    if (right->error) {
      return right;
    }
    if (arithmetic_node->op == "+") {
      C->instructions.push_back(new MaInstruction(OP_ADD));
    } else if (arithmetic_node->op == "-") {
      C->instructions.push_back(new MaInstruction(OP_SUB));
    } else if (arithmetic_node->op == "*") {
      C->instructions.push_back(new MaInstruction(OP_MUL));
    } else if (arithmetic_node->op == "/") {
      C->instructions.push_back(new MaInstruction(OP_DIV));
    } else if (arithmetic_node->op == "%") {
      C->instructions.push_back(new MaInstruction(OP_MOD));
    } else if (arithmetic_node->op == "//") {
      C->instructions.push_back(new MaInstruction(OP_DIVDIV));
    } else if (arithmetic_node->op == "**") {
      C->instructions.push_back(new MaInstruction(OP_POW));
    }
    return success();
  }
} // namespace mavka::mama
