#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_diia_node(MaCode* C,
                                         mavka::ast::DiiaNode* diia_node) {
    const auto jump_out_of_diia_instruction = new MaInstruction(OP_JUMP);
    C->instructions.push_back(jump_out_of_diia_instruction);

    const auto diia_index = C->instructions.size() - 1;

    for (int i = 0; i < diia_node->params.size(); ++i) {
      const auto param = diia_node->params[i];
      if (param->value) {
        const auto value_result = compile_node(C, param->value);
        if (value_result->error) {
          return value_result;
        }
      }
      C->instructions.push_back(
          MaInstruction::create_load_param(i, param->name));
    }
    C->instructions.push_back(new MaInstruction(OP_CLEAR_ARGS));
    const auto body_result = compile_body(C, diia_node->body);
    if (body_result->error) {
      return body_result;
    }
    C->instructions.push_back(MaInstruction::create_load("пусто"));
    C->instructions.push_back(new MaInstruction(OP_RETURN));

    jump_out_of_diia_instruction->numval = C->instructions.size() - 1;

    C->instructions.push_back(
        new MaInstruction(OP_STORE_DIIA, diia_index, diia_node->name));

    return success();
  }
} // namespace mavka::mama