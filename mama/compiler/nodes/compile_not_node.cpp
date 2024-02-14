#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_not_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::NotNode* not_node) {
    const auto result = compile_node(M, code, not_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction{OP_NOT});
    return success();
  }
} // namespace mavka::mama