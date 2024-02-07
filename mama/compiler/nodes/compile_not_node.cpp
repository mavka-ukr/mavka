#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_not_node(MaCode* C,
                                        const mavka::ast::NotNode* not_node) {
    const auto result = compile_node(C, not_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_NOT));
    return success();
  }
} // namespace mavka::mama