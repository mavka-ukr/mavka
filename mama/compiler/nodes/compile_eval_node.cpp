#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_eval_node(MaMa* M,
                                        mavka::ast::EvalNode* eval_node) {
    return error(
        mavka::ast::make_ast_some(eval_node),
        "Вказівка \"js\" недоступна і буде видалена в подальших версіях.");
  }
} // namespace mavka::mama