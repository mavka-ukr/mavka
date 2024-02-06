#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_test_node(MaCode* C,
                                         mavka::ast::TestNode* test_node) {
    const auto left = compile_node(C, test_node->left);
    if (left->error) {
      return left;
    }
    const auto right = compile_node(C, test_node->right);
    if (right->error) {
      return right;
    }
    // todo
    return success();
  }
} // namespace mavka::mama