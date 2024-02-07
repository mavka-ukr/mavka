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

    const auto body_result = compile_body(C, body);
    if (body_result->error) {
      return body_result;
    }
    C->instructions.push_back(MaInstruction::create_load("пусто"));
    C->instructions.push_back(new MaInstruction(OP_RETURN));

    jump_out_of_diia_instruction->numval = C->instructions.size();

    C->instructions.push_back(new MaInstruction(OP_DIIA, diia_index, name));
    for (int i = 0; i < params.size(); ++i) {
      const auto param = params[i];
      C->instructions.push_back(
          new MaInstruction(OP_DIIA_PARAM, i, param->name));
    }

    return success();
  }
} // namespace mavka::mama