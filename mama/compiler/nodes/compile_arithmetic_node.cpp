#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_arithmetic_node(
      MaMa* M,
      const mavka::ast::ArithmeticNode* arithmetic_node) {
    const auto left = compile_node(M, arithmetic_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, arithmetic_node->right);
    if (right.error) {
      return right;
    }
    if (arithmetic_node->op == "+") {
      M->code.push_back(MaInstruction::add());
    } else if (arithmetic_node->op == "-") {
      M->code.push_back(MaInstruction::sub());
    } else if (arithmetic_node->op == "*") {
      M->code.push_back(MaInstruction::mul());
    } else if (arithmetic_node->op == "/") {
      M->code.push_back(MaInstruction::div());
    } else if (arithmetic_node->op == "%") {
      M->code.push_back(MaInstruction::mod());
    } else if (arithmetic_node->op == "//") {
      M->code.push_back(MaInstruction::divdiv());
    } else if (arithmetic_node->op == "**") {
      M->code.push_back(MaInstruction::pop());
    }
    return success();
  }
} // namespace mavka::mama
