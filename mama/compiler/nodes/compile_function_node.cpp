#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_function_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::FunctionNode* function_node) {
    return compile_diia(M, code, function_node->async, {}, "",
                        function_node->params, function_node->return_types,
                        function_node->body);
  }
} // namespace mavka::mama