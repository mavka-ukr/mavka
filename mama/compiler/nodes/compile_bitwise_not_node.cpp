#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_bitwise_not_node(
      MaMa* M,
      const mavka::ast::BitwiseNotNode* bitwise_not_node) {
    const auto result = compile_node(M, bitwise_not_node->value);
    if (result->error) {
      return result;
    }
    M->instructions.push_back(MaInstruction{OP_BNOT});
    return success();
  }
} // namespace mavka::mama
