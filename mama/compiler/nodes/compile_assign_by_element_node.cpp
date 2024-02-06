#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_assign_by_element_node(
      MaCode* C,
      mavka::ast::AssignByElementNode* assign_by_element_node) {
    return error(mavka::ast::make_ast_some(assign_by_element_node),
                 "Not implemented");
  }
} // namespace mavka::mama
