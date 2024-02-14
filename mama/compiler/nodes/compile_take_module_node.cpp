#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_take_module_node(
      MaMa* M,
      mavka::ast::TakeModuleNode* take_module_node) {
    const auto name = take_module_node->name;
    const auto path = M->cwd + "/" + name + ".м";
    M->code.push_back(MaInstruction{
        OP_TAKE,
        {.take = new MaTakeInstructionArgs(M->code.size() + 1, path)}});
    if (take_module_node->elements.empty()) {
      if (take_module_node->as.empty()) {
        M->code.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(name)}});
      } else {
        M->code.push_back(MaInstruction{
            OP_STORE,
            {.store = new MaStoreInstructionArgs(take_module_node->as)}});
      }
    } else {
      for (const auto element : take_module_node->elements) {
        M->code.push_back(
            MaInstruction{OP_MODULE_LOAD,
                          {.moduleload = new MaModuleLoadInstructionArgs(
                               element.first, element.second)}});
      }
    }
    return success();
  }
} // namespace mavka::mama