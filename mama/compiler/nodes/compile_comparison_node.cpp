#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_comparison_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto comparison_node = ast_value->data.ComparisonNode;
    const auto left = compile_node(M, code, comparison_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, code, comparison_node->right);
    if (right.error) {
      return right;
    }
    if (comparison_node->op == ast::COMPARISON_EQ) {
      code->instructions.push_back(MaInstruction::eq());
    } else if (comparison_node->op == ast::COMPARISON_NE) {
      code->instructions.push_back(MaInstruction::eq());
      code->instructions.push_back(MaInstruction::not_());
    } else if (comparison_node->op == ast::COMPARISON_GT) {
      code->instructions.push_back(MaInstruction::gt());
    } else if (comparison_node->op == ast::COMPARISON_GE) {
      code->instructions.push_back(MaInstruction::ge());
    } else if (comparison_node->op == ast::COMPARISON_LT) {
      code->instructions.push_back(MaInstruction::lt());
    } else if (comparison_node->op == ast::COMPARISON_LE) {
      code->instructions.push_back(MaInstruction::le());
    } else if (comparison_node->op == ast::COMPARISON_CONTAINS) {
      code->instructions.push_back(MaInstruction::contains());
    } else if (comparison_node->op == ast::COMPARISON_NOT_CONTAINS) {
      code->instructions.push_back(MaInstruction::contains());
      code->instructions.push_back(MaInstruction::not_());
    } else if (comparison_node->op == ast::COMPARISON_IS) {
      code->instructions.push_back(MaInstruction::is());
    } else if (comparison_node->op == ast::COMPARISON_NOT_IS) {
      code->instructions.push_back(MaInstruction::is());
      code->instructions.push_back(MaInstruction::not_());
    }
    return success();
  }
} // namespace mavka::mama
