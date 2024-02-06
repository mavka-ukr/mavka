#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_method_declaration_node(
      MaCode* C,
      mavka::ast::MethodDeclarationNode* method_declaration_node) {
    return error(mavka::ast::make_ast_some(method_declaration_node),
                 "Not implemented");
  }
} // namespace mavka::mama