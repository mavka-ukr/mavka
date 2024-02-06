#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_give_node(MaCode* C,
                                         mavka::ast::GiveNode* give_node) {
    return error(mavka::ast::make_ast_some(give_node), "Not implemented");
  }
} // namespace mavka::mama