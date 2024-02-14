#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_module_node(
      MaMa* M,
      const mavka::ast::ModuleNode* module_node) {
    M->code.push_back(
        MaInstruction::module(new MaModuleInstructionArgs(module_node->name)));
    const auto body_result = compile_body(M, module_node->body);
    if (body_result.error) {
      return body_result;
    }
    M->code.push_back(MaInstruction::moduledone());
    return success();
  }
} // namespace mavka::mama