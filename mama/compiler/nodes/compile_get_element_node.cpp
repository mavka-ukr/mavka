#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_get_element_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::GetElementNode* get_element_node) {
    const auto call_node = new mavka::ast::CallNode();
    const auto value_chain_node = new mavka::ast::ChainNode();
    value_chain_node->left = get_element_node->value;
    value_chain_node->right = new ast::IdentifierNode();
    value_chain_node->right->name = MAG_GET_ELEMENT;
    call_node->value = ast::make_ast_some(value_chain_node);
    const auto element_arg_node = new ast::ArgNode();
    element_arg_node->index = 0;
    element_arg_node->value = get_element_node->index;
    call_node->args = {element_arg_node};
    return compile_call_node(M, code, call_node);
  }
} // namespace mavka::mama