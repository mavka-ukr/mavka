#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_structure_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::StructureNode* structure_node) {
    if (structure_node->parent) {
      return error(mavka::ast::make_ast_some(structure_node),
                   "Наслідування структур тимчасово недоступне.");
    }
    code->instructions.push_back(MaInstruction{
        OP_STRUCT,
        {.struct_ = new MaStructInstructionArgs(structure_node->name)}});
    for (const auto& param : structure_node->params) {
      if (param->value) {
        const auto value_result = compile_node(M, code, param->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        code->instructions.push_back(MaInstruction{OP_EMPTY});
      }
      if (param->ee) {
        code->instructions.push_back(MaInstruction{
            OP_E_SETR, {.set = new MaSetInstructionArgs(param->name)}});
      } else {
        code->instructions.push_back(MaInstruction{
            OP_STRUCT_PARAM,
            {.structparam = new MaStructParamInstructionArgs(param->name)}});
      }
    }
    code->instructions.push_back(MaInstruction{
        OP_STORE, {.store = new MaStoreInstructionArgs(structure_node->name)}});
    return success();
  }
} // namespace mavka::mama