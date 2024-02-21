#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_module_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ModuleNode* module_node) {
    code->instructions.push_back(
        MaInstruction::module(new MaModuleInstructionArgs(module_node->name)));
    const auto body_result = compile_body(M, code, module_node->body);
    if (body_result.error) {
      return body_result;
    }
    code->instructions.push_back(MaInstruction::moduledone());
    return success();
  }
} // namespace mavka::mama