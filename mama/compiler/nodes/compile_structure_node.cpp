#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_structure_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto structure_node = ast_value->data.StructureNode;
    if (structure_node->parent) {
      return error(ast_value, "Наслідування структур тимчасово недоступне.");
    }
    code->instructions.push_back(MaInstruction::struct_(
        new MaStructInstructionArgs(structure_node->name)));
    for (const auto& param : structure_node->params) {
      if (param->data.ParamNode->value) {
        const auto value_result =
            compile_node(M, code, param->data.ParamNode->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        code->instructions.push_back(MaInstruction::empty());
      }
      if (param->data.ParamNode->ee) {
        code->instructions.push_back(MaInstruction{
            VESetR,
            {.set = new MaSetInstructionArgs(param->data.ParamNode->name)}});
      } else {
        code->instructions.push_back(MaInstruction::structparam(
            new MaStructParamInstructionArgs(param->data.ParamNode->name)));
      }
    }
    code->instructions.push_back(
        MaInstruction::store(new MaStoreInstructionArgs(structure_node->name)));
    return success();
  }
} // namespace mavka::mama