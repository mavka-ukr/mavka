#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_anon_diia_node(
      MaCode* C,
      const mavka::ast::AnonDiiaNode* anon_diia_node) {
    return compile_diia(C, anon_diia_node->async, anon_diia_node->generics, "",
                        anon_diia_node->params, anon_diia_node->return_types,
                        anon_diia_node->body);
  }
} // namespace mavka::mama
