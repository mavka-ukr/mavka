#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_take_module_node(
      MaCode* C,
      mavka::ast::TakeModuleNode* take_module_node) {
    return error(mavka::ast::make_ast_some(take_module_node),
                 "Not implemented");
  }
} // namespace mavka::mama