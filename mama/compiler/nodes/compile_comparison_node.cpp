#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_comparison_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ComparisonNode* comparison_node) {
    const auto left = compile_node(M, code, comparison_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, code, comparison_node->right);
    if (right.error) {
      return right;
    }
    if (comparison_node->op == "==" || comparison_node->op == "рівно") {
      code->instructions.push_back(MaInstruction::eq());
    } else if (comparison_node->op == "!=" ||
               comparison_node->op == "не рівно" ||
               comparison_node->op == "нерівно") {
      code->instructions.push_back(MaInstruction::eq());
      code->instructions.push_back(MaInstruction::not_());
    } else if (comparison_node->op == ">" || comparison_node->op == "більше") {
      code->instructions.push_back(MaInstruction::gt());
    } else if (comparison_node->op == ">=" ||
               comparison_node->op == "не менше" ||
               comparison_node->op == "неменше") {
      code->instructions.push_back(MaInstruction::ge());
    } else if (comparison_node->op == "<" || comparison_node->op == "менше") {
      code->instructions.push_back(MaInstruction::lt());
    } else if (comparison_node->op == "<=" ||
               comparison_node->op == "не більше" ||
               comparison_node->op == "небільше") {
      code->instructions.push_back(MaInstruction::le());
    } else if (comparison_node->op == "містить") {
      code->instructions.push_back(MaInstruction::contains());
    } else if (comparison_node->op == "не містить" ||
               comparison_node->op == "немістить") {
      code->instructions.push_back(MaInstruction::contains());
      code->instructions.push_back(MaInstruction::not_());
    } else if (comparison_node->op == "є") {
      code->instructions.push_back(MaInstruction::is());
    } else if (comparison_node->op == "не є" || comparison_node->op == "неє") {
      code->instructions.push_back(MaInstruction::is());
      code->instructions.push_back(MaInstruction::not_());
    } else {
      return error(mavka::ast::make_ast_some(comparison_node),
                   "Невідомий оператор порівняння: " + comparison_node->op);
    }
    return success();
  }
} // namespace mavka::mama
