#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_while_node(
      MaMa* M,
      const mavka::ast::WhileNode* while_node) {
    std::vector<EachNodeJumps> jumps;
    find_each_node_jumps(M, while_node->body, jumps);

    const auto continue_index = M->code.size();
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
    M->code.push_back(MaInstruction{OP_JUMP, {.jump = continue_index}});
    const auto break_index = M->code.size();
    M->code[jump_if_false_instruction_index].args.jumpiffalse = break_index;
    for (const auto& jump : jumps) {
      if (jump.continue_node) {
        M->code[jump.continue_node->code_index].args.jump = continue_index;
      } else if (jump.break_node) {
        M->code[jump.break_node->code_index].args.jump = break_index;
      }
    }
    return success();
  }
} // namespace mavka::mama