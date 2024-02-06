#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_mockup_structure_node(
      MaCode* C,
      mavka::ast::MockupStructureNode* mockup_structure_node) {
    return error(mavka::ast::make_ast_some(mockup_structure_node),
                 "Not implemented");
  }
} // namespace mavka::mama