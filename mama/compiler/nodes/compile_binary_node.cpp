#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_binary_node(MaMa* M,
                                          MaCode* code,
                                          mavka::ast::ASTValue* ast_value) {
    const auto binary_node = ast_value->data.BinaryNode;
    const auto left = compile_node(M, code, binary_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, code, binary_node->right);
    if (right.error) {
      return right;
    }
    const auto instruction_location = new MaInstructionLocation(
        ast_value->start_line, ast_value->start_column);
    if (binary_node->op == ast::ARITHMETIC_ADD) {
      code->instructions.push_back(MaInstruction::add(instruction_location));
    } else if (binary_node->op == ast::ARITHMETIC_SUB) {
      code->instructions.push_back(MaInstruction::sub(instruction_location));
    } else if (binary_node->op == ast::ARITHMETIC_MUL) {
      code->instructions.push_back(MaInstruction::mul(instruction_location));
    } else if (binary_node->op == ast::ARITHMETIC_DIV) {
      code->instructions.push_back(MaInstruction::div(instruction_location));
    } else if (binary_node->op == ast::ARITHMETIC_MOD) {
      code->instructions.push_back(MaInstruction::mod(instruction_location));
    } else if (binary_node->op == ast::ARITHMETIC_DIVDIV) {
      code->instructions.push_back(MaInstruction::divdiv(instruction_location));
    } else if (binary_node->op == ast::ARITHMETIC_POW) {
      code->instructions.push_back(MaInstruction::pow(instruction_location));
    } else if (binary_node->op == ast::BITWISE_XOR) {
      code->instructions.push_back(MaInstruction::xor_());
    } else if (binary_node->op == ast::BITWISE_OR) {
      code->instructions.push_back(MaInstruction::bor());
    } else if (binary_node->op == ast::BITWISE_AND) {
      code->instructions.push_back(MaInstruction::band());
    } else if (binary_node->op == ast::BITWISE_SHIFT_LEFT) {
      code->instructions.push_back(MaInstruction::shl());
    } else if (binary_node->op == ast::BITWISE_SHIFT_RIGHT) {
      code->instructions.push_back(MaInstruction::shr());
    } else if (binary_node->op == ast::COMPARISON_EQ) {
      code->instructions.push_back(MaInstruction::eq());
    } else if (binary_node->op == ast::COMPARISON_NE) {
      code->instructions.push_back(MaInstruction::eq());
      code->instructions.push_back(MaInstruction::not_());
    } else if (binary_node->op == ast::COMPARISON_GT) {
      code->instructions.push_back(MaInstruction::gt());
    } else if (binary_node->op == ast::COMPARISON_GE) {
      code->instructions.push_back(MaInstruction::ge());
    } else if (binary_node->op == ast::COMPARISON_LT) {
      code->instructions.push_back(MaInstruction::lt());
    } else if (binary_node->op == ast::COMPARISON_LE) {
      code->instructions.push_back(MaInstruction::le());
    } else if (binary_node->op == ast::COMPARISON_CONTAINS) {
      code->instructions.push_back(MaInstruction::contains());
    } else if (binary_node->op == ast::COMPARISON_NOT_CONTAINS) {
      code->instructions.push_back(MaInstruction::contains());
      code->instructions.push_back(MaInstruction::not_());
    } else if (binary_node->op == ast::COMPARISON_IS) {
      code->instructions.push_back(MaInstruction::is());
    } else if (binary_node->op == ast::COMPARISON_NOT_IS) {
      code->instructions.push_back(MaInstruction::is());
      code->instructions.push_back(MaInstruction::not_());
    } else if (binary_node->op == ast::UTIL_AS) {
      return error(ast_value, "Вказівка \"як\" тимчасово недоступна.");
    }
    return success();
  }
} // namespace mavka::mama
