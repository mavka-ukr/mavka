#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_give_node(
      MaCode* C,
      const mavka::ast::GiveNode* give_node) {
    for (const auto& element : give_node->elements) {
      C->instructions.push_back(new MaInstruction(OP_LOAD, 0, element->name));
      if (element->as.empty()) {
        C->instructions.push_back(new MaInstruction(OP_GIVE, 0, element->name));
      } else {
        C->instructions.push_back(new MaInstruction(OP_GIVE, 0, element->as));
      }
    }
    return success();
  }
} // namespace mavka::mama