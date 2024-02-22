#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_god_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value) {
    return error(ast_value, "Бог недоступний.");
  }
} // namespace mavka::mama