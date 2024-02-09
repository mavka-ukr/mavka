#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_if_node(MaMa* M,
                                       const mavka::ast::IfNode* if_node) {
    const auto condition_result = compile_node(M, if_node->condition);
    if (condition_result->error) {
      return condition_result;
    }
    M->instructions.push_back(MaInstruction{OP_JUMP_IF_FALSE});
    const auto jump_if_instruction_index = M->instructions.size() - 1;
    const auto body_result = compile_body(M, if_node->body);
    if (body_result->error) {
      return body_result;
    }
    M->instructions.push_back(MaInstruction{OP_JUMP});
    const auto jump_out_else_instruction_index = M->instructions.size() - 1;
    M->instructions[jump_if_instruction_index].args.jumpiffalse =
        M->instructions.size();
    const auto else_body_result = compile_body(M, if_node->else_body);
    if (else_body_result->error) {
      return else_body_result;
    }
    M->instructions[jump_out_else_instruction_index].args.jump =
        M->instructions.size();
    return success();
  }
} // namespace mavka::mama