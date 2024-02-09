#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_continue_node(
      MaMa* M,
      mavka::ast::ContinueNode* continue_node) {
    M->instructions.push_back(MaInstruction{OP_CONTINUE});
    return success();
  }
} // namespace mavka::mama
