#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_mockup_diia_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::MockupDiiaNode* mockup_diia_node) {
    return error(mavka::ast::make_ast_some(mockup_diia_node),
                 "Макети тимчасово недоступні.");
  }
} // namespace mavka::mama