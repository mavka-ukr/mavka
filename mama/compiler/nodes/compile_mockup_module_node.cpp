#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_mockup_module_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    return error(ast_value, "Макети тимчасово недоступні.");
  }
} // namespace mavka::mama