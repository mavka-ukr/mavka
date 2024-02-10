#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_post_decrement_node(
      MaMa* M,
      mavka::ast::PostDecrementNode* post_decrement_node) {
    return error(mavka::ast::make_ast_some(post_decrement_node),
                 "Вказівка зменшення тимчасово недоступна.");
  }
} // namespace mavka::mama