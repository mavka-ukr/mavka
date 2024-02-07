#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_throw_node(
      MaCode* C,
      const mavka::ast::ThrowNode* throw_node) {
    const auto result = compile_node(C, throw_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_THROW));
    return success();
  }
} // namespace mavka::mama