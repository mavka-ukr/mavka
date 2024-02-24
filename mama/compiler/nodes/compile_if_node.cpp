#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_if_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::ASTValue* ast_value) {
    const auto if_node = ast_value->data.IfNode;
    const auto condition_result = compile_node(M, code, if_node->condition);
    if (condition_result.error) {
      return condition_result;
    }
    code->instructions.push_back(MaInstruction::jumpiffalse(0));
    const auto jump_if_instruction_index = code->instructions.size() - 1;
    const auto body_result = compile_body(M, code, if_node->body);
    if (body_result.error) {
      return body_result;
    }
    code->instructions.push_back(MaInstruction::jump(0));
    const auto jump_out_else_instruction_index = code->instructions.size() - 1;
    code->instructions[jump_if_instruction_index].args.jumpiffalse =
        code->instructions.size();
    const auto else_body_result = compile_body(M, code, if_node->else_body);
    if (else_body_result.error) {
      return else_body_result;
    }
    code->instructions[jump_out_else_instruction_index].args.jump =
        code->instructions.size();
    return success();
  }
} // namespace mavka::mama