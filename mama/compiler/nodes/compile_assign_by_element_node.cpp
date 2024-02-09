#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_assign_by_element_node(
      MaMa* M,
      mavka::ast::AssignByElementNode* assign_by_element_node) {
    if (assign_by_element_node->op == "=") {
      const auto key_result = compile_node(M, assign_by_element_node->element);
      if (key_result->error) {
        return key_result;
      }
      const auto value_result = compile_node(M, assign_by_element_node->value);
      if (value_result->error) {
        return value_result;
      }
      const auto result = compile_node(M, assign_by_element_node->left);
      if (result->error) {
        return result;
      }
      M->instructions.push_back(MaInstruction{OP_SET_ELEMENT});
      return success();
    }
    return error(mavka::ast::make_ast_some(assign_by_element_node),
                 "Not implemented");
  }
} // namespace mavka::mama
