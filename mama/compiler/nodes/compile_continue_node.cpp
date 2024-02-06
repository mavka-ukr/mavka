#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_continue_node(
      MaCode* C,
      mavka::ast::ContinueNode* continue_node) {
    return error(mavka::ast::make_ast_some(continue_node), "Not implemented");
  }
} // namespace mavka::mama
