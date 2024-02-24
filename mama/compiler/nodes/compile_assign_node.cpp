#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto assign_simple_node = ast_value->data.AssignNode;
    const auto result = compile_node(M, code, assign_simple_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::store(
        new MaStoreInstructionArgs(assign_simple_node->name)));
    return success();
  }
} // namespace mavka::mama
