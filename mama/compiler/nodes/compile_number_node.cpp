#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_number_node(
      MaMa* M,
      const mavka::ast::NumberNode* number_node) {
    const auto number_cell =
        new MaCell(MA_CELL_NUMBER, {.number = std::stod(number_node->value)});
    M->instructions.push_back(
        MaInstruction{OP_CONSTANT, {.constant = number_cell}});
    return success();
  }
} // namespace mavka::mama