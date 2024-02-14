#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_return_node(
      MaMa* M,
      const mavka::ast::ReturnNode* return_node) {
    const auto result = compile_node(M, return_node->value);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction::return_());
    return success();
  }
} // namespace mavka::mama