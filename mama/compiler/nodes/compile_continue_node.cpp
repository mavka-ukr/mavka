#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_continue_node(
      MaCode* C,
      mavka::ast::ContinueNode* continue_node) {
    C->instructions.push_back(new MaInstruction(OP_CONTINUE));
    return success();
  }
} // namespace mavka::mama
