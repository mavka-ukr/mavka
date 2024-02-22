#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_post_increment_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    return error(ast_value, "Вказівка збільшення тимчасово недоступна.");
  }
} // namespace mavka::mama