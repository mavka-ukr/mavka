#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_number_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::NumberNode* number_node) {
    code->instructions.push_back(MaInstruction::number(std::stod(number_node->value)));
    return success();
  }
} // namespace mavka::mama