#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_function_node(
      MaCode* C,
      mavka::ast::FunctionNode* function_node) {
    return error(mavka::ast::make_ast_some(function_node), "Not implemented");
  }
} // namespace mavka::mama