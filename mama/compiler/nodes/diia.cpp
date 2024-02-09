#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_diia(
      MaMa* M,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    M->code.push_back(MaInstruction{OP_JUMP});
    const auto jump_out_of_diia_body_instruction_index = M->code.size() - 1;

    const auto diia_index = M->code.size();

    const auto body_result = compile_body(M, body);
    if (body_result.error) {
      return body_result;
    }
    M->code.push_back(
        MaInstruction{OP_LOAD, {.load = new MaLoadInstructionArgs("пусто")}});
    M->code.push_back(MaInstruction{OP_RETURN});

    M->code[jump_out_of_diia_body_instruction_index].args.jump = M->code.size();

    M->code.push_back(MaInstruction{
        OP_DIIA, {.diia = new MaDiiaInstructionArgs(diia_index, name)}});
    for (const auto& param : params) {
      if (param->variadic) {
        return error(ast::make_ast_some(param),
                     "Варіативні параметри наразі не підтримуються.");
      }
      if (param->value) {
        const auto value_result = compile_node(M, param->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        M->code.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs("пусто")}});
      }
      M->code.push_back(MaInstruction{
          OP_DIIA_PARAM,
          {.diiaparam = new MaDiiaParamInstructionArgs(param->name)}});
    }

    return success();
  }

  MaCompilationResult compile_method(
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