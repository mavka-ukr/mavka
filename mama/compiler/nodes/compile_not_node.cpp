#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_not_node(MaMa* M,
                                       const mavka::ast::NotNode* not_node) {
    const auto result = compile_node(M, not_node->value);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction{OP_NOT});
    return success();
  }
} // namespace mavka::mama