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
    M->code.push_back(MaInstruction::jump(0));
    const auto jump_out_of_diia_body_instruction_index = M->code.size() - 1;

    const auto diia_index = M->code.size();

    const auto body_result = compile_body(M, body);
    if (body_result.error) {
      return body_result;
    }
    M->code.push_back(MaInstruction::empty());
    M->code.push_back(MaInstruction::return_());

    M->code[jump_out_of_diia_body_instruction_index].args.jump = M->code.size();

    M->code.push_back(
        MaInstruction::diia(new MaDiiaInstructionArgs(diia_index, name)));
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
        M->code.push_back(MaInstruction::empty());
      }
      M->code.push_back(MaInstruction::diiaparam(
          new MaDiiaParamInstructionArgs(param->name)));
    }
    return success();
  }

  MaCompilationResult compile_method(
      MaMa* M,
      const std::string& structure,
      bool ee,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    M->code.push_back(
        MaInstruction::load(new MaLoadInstructionArgs(structure)));
    const auto result =
        compile_diia(M, async, generics, name, params, return_types, body);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction::structmethod());
    return success();
  }
} // namespace mavka::mama