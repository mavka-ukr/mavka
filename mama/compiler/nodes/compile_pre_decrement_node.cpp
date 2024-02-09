#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_pre_decrement_node(
      MaMa* M,
      mavka::ast::PreDecrementNode* pre_decrement_node) {
    return error(mavka::ast::make_ast_some(pre_decrement_node),
                 "Not implemented");
  }
} // namespace mavka::mama