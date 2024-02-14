#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_mockup_structure_node(
      MaMa* M, MaCode* code,
      mavka::ast::MockupStructureNode* mockup_structure_node) {
    return error(mavka::ast::make_ast_some(mockup_structure_node),
                 "Макети тимчасово недоступні.");
  }
} // namespace mavka::mama