#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_while_node(
      MaMa* M,
      const mavka::ast::WhileNode* while_node) {
    const auto initial_jump = M->code.size();
    const auto condition_result = compile_node(M, while_node->condition);
    if (condition_result.error) {
      return condition_result;
    }
    M->code.push_back(MaInstruction{OP_JUMP_IF_FALSE});
    const auto jump_if_false_instruction_index = M->code.size() - 1;
    const auto body_result = compile_body(M, while_node->body);
    if (body_result.error) {
      return body_result;
    }
    M->code.push_back(MaInstruction{OP_JUMP, {.jump = initial_jump}});
    M->code[jump_if_false_instruction_index].args.jumpiffalse = M->code.size();
    return success();
  }
} // namespace mavka::mama