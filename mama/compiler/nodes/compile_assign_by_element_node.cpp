#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_by_element_node(
      MaMa* M,
      mavka::ast::AssignByElementNode* assign_by_element_node) {
    if (assign_by_element_node->op == "=") {
      const auto left = compile_node(M, assign_by_element_node->left);
      if (left.error) {
        return left;
      }
      const auto right = compile_node(M, assign_by_element_node->element);
      if (right.error) {
        return right;
      }
      const auto value_result = compile_node(M, assign_by_element_node->value);
      if (value_result.error) {
        return value_result;
      }
      M->code.push_back(MaInstruction{OP_SET_ELEMENT});
      return success();
    }
    return error(mavka::ast::make_ast_some(assign_by_element_node),
                 "Not implemented");
  }
} // namespace mavka::mama
