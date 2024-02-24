#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_diia(MaMa* M,
                                   MaCode* code,
                                   bool async,
                                   const std::vector<ast::ASTValue*>& generics,
                                   const std::string& name,
                                   const std::vector<ast::ASTValue*>& params,
                                   const ast::ASTValue* return_types,
                                   const std::vector<ast::ASTValue*>& body) {
    const auto diia_code = new MaCode();
    diia_code->path = code->path;
    const auto body_result = compile_body(M, diia_code, body);
    if (body_result.error) {
      return body_result;
    }
    diia_code->instructions.push_back(MaInstruction::empty());
    diia_code->instructions.push_back(MaInstruction::return_());

    code->instructions.push_back(
        MaInstruction::diia(new MaDiiaInstructionArgs(diia_code, name)));
    for (const auto& param : params) {
      if (param->data.ParamNode->variadic) {
        return error(param, "Варіативні параметри наразі не підтримуються.");
      }
      if (param->data.ParamNode->value) {
        const auto value_result =
            compile_node(M, code, param->data.ParamNode->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        code->instructions.push_back(MaInstruction::empty());
      }
      code->instructions.push_back(MaInstruction::diiaparam(
          new MaDiiaParamInstructionArgs(param->data.ParamNode->name)));
    }
    return success();
  }

  MaCompilationResult compile_method(
      MaMa* M,
      MaCode* code,
      const std::string& structure,
      bool ee,
      bool async,
      const std::vector<ast::ASTValue*>& generics,
      const std::string& name,
      const std::vector<ast::ASTValue*>& params,
      const ast::ASTValue* return_types,
      const std::vector<ast::ASTValue*>& body) {
    code->instructions.push_back(
        MaInstruction::load(new MaLoadInstructionArgs(structure)));
    const auto result = compile_diia(M, code, async, generics, name, params,
                                     return_types, body);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::structmethod());
    return success();
  }
} // namespace mavka::mama