#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_function_node(
      MaCode* C,
      mavka::ast::FunctionNode* function_node) {
    return compile_diia(C, function_node->async, {}, "", function_node->params,
                        function_node->return_types, function_node->body);
  }
} // namespace mavka::mama