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
      M->code.push_back(MaInstruction{OP_ADD});
    } else if (arithmetic_node->op == "-") {
      M->code.push_back(MaInstruction{OP_SUB});
    } else if (arithmetic_node->op == "*") {
      M->code.push_back(MaInstruction{OP_MUL});
    } else if (arithmetic_node->op == "/") {
      M->code.push_back(MaInstruction{OP_DIV});
    } else if (arithmetic_node->op == "%") {
      M->code.push_back(MaInstruction{OP_MOD});
    } else if (arithmetic_node->op == "//") {
      M->code.push_back(MaInstruction{OP_DIVDIV});
    } else if (arithmetic_node->op == "**") {
      M->code.push_back(MaInstruction{OP_POW});
    }
    return success();
  }
} // namespace mavka::mama
