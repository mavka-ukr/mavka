#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_structure_node(
      MaCode* C,
      const mavka::ast::StructureNode* structure_node) {
    C->instructions.push_back(
        new MaInstruction(OP_STRUCT, 0, structure_node->name));
    for (int i = 0; i < structure_node->params.size(); ++i) {
      const auto param = structure_node->params[i];
      C->instructions.push_back(
          new MaInstruction(OP_STRUCT_PARAM, i, param->name));
    }
    C->instructions.push_back(
        new MaInstruction(OP_STORE, 0, structure_node->name));
    return success();
  }
} // namespace mavka::mama