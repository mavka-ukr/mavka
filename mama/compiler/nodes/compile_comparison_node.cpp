#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_comparison_node(
      MaMa* M,
      mavka::ast::ComparisonNode* comparison_node) {
    const auto left = compile_node(M, comparison_node->left);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, comparison_node->right);
    if (right.error) {
      return right;
    }
    if (comparison_node->op == "==" || comparison_node->op == "рівно") {
      M->code.push_back(MaInstruction::eq());
    } else if (comparison_node->op == "!=" ||
               comparison_node->op == "не рівно" ||
               comparison_node->op == "нерівно") {
      M->code.push_back(MaInstruction::eq());
      M->code.push_back(MaInstruction::not_());
    } else if (comparison_node->op == ">" || comparison_node->op == "більше") {
      M->code.push_back(MaInstruction::gt());
    } else if (comparison_node->op == ">=" ||
               comparison_node->op == "не менше" ||
               comparison_node->op == "неменше") {
      M->code.push_back(MaInstruction::ge());
    } else if (comparison_node->op == "<" || comparison_node->op == "менше") {
      M->code.push_back(MaInstruction::lt());
    } else if (comparison_node->op == "<=" ||
               comparison_node->op == "не більше" ||
               comparison_node->op == "небільше") {
      M->code.push_back(MaInstruction::le());
    } else if (comparison_node->op == "містить") {
      M->code.push_back(MaInstruction::contains());
    } else if (comparison_node->op == "не містить" ||
               comparison_node->op == "немістить") {
      M->code.push_back(MaInstruction::contains());
      M->code.push_back(MaInstruction::not_());
    } else if (comparison_node->op == "є") {
      M->code.push_back(MaInstruction::is());
    } else if (comparison_node->op == "не є" || comparison_node->op == "неє") {
      M->code.push_back(MaInstruction::is());
      M->code.push_back(MaInstruction::not_());
    } else {
      return error(mavka::ast::make_ast_some(comparison_node),
                   "Невідомий оператор порівняння: " + comparison_node->op);
    }
    return success();
  }
} // namespace mavka::mama
