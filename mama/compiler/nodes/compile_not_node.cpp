#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_not_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value) {
    const auto not_node = ast_value->data.NotNode;
    const auto result = compile_node(M, code, not_node->value);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::not_());
    return success();
  }
} // namespace mavka::mama