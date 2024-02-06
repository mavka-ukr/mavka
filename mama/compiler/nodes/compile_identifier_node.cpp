#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_identifier_node(
      MaCode* C,
      mavka::ast::IdentifierNode* identifier_node) {
    C->instructions.push_back(
        MaInstruction::create_load(identifier_node->name));
    return success();
  }
} // namespace mavka::mama