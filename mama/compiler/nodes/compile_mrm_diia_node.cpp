#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_mrm_diia_node(
      MaCode* C,
      mavka::ast::MRMDiiaNode* mrm_diia_node) {
    return error(mavka::ast::make_ast_some(mrm_diia_node), "Not implemented");
  }
} // namespace mavka::mama