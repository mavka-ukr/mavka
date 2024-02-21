#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_return_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ReturnNode* return_node) {
    const auto result = compile_node(M, code, return_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::return_());
    return success();
  }
} // namespace mavka::mama