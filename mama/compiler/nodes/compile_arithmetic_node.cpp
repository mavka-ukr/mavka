#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_arithmetic_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ArithmeticNode* arithmetic_node) {
    const auto left = compile_node(M, code, arithmetic_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, code, arithmetic_node->right);
    if (right.error) {
      return right;
    }
    const auto instruction_location = new MaInstructionLocation(
        arithmetic_node->start_line, arithmetic_node->start_column);
    if (arithmetic_node->op == "+") {
      code->instructions.push_back(MaInstruction::add(instruction_location));
    } else if (arithmetic_node->op == "-") {
      code->instructions.push_back(MaInstruction::sub(instruction_location));
    } else if (arithmetic_node->op == "*") {
      code->instructions.push_back(MaInstruction::mul(instruction_location));
    } else if (arithmetic_node->op == "/") {
      code->instructions.push_back(MaInstruction::div(instruction_location));
    } else if (arithmetic_node->op == "%") {
      code->instructions.push_back(MaInstruction::mod(instruction_location));
    } else if (arithmetic_node->op == "//") {
      code->instructions.push_back(MaInstruction::divdiv(instruction_location));
    } else if (arithmetic_node->op == "**") {
      code->instructions.push_back(MaInstruction::pow(instruction_location));
    }
    return success();
  }
} // namespace mavka::mama
