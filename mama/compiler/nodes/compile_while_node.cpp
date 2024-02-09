#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_while_node(
      MaMa* M,
      const mavka::ast::WhileNode* while_node) {
    // const auto initial_jump = M->instructions.size();
    // const auto condition_result = compile_node(M, while_node->condition);
    // if (condition_result->error) {
    //   return condition_result;
    // }
    // const auto jump_if_false_instruction =
    //     new MaInstruction(OP_JUMP_IF_FALSE, 0);
    // M->instructions.push_back(jump_if_false_instruction);
    // const auto body_result = compile_body(M, while_node->body);
    // if (body_result->error) {
    //   return body_result;
    // }
    // const auto jump_back_instruction = new MaInstruction(OP_JUMP,
    // initial_jump); M->instructions.push_back(jump_back_instruction);
    // jump_if_false_instruction->numval = M->instructions.size();
    return success();
  }
} // namespace mavka::mama