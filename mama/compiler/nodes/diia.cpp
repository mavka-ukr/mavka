#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_diia(
      MaMa* M,
      MaCode* code,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    const auto diia_code = new MaCode();
    M->diia_bodies.push_back(diia_code);
    const auto diia_code_index = M->diia_bodies.size() - 1;
    const auto body_result = compile_body(M, diia_code, body);
    if (body_result.error) {
      return body_result;
    }
    diia_code->instructions.push_back(MaInstruction{OP_EMPTY});
    diia_code->instructions.push_back(MaInstruction{OP_RETURN});
    diia_code->instructions.push_back(MaInstruction{
        OP_DIIA, {.diia = new MaDiiaInstructionArgs(diia_code_index, name)}});

    for (const auto& param : params) {
      if (param->variadic) {
        return error(ast::make_ast_some(param),
                     "Варіативні параметри наразі не підтримуються.");
      }
      if (param->value) {
        const auto value_result = compile_node(M, code, param->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        code->instructions.push_back(MaInstruction{OP_EMPTY});
      }
      code->instructions.push_back(MaInstruction{
          OP_DIIA_PARAM,
          {.diiaparam = new MaDiiaParamInstructionArgs(param->name)}});
    }
    return success();
  }

  MaCompilationResult compile_method(
      MaMa* M,
      MaCode* code,
      const std::string& structure,
      bool ee,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body) {
    code->instructions.push_back(
        MaInstruction{OP_LOAD, {.load = new MaLoadInstructionArgs(structure)}});
    const auto result = compile_diia(M, code, async, generics, name, params,
                                     return_types, body);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction{OP_STRUCT_METHOD});
    return success();
  }
} // namespace mavka::mama