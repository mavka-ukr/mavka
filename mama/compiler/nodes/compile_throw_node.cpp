#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_throw_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ThrowNode* throw_node) {
    const auto result = compile_node(M, code, throw_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction{OP_THROW});
    return success();
  }
} // namespace mavka::mama