#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_mrm_diia_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::MRMDiiaNode* mrm_diia_node) {
    return error(mavka::ast::make_ast_some(mrm_diia_node),
                 "Вказівка <дія> тимчасово недоступна.");
  }
} // namespace mavka::mama