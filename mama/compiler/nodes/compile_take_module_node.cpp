#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_take_module_node(
      MaMa* M, MaCode* code,
      mavka::ast::TakeModuleNode* take_module_node) {
    return error(mavka::ast::make_ast_some(take_module_node),
                 "Вказівка \"взяти\" тимчасово недоступна.");
  }
} // namespace mavka::mama