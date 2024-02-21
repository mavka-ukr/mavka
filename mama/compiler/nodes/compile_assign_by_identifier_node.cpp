#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_by_identifier_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::AssignByIdentifierNode* assign_by_identifier_node) {
    if (assign_by_identifier_node->op == "=") {
      const auto value_result =
          compile_node(M, code, assign_by_identifier_node->value);
      if (value_result.error) {
        return value_result;
      }
      const auto result =
          compile_node(M, code, assign_by_identifier_node->left);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(MaInstruction::set(
          new MaSetInstructionArgs(assign_by_identifier_node->identifier)));
      return success();
    }
    return error(mavka::ast::make_ast_some(assign_by_identifier_node),
                 "Вказівка \"" + assign_by_identifier_node->op +
                     "\" тимчасово недоступна.");
  }
} // namespace mavka::mama
