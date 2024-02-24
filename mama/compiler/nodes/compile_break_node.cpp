#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_break_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto break_node = ast_value->data.BreakNode;
    code->instructions.push_back(MaInstruction::jump(0));
    break_node->code_index = code->instructions.size() - 1;
    return success();
  }
} // namespace mavka::mama
