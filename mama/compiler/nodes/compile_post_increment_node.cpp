#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_post_increment_node(
      MaCode* C,
      mavka::ast::PostIncrementNode* post_increment_node) {
    return error(mavka::ast::make_ast_some(post_increment_node),
                 "Not implemented");
  }
} // namespace mavka::mama