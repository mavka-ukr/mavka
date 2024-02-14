#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_positive_node(
      MaMa* M,
      const mavka::ast::PositiveNode* positive_node) {
    const auto result = compile_node(M, positive_node->value);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction::positive());
    return success();
  }
} // namespace mavka::mama