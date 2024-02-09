#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_pre_increment_node(
      MaMa* M,
      mavka::ast::PreIncrementNode* pre_increment_node) {
    return error(mavka::ast::make_ast_some(pre_increment_node),
                 "Not implemented");
  }
} // namespace mavka::mama