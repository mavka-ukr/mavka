#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_positive_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto positive_node = ast_value->data.PositiveNode;
    const auto result = compile_node(M, code, positive_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::positive());
    return success();
  }
} // namespace mavka::mama