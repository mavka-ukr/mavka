#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_by_identifier_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto assign_by_identifier_node =
        ast_value->data.AssignByIdentifierNode;
    const auto value_result =
        compile_node(M, code, assign_by_identifier_node->value);
    if (value_result.error) {
      return value_result;
    }
    const auto result = compile_node(M, code, assign_by_identifier_node->left);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::set(
        new MaSetInstructionArgs(assign_by_identifier_node->identifier)));
    return success();
  }
} // namespace mavka::mama
