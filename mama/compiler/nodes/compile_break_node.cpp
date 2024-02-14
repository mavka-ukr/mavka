#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_break_node(MaMa* M,
                                         mavka::ast::BreakNode* break_node) {
    M->code.push_back(MaInstruction::jump(0));
    break_node->code_index = M->code.size() - 1;
    return success();
  }
} // namespace mavka::mama
