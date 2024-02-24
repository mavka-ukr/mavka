#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_continue_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto continue_node = ast_value->data.ContinueNode;
    code->instructions.push_back(MaInstruction::jump(0));
    continue_node->code_index = code->instructions.size() - 1;
    return success();
  }
} // namespace mavka::mama
