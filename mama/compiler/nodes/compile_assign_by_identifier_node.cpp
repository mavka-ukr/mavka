#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_assign_by_identifier_node(
      MaCode* C,
      mavka::ast::AssignByIdentifierNode* assign_by_identifier_node) {
    return error(mavka::ast::make_ast_some(assign_by_identifier_node),
                 "Not implemented");
  }
} // namespace mavka::mama
