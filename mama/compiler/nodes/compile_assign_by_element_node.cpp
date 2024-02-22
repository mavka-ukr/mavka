#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_by_element_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto assign_by_element_node = ast_value->data.AssignByElementNode;
    const auto call_node = new mavka::ast::CallNode();
    const auto value_chain_node = new mavka::ast::ChainNode();
    value_chain_node->left = assign_by_element_node->left;
    value_chain_node->right = new ast::IdentifierNode();
    value_chain_node->right->name = MAG_SET_ELEMENT;
    call_node->value = ast::make_ast_some(value_chain_node);
    const auto element_arg_node = new ast::Arg();
    element_arg_node->index = 0;
    element_arg_node->value = assign_by_element_node->element;
    const auto value_arg_node = new ast::Arg();
    value_arg_node->index = 1;
    value_arg_node->value = assign_by_element_node->value;
    call_node->args = {element_arg_node, value_arg_node};
    return compile_call_node(M, code, call_node);
  }
} // namespace mavka::mama
