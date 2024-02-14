#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_give_node(MaMa* M, MaCode* code,
                                        mavka::ast::GiveNode* give_node) {
    for (const auto& element_node : give_node->elements) {
      code->instructions.push_back(MaInstruction{
          OP_LOAD, {.load = new MaLoadInstructionArgs(element_node->name)}});
      if (element_node->as.empty()) {
        code->instructions.push_back(MaInstruction{
            OP_GIVE, {.give = new MaGiveInstructionArgs(element_node->name)}});
      } else {
        code->instructions.push_back(MaInstruction{
            OP_GIVE, {.give = new MaGiveInstructionArgs(element_node->as)}});
      }
    }
    return success();
  }
} // namespace mavka::mama