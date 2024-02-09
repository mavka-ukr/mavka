#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_diia(
      MaMa* M,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    // const auto jump_out_of_diia_body_instruction = new
    // MaInstruction(OP_JUMP);
    // M->instructions.push_back(jump_out_of_diia_body_instruction);
    //
    // const auto diia_index = M->instructions.size();
    //
    // const auto body_result = compile_body(M, body);
    // if (body_result->error) {
    //   return body_result;
    // }
    // M->instructions.push_back(MaInstruction::create_load("пусто"));
    // M->instructions.push_back(new MaInstruction(OP_RETURN));
    //
    // jump_out_of_diia_body_instruction->numval = M->instructions.size();
    //
    // M->instructions.push_back(new MaInstruction(OP_DIIA, diia_index, name));
    // for (int i = 0; i < params.size(); ++i) {
    //   const auto param = params[i];
    //   M->instructions.push_back(
    //       new MaInstruction(OP_DIIA_PARAM, i, param->name));
    // }

    return success();
  }

  MaCompilationResult* compile_method(
      MaMa* M,
      const std::string& structure,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    // const auto jump_out_of_diia_instruction = new MaInstruction(OP_JUMP);
    // M->instructions.push_back(jump_out_of_diia_instruction);
    //
    // const auto diia_index = M->instructions.size();
    //
    // const auto body_result = compile_body(M, body);
    // if (body_result->error) {
    //   return body_result;
    // }
    // M->instructions.push_back(MaInstruction::create_load("пусто"));
    // M->instructions.push_back(new MaInstruction(OP_RETURN));
    //
    // jump_out_of_diia_instruction->numval = M->instructions.size();
    //
    // M->instructions.push_back(MaInstruction::create_load(structure));
    // M->instructions.push_back(new MaInstruction(OP_METHOD, diia_index,
    // name)); for (int i = 0; i < params.size(); ++i) {
    //   const auto param = params[i];
    //   M->instructions.push_back(
    //       new MaInstruction(OP_METHOD_PARAM, i, param->name));
    // }
    // M->instructions.push_back(new MaInstruction(OP_POP));

    return success();
  }
} // namespace mavka::mama