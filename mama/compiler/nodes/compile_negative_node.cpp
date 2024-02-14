#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_negative_node(
      MaMa* M,
      const mavka::ast::NegativeNode* negative_node) {
    const auto result = compile_node(M, negative_node->value);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction::negative());
    return success();
  }
} // namespace mavka::mama