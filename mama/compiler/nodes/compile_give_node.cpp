#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_give_node(MaMa* M,
                                         mavka::ast::GiveNode* give_node) {
    return error(mavka::ast::make_ast_some(give_node), "Not implemented");
  }
} // namespace mavka::mama