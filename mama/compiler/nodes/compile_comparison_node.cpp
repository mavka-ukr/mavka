#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_comparison_node(
      MaMa* M,
      const mavka::ast::ComparisonNode* comparison_node) {
    const auto right = compile_node(M, comparison_node->right);
    if (right.error) {
      return right;
    }
    const auto left = compile_node(M, comparison_node->left);
    if (left.error) {
      return left;
    }
    if (comparison_node->op == "==" || comparison_node->op == "рівно") {
      M->code.push_back(MaInstruction{OP_EQ});
    } else if (comparison_node->op == "!=" ||
               comparison_node->op == "не рівно") {
      M->code.push_back(MaInstruction{OP_EQ});
      M->code.push_back(MaInstruction{OP_NOT});
    } else if (comparison_node->op == ">" || comparison_node->op == "більше") {
      M->code.push_back(MaInstruction{OP_GT});
    }
    return success();
  }
} // namespace mavka::mama
