#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_bitwise_not_node(
      MaCode* C,
      mavka::ast::BitwiseNotNode* bitwise_not_node) {
    C->instructions.push_back(new MaInstruction(OP_BNOT));
    return success();
  }
} // namespace mavka::mama
