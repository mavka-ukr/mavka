#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_comparison_node(
      MaCode* C,
      mavka::ast::ComparisonNode* comparison_node) {
    const auto left = compile_node(C, comparison_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(C, comparison_node->right);
    if (right->error) {
      return right;
    }
    if (comparison_node->op == "==" || comparison_node->op == "рівно") {
      C->instructions.push_back(new MaInstruction(OP_EQ));
    } else if (comparison_node->op == "!=" ||
               comparison_node->op == "не рівно") {
      C->instructions.push_back(new MaInstruction(OP_NE));
    } else if (comparison_node->op == "<" || comparison_node->op == "менше") {
      C->instructions.push_back(new MaInstruction(OP_LT));
    } else if (comparison_node->op == "<=" ||
               comparison_node->op == "не більше") {
      C->instructions.push_back(new MaInstruction(OP_LE));
    } else if (comparison_node->op == ">" || comparison_node->op == "більше") {
      C->instructions.push_back(new MaInstruction(OP_GT));
    } else if (comparison_node->op == ">=" ||
               comparison_node->op == "не менше") {
      C->instructions.push_back(new MaInstruction(OP_GE));
    }
    return success();
  }
} // namespace mavka::mama
