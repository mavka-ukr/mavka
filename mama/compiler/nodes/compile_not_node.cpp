#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_not_node(MaCode* C,
                                        mavka::ast::NotNode* not_node) {
    return error(mavka::ast::make_ast_some(not_node), "Not implemented");
  }
} // namespace mavka::mama