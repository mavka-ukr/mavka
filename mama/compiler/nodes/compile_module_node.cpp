#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_module_node(
      MaCode* C,
      mavka::ast::ModuleNode* module_node) {
    return error(mavka::ast::make_ast_some(module_node), "Not implemented");
  }
} // namespace mavka::mama