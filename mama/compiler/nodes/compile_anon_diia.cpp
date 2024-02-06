#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_anon_diia_node(
      MaCode* C,
      mavka::ast::AnonDiiaNode* anon_diia_node) {
    return error(mavka::ast::make_ast_some(anon_diia_node), "Not implemented");
  }
} // namespace mavka::mama
