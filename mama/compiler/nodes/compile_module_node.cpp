#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_module_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto module_node = ast_value->data.ModuleNode;
    const auto module_code = new MaCode();
    module_code->path = code->path;
    const auto body_result = compile_body(M, module_code, module_node->body);
    if (body_result.error) {
      return body_result;
    }
    code->instructions.push_back(MaInstruction::module(
        new MaModuleInstructionArgs(module_code, module_node->name)));
    return success();
  }
} // namespace mavka::mama