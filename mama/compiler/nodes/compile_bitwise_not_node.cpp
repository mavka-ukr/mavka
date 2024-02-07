#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_bitwise_not_node(
      MaCode* C,
      mavka::ast::BitwiseNotNode* bitwise_not_node) {
    const auto result = compile_node(C, bitwise_not_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_BNOT));
    return success();
  }
} // namespace mavka::mama
