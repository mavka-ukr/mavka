#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_mrm_diia_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    return error(ast_value, "Вказівка <дія> тимчасово недоступна.");
  }
} // namespace mavka::mama