#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_structure_node(
      MaMa* M,
      const mavka::ast::StructureNode* structure_node) {
    M->code.push_back(MaInstruction{
        OP_STRUCT,
        {.struct_ = new MaStructInstructionArgs(structure_node->name)}});
    for (const auto& param : structure_node->params) {
      if (param->ee) {
        return error(ast::make_ast_some(param),
                     "Спец параметри наразі не підтримуються.");
      }
      if (param->value) {
        const auto value_result = compile_node(M, param->value);
        if (value_result.error) {
          return value_result;
        }
      } else {
        M->code.push_back(MaInstruction{OP_EMPTY});
      }
      M->code.push_back(MaInstruction{
          OP_STRUCT_PARAM,
          {.structparam = new MaStructParamInstructionArgs(param->name)}});
    }
    M->code.push_back(MaInstruction{
        OP_STORE, {.store = new MaStoreInstructionArgs(structure_node->name)}});
    return success();
  }
} // namespace mavka::mama