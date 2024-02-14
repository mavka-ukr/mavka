#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_negative_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::NegativeNode* negative_node) {
    const auto result = compile_node(M, code, negative_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction{OP_NEGATIVE});
    return success();
  }
} // namespace mavka::mama