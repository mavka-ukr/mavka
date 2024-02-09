#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_comparison_node(
      MaMa* M,
      const mavka::ast::ComparisonNode* comparison_node) {
    const auto left = compile_node(M, comparison_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(M, comparison_node->right);
    if (right->error) {
      return right;
    }
    if (comparison_node->op == "==" || comparison_node->op == "рівно") {
      M->instructions.push_back(MaInstruction{OP_EQ});
    } else if (comparison_node->op == "!=" ||
               comparison_node->op == "не рівно") {
      M->instructions.push_back(MaInstruction{OP_NE});
    } else if (comparison_node->op == "<" || comparison_node->op == "менше") {
      M->instructions.push_back(MaInstruction{OP_LT});
    } else if (comparison_node->op == "<=" ||
               comparison_node->op == "не більше") {
      M->instructions.push_back(MaInstruction{OP_LE});
    } else if (comparison_node->op == ">" || comparison_node->op == "більше") {
      M->instructions.push_back(MaInstruction{OP_GT});
    } else if (comparison_node->op == ">=" ||
               comparison_node->op == "не менше") {
      M->instructions.push_back(MaInstruction{OP_GE});
    }
    return success();
  }
} // namespace mavka::mama
