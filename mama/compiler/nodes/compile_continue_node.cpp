#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_continue_node(
      MaMa* M,
      mavka::ast::ContinueNode* continue_node) {
    M->code.push_back(MaInstruction::jump(0));
    continue_node->code_index = M->code.size() - 1;
    return success();
  }
} // namespace mavka::mama
