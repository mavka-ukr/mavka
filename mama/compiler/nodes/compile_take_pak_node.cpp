#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_take_pak_node(
      MaMa* M,
      mavka::ast::TakePakNode* take_pak_node) {
    return error(mavka::ast::make_ast_some(take_pak_node), "Not implemented");
  }
} // namespace mavka::mama