#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_negative_node(
      MaCode* C,
      mavka::ast::NegativeNode* negative_node) {
    const auto result = compile_node(C, negative_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_NEGATIVE));
    return success();
  }
} // namespace mavka::mama