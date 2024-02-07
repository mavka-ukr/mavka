#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_module_node(
      MaCode* C,
      const mavka::ast::ModuleNode* module_node) {
    const auto jump_out_of_module_instruction = new MaInstruction(OP_JUMP);
    C->instructions.push_back(jump_out_of_module_instruction);

    const auto module_index = C->instructions.size();

    const auto body_result = compile_body(C, module_node->body);
    if (body_result->error) {
      return body_result;
    }
    C->instructions.push_back(MaInstruction::create_load("пусто"));
    C->instructions.push_back(new MaInstruction(OP_RETURN));

    jump_out_of_module_instruction->numval = C->instructions.size();
    C->instructions.push_back(
        new MaInstruction(OP_MODULE, module_index, module_node->name));

    return success();
  }
} // namespace mavka::mama