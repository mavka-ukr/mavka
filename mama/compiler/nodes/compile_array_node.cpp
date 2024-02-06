#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_array_node(MaCode* C,
                                          mavka::ast::ArrayNode* array_node) {
    C->instructions.push_back(new MaInstruction(OP_LIST));
    for (auto& element : array_node->elements) {
      const auto result = compile_node(C, element);
      if (result->error) {
        return result;
      }
      C->instructions.push_back(new MaInstruction(OP_LIST_APPEND));
    }
    return success();
  }
} // namespace mavka::mama
