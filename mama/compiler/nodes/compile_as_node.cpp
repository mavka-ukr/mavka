#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_as_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value) {
    return error(ast_value, "Вказівка \"як\" тимчасово недоступна.");
  }
} // namespace mavka::mama
