#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_while_node(MaCode* C,
                                          mavka::ast::WhileNode* while_node) {
    const auto initial_jump = C->instructions.size();
    const auto condition_result = compile_node(C, while_node->condition);
    if (condition_result->error) {
      return condition_result;
    }
    const auto jump_if_false_instruction =
        new MaInstruction(OP_JUMP_IF_FALSE, 0);
    C->instructions.push_back(jump_if_false_instruction);
    const auto body_result = compile_body(C, while_node->body);
    if (body_result->error) {
      return body_result;
    }
    const auto jump_back_instruction = new MaInstruction(OP_JUMP, initial_jump);
    C->instructions.push_back(jump_back_instruction);
    jump_if_false_instruction->numval = C->instructions.size();
    return success();
  }
} // namespace mavka::mama