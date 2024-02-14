#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_pre_decrement_node(
      MaMa* M, MaCode* code,
      mavka::ast::PreDecrementNode* pre_decrement_node) {
    return error(mavka::ast::make_ast_some(pre_decrement_node),
                 "Вказівка зменшення тимчасово недоступна.");
  }
} // namespace mavka::mama