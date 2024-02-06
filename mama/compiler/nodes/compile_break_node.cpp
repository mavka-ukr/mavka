#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_break_node(MaCode* C,
                                          mavka::ast::BreakNode* break_node) {
    return error(mavka::ast::make_ast_some(break_node), "Not implemented");
  }
} // namespace mavka::mama
