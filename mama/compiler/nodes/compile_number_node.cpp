#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_number_node(
      MaCode* C,
      const mavka::ast::NumberNode* number_node) {
    C->instructions.push_back(
        new MaInstruction(OP_PUSH_NUMBER, std::stod(number_node->value)));
    return success();
  }
} // namespace mavka::mama