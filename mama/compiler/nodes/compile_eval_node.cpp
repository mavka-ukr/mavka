#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_eval_node(MaCode* C,
                                         mavka::ast::EvalNode* eval_node) {
    return error(mavka::ast::make_ast_some(eval_node), "Not implemented");
  }
} // namespace mavka::mama