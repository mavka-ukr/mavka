#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_identifier_node(
      MaMa* M,
      const mavka::ast::IdentifierNode* identifier_node) {
    M->code.push_back(MaInstruction{
        OP_LOAD, {.load = new MaLoadInstructionArgs(identifier_node->name)}});
    return success();
  }
} // namespace mavka::mama