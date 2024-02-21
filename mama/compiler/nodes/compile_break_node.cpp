#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_break_node(MaMa* M,
                                         MaCode* code,
                                         mavka::ast::BreakNode* break_node) {
    code->instructions.push_back(MaInstruction::jump(0));
    break_node->code_index = code->instructions.size() - 1;
    return success();
  }
} // namespace mavka::mama
