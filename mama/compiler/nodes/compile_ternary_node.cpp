#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_ternary_node(
      MaMa* M,
      mavka::ast::TernaryNode* ternary_node) {
    const auto condition_result = compile_node(M, ternary_node->condition);
    if (condition_result.error) {
      return condition_result;
    }
    M->code.push_back(MaInstruction::jumpiffalse(0));
    const auto jump_if_instruction_index = M->code.size() - 1;
    const auto body_result = compile_node(M, ternary_node->body);
    if (body_result.error) {
      return body_result;
    }
    M->code.push_back(MaInstruction::jump(0));
    const auto jump_out_else_instruction_index = M->code.size() - 1;
    M->code[jump_if_instruction_index].args.jumpiffalse = M->code.size();
    const auto else_body_result = compile_node(M, ternary_node->else_body);
    if (else_body_result.error) {
      return else_body_result;
    }
    M->code[jump_out_else_instruction_index].args.jump = M->code.size();
    return success();
  }
} // namespace mavka::mama