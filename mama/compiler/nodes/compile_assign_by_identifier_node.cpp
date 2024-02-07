#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_assign_by_identifier_node(
      MaCode* C,
      mavka::ast::AssignByIdentifierNode* assign_by_identifier_node) {
    if (assign_by_identifier_node->op == "=") {
      const auto value_result =
          compile_node(C, assign_by_identifier_node->value);
      if (value_result->error) {
        return value_result;
      }
      const auto result = compile_node(C, assign_by_identifier_node->left);
      if (result->error) {
        return result;
      }
      C->instructions.push_back(
          new MaInstruction(OP_SET, 0, assign_by_identifier_node->identifier));
      return success();
    }
    return error(mavka::ast::make_ast_some(assign_by_identifier_node),
                 "Not implemented");
  }
} // namespace mavka::mama
