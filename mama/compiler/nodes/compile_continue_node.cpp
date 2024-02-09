#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_continue_node(
      MaMa* M,
      mavka::ast::ContinueNode* continue_node) {
    // todo: find the loop and jump to the beginning of the loop
    return success();
  }
} // namespace mavka::mama
