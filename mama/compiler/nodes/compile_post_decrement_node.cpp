#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_post_decrement_node(
      MaCode* C,
      mavka::ast::PostDecrementNode* post_decrement_node) {
    return error(mavka::ast::make_ast_some(post_decrement_node),
                 "Not implemented");
  }
} // namespace mavka::mama