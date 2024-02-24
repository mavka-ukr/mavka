#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_diia_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::ASTValue* ast_value) {
    const auto diia_node = ast_value->data.DiiaNode;
    if (diia_node->structure.empty()) {
      const auto result = compile_diia(
          M, code, diia_node->async, diia_node->generics, diia_node->name,
          diia_node->params, diia_node->return_types, diia_node->body);
      if (result.error) {
        return result;
      }
      if (diia_node->anonymous) {
      } else {
        if (diia_node->name.empty()) {
          return error(ast_value, "Не вказано назву дії.");
        }
        code->instructions.push_back(
            MaInstruction::store(new MaStoreInstructionArgs(diia_node->name)));
      }
    } else {
      if (diia_node->ee) {
        const auto result = compile_diia(
            M, code, diia_node->async, diia_node->generics, diia_node->name,
            diia_node->params, diia_node->return_types, diia_node->body);
        if (result.error) {
          return result;
        }
        code->instructions.push_back(MaInstruction::load(
            new MaLoadInstructionArgs(diia_node->structure)));
        code->instructions.push_back(
            MaInstruction::set(new MaSetInstructionArgs(diia_node->name)));
      } else {
        const auto result = compile_method(
            M, code, diia_node->structure, diia_node->ee, diia_node->async,
            diia_node->generics, diia_node->name, diia_node->params,
            diia_node->return_types, diia_node->body);
        if (result.error) {
          return result;
        }
      }
    }

    return success();
  }
} // namespace mavka::mama