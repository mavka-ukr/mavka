#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_wait_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::ASTValue* ast_value) {
    return error(ast_value, "Вказівка \"чекати\" тимчасово недоступна.");
  }
} // namespace mavka::mama