#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_wait_node(MaMa* M,
                                         mavka::ast::WaitNode* wait_node) {
    return error(mavka::ast::make_ast_some(wait_node), "Not implemented");
  }
} // namespace mavka::mama