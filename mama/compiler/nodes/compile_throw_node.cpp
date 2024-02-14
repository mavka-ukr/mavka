#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_throw_node(
      MaMa* M,
      const mavka::ast::ThrowNode* throw_node) {
    const auto result = compile_node(M, throw_node->value);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction::throw_());
    return success();
  }
} // namespace mavka::mama