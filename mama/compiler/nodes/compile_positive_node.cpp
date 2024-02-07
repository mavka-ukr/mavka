#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_positive_node(
      MaCode* C,
      const mavka::ast::PositiveNode* positive_node) {
    const auto result = compile_node(C, positive_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_POSITIVE));
    return success();
  }
} // namespace mavka::mama