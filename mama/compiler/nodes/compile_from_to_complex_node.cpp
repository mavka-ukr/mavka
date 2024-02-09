#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_from_to_complex_node(
      MaMa* M,
      mavka::ast::FromToComplexNode* from_to_complex_node) {
    return error(mavka::ast::make_ast_some(from_to_complex_node),
                 "Not implemented");
  }
} // namespace mavka::mama