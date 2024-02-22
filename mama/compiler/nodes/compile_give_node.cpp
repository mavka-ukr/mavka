#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_give_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::ASTValue* ast_value) {
    const auto give_node = ast_value->data.GiveNode;
    for (const auto& element_node : give_node->elements) {
      code->instructions.push_back(
          MaInstruction::load(new MaLoadInstructionArgs(element_node->name)));
      if (element_node->as.empty()) {
        code->instructions.push_back(
            MaInstruction::give(new MaGiveInstructionArgs(element_node->name)));
      } else {
        code->instructions.push_back(
            MaInstruction::give(new MaGiveInstructionArgs(element_node->as)));
      }
    }
    return success();
  }
} // namespace mavka::mama