#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_structure_node(
      MaMa* M,
      mavka::ast::StructureNode* structure_node) {
    if (structure_node->parent) {
      return error(mavka::ast::make_ast_some(structure_node),
                   "Наслідування структур тимчасово недоступне.");
    }
    M->code.push_back(MaInstruction::struct_(
        new MaStructInstructionArgs(structure_node->name)));
    for (const auto& param : structure_node->params) {
      if (param->value) {
        const auto value_result = compile_node(M, param->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        M->code.push_back(MaInstruction::empty());
      }
      if (param->ee) {
        M->code.push_back(MaInstruction{
            OP_E_SETR, {.set = new MaSetInstructionArgs(param->name)}});
      } else {
        M->code.push_back(MaInstruction::structparam(
            new MaStructParamInstructionArgs(param->name)));
      }
    }
    M->code.push_back(
        MaInstruction::store(new MaStoreInstructionArgs(structure_node->name)));
    return success();
  }
} // namespace mavka::mama