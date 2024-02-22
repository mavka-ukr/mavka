#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_negative_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto negative_node = ast_value->data.NegativeNode;
    const auto result = compile_node(M, code, negative_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::negative());
    return success();
  }
} // namespace mavka::mama