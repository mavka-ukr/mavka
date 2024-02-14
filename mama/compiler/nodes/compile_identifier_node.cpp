#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_identifier_node(
      MaMa* M,
      const mavka::ast::IdentifierNode* identifier_node) {
    if (identifier_node->name == "пусто") {
      M->code.push_back(MaInstruction::empty());
    } else if (identifier_node->name == "так") {
      M->code.push_back(MaInstruction::yes());
    } else if (identifier_node->name == "ні") {
      M->code.push_back(MaInstruction::no());
    } else {
      M->code.push_back(MaInstruction::load(
          new MaLoadInstructionArgs(identifier_node->name)));
    }
    return success();
  }
} // namespace mavka::mama