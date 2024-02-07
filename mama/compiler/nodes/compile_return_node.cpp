#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_return_node(
      MaCode* C,
      const mavka::ast::ReturnNode* return_node) {
    const auto result = compile_node(C, return_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_RETURN));
    return success();
  }
} // namespace mavka::mama