#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_get_element_node(
      MaMa* M,
      const mavka::ast::GetElementNode* get_element_node) {
    const auto key_result = compile_node(M, get_element_node->index);
    if (key_result->error) {
      return key_result;
    }
    const auto value_result = compile_node(M, get_element_node->value);
    if (value_result->error) {
      return value_result;
    }
    M->instructions.push_back(MaInstruction{OP_GET_ELEMENT});
    return success();
  }
} // namespace mavka::mama