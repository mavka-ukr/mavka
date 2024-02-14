#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_wait_node(MaMa* M, MaCode* code,
                                        mavka::ast::WaitNode* wait_node) {
    return error(mavka::ast::make_ast_some(wait_node),
                 "Вказівка \"чекати\" тимчасово недоступна.");
  }
} // namespace mavka::mama