#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_array_node(
      MaMa* M,
      const mavka::ast::ArrayNode* array_node) {
    M->code.push_back(MaInstruction{OP_LIST});
    for (auto& element : array_node->elements) {
      const auto result = compile_node(M, element);
      if (result.error) {
        return result;
      }
      M->code.push_back(MaInstruction{OP_LIST_APPEND});
    }
    return success();
  }
} // namespace mavka::mama
