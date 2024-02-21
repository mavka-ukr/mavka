#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_method_declaration_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::MethodDeclarationNode* method_declaration_node) {
    return error(mavka::ast::make_ast_some(method_declaration_node),
                 "Макети тимчасово недоступні.");
  }
} // namespace mavka::mama