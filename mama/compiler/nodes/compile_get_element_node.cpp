#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_get_element_node(
      MaCode* C,
      const mavka::ast::GetElementNode* get_element_node) {
    const auto key_result = compile_node(C, get_element_node->index);
    if (key_result->error) {
      return key_result;
    }
    const auto value_result = compile_node(C, get_element_node->value);
    if (value_result->error) {
      return value_result;
    }
    C->instructions.push_back(new MaInstruction(OP_GET_ELEMENT));
    return success();
  }
} // namespace mavka::mama