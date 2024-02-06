#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_from_to_simple_node(
      MaCode* C,
      mavka::ast::FromToSimpleNode* from_to_simple_node) {
    return error(mavka::ast::make_ast_some(from_to_simple_node),
                 "Not implemented");
  }
} // namespace mavka::mama