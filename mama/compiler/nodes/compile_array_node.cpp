#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_array_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ArrayNode* array_node) {
    code->instructions.push_back(MaInstruction{OP_LIST});
    for (auto& element : array_node->elements) {
      const auto result = compile_node(M, code, element);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(MaInstruction{OP_LIST_APPEND});
    }
    return success();
  }
} // namespace mavka::mama
