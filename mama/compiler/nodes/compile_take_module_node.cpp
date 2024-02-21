#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_take_module_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::TakeModuleNode* take_module_node) {
    const auto name = take_module_node->name;
    const auto path = M->cwd + "/" + name + ".м";
    code->instructions.push_back(MaInstruction::take(
        new MaTakeInstructionArgs(code->instructions.size() + 1, path)));
    if (take_module_node->elements.empty()) {
      if (take_module_node->as.empty()) {
        code->instructions.push_back(
            MaInstruction::store(new MaStoreInstructionArgs(name)));
      } else {
        code->instructions.push_back(MaInstruction::store(
            new MaStoreInstructionArgs(take_module_node->as)));
      }
    } else {
      for (const auto element : take_module_node->elements) {
        code->instructions.push_back(MaInstruction::moduleload(
            new MaModuleLoadInstructionArgs(element.first, element.second)));
      }
    }
    return success();
  }
} // namespace mavka::mama