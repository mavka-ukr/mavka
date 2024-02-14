#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_number_node(
      MaMa* M,
      const mavka::ast::NumberNode* number_node) {
    M->code.push_back(MaInstruction::number(std::stod(number_node->value)));
    return success();
  }
} // namespace mavka::mama