#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_return_node(
      MaMa* M,
      const mavka::ast::ReturnNode* return_node) {
    const auto result = compile_node(M, return_node->value);
    if (result->error) {
      return result;
    }
    M->instructions.push_back(MaInstruction{OP_RETURN});
    return success();
  }
} // namespace mavka::mama