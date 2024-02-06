#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_mml_node(MaCode* C,
                                        mavka::ast::MMLNode* mml_node) {
    return error(mavka::ast::make_ast_some(mml_node), "Not implemented");
  }
} // namespace mavka::mama