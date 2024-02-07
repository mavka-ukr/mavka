#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_string_node(
      MaCode* C,
      const mavka::ast::StringNode* string_node) {
    C->instructions.push_back(
        MaInstruction::create_push_string(string_node->value));
    return success();
  }
} // namespace mavka::mama