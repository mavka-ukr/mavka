#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_give_node(MaMa* M,
                                        mavka::ast::GiveNode* give_node) {
    for (const auto& element_node : give_node->elements) {
      M->code.push_back(
          MaInstruction::load(new MaLoadInstructionArgs(element_node->name)));
      if (element_node->as.empty()) {
        M->code.push_back(
            MaInstruction::give(new MaGiveInstructionArgs(element_node->name)));
      } else {
        M->code.push_back(
            MaInstruction::give(new MaGiveInstructionArgs(element_node->as)));
      }
    }
    return success();
  }
} // namespace mavka::mama