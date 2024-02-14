#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_by_identifier_node(
      MaMa* M,
      mavka::ast::AssignByIdentifierNode* assign_by_identifier_node) {
    if (assign_by_identifier_node->op == "=") {
      const auto value_result =
          compile_node(M, assign_by_identifier_node->value);
      if (value_result.error) {
        return value_result;
      }
      const auto result = compile_node(M, assign_by_identifier_node->left);
      if (result.error) {
        return result;
      }
      M->code.push_back(
          MaInstruction{OP_SET,
                        {.set = new MaSetInstructionArgs(
                             assign_by_identifier_node->identifier)}});
      return success();
    }
    return error(mavka::ast::make_ast_some(assign_by_identifier_node),
                 "Вказівка \"" + assign_by_identifier_node->op +
                     "\" тимчасово недоступна.");
  }
} // namespace mavka::mama
