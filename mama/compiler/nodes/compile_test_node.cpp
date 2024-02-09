#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_test_node(
      MaMa* M,
      const mavka::ast::TestNode* test_node) {
    const auto left = compile_node(M, test_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(M, test_node->right);
    if (right->error) {
      return right;
    }
    // todo
    return success();
  }
} // namespace mavka::mama