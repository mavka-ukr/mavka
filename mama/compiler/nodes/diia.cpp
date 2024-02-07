#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_diia(
      MaCode* C,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    const auto jump_out_of_diia_instruction = new MaInstruction(OP_JUMP);
    C->instructions.push_back(jump_out_of_diia_instruction);

    const auto diia_index = C->instructions.size();

    for (int i = 0; i < params.size(); ++i) {
      const auto param = params[i];
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
    const auto body_result = compile_body(C, body);
    if (body_result->error) {
      return body_result;
    }
    C->instructions.push_back(MaInstruction::create_load("пусто"));
    C->instructions.push_back(new MaInstruction(OP_RETURN));

    jump_out_of_diia_instruction->numval = C->instructions.size();

    C->instructions.push_back(
        new MaInstruction(OP_PUSH_DIIA, diia_index, name));

    return success();
  }
} // namespace mavka::mama