#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_god_node(MaMa* M,
                                        mavka::ast::GodNode* god_node) {
    return error(mavka::ast::make_ast_some(god_node), "Not implemented");
  }
} // namespace mavka::mama