#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_get_element_node(
      MaMa* M,
      const mavka::ast::GetElementNode* get_element_node) {
    const auto left = compile_node(M, get_element_node->value);
    if (left.error) {
      return left;
    }
    const auto right = compile_node(M, get_element_node->index);
    if (right.error) {
      return right;
    }
    M->code.push_back(MaInstruction{OP_GET_ELEMENT});
    return success();
  }
} // namespace mavka::mama