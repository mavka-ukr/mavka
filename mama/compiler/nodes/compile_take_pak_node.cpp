#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_take_pak_node(
      MaCode* C,
      mavka::ast::TakePakNode* take_pak_node) {
    return error(mavka::ast::make_ast_some(take_pak_node), "Not implemented");
  }
} // namespace mavka::mama