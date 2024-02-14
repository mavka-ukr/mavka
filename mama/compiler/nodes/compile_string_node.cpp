#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_string_node(
      MaMa* M,
      const mavka::ast::StringNode* string_node) {
    M->constants.push_back(create_string(M, string_node->value));
    M->code.push_back(MaInstruction::constant(M->constants.size() - 1));
    return success();
  }
} // namespace mavka::mama