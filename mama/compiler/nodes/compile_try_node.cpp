#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_try_node(MaCode* C,
                                        mavka::ast::TryNode* try_node) {
    return error(mavka::ast::make_ast_some(try_node), "Not implemented");
  }
} // namespace mavka::mama