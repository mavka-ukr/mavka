#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_bitwise_not_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::BitwiseNotNode* bitwise_not_node) {
    const auto result = compile_node(M, code, bitwise_not_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::bnot());
    return success();
  }
} // namespace mavka::mama
