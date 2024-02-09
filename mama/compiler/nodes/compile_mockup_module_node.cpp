#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_mockup_module_node(
      MaMa* M,
      mavka::ast::MockupModuleNode* mockup_module_node) {
    return error(mavka::ast::make_ast_some(mockup_module_node),
                 "Not implemented");
  }
} // namespace mavka::mama