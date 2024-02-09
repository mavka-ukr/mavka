#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_structure_node(
      MaMa* M,
      const mavka::ast::StructureNode* structure_node) {
    // M->instructions.push_back(
    //     new MaInstruction(OP_STRUCT, 0, structure_node->name));
    // for (int i = 0; i < structure_node->params.size(); ++i) {
    //   const auto param = structure_node->params[i];
    //   M->instructions.push_back(
    //       new MaInstruction(OP_STRUCT_PARAM, i, param->name));
    // }
    // M->instructions.push_back(
    //     new MaInstruction(OP_STORE, 0, structure_node->name));
    return success();
  }
} // namespace mavka::mama