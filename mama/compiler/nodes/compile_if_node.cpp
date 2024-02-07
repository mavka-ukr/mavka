#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_if_node(MaCode* C,
                                       const mavka::ast::IfNode* if_node) {
    const auto condition_result = compile_node(C, if_node->condition);
    if (condition_result->error) {
      return condition_result;
    }
    const auto jump_if_instruction = new MaInstruction(OP_JUMP_IF_FALSE, 0);
    C->instructions.push_back(jump_if_instruction);
    const auto body_result = compile_body(C, if_node->body);
    if (body_result->error) {
      return body_result;
    }
    const auto jump_out_else_instruction = new MaInstruction(OP_JUMP, 0);
    C->instructions.push_back(jump_out_else_instruction);
    jump_if_instruction->numval = C->instructions.size();
    const auto else_body_result = compile_body(C, if_node->else_body);
    if (else_body_result->error) {
      return else_body_result;
    }
    jump_out_else_instruction->numval = C->instructions.size();
    return success();
  }
} // namespace mavka::mama