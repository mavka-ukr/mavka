#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_while_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto while_node = ast_value->data.WhileNode;
    std::vector<EachNodeJumps> jumps;
    find_each_node_jumps(M, code, while_node->body, jumps);

    const auto continue_index = code->instructions.size();
    const auto condition_result = compile_node(M, code, while_node->condition);
    if (condition_result.error) {
      return condition_result;
    }
    code->instructions.push_back(MaInstruction::jumpiffalse(0));
    const auto jump_if_false_instruction_index = code->instructions.size() - 1;
    const auto body_result = compile_body(M, code, while_node->body);
    if (body_result.error) {
      return body_result;
    }
    code->instructions.push_back(MaInstruction::jump(continue_index));
    const auto break_index = code->instructions.size();
    code->instructions[jump_if_false_instruction_index].args.jumpiffalse =
        break_index;
    for (const auto& jump : jumps) {
      if (jump.continue_node) {
        code->instructions[jump.continue_node->code_index].args.jump =
            continue_index;
      } else if (jump.break_node) {
        code->instructions[jump.break_node->code_index].args.jump = break_index;
      }
    }
    return success();
  }
} // namespace mavka::mama