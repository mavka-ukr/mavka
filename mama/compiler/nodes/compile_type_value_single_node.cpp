#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_type_value_single_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::TypeValueSingleNode* type_value_single_node) {
    return error(mavka::ast::make_ast_some(type_value_single_node),
                 "Not implemented");
  }
} // namespace mavka::mama