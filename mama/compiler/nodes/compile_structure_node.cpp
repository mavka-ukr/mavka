#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_structure_node(
      MaMa* M,
      const mavka::ast::StructureNode* structure_node) {
    M->code.push_back(MaInstruction{
        OP_STRUCT,
        {.struct_ = new MaStructInstructionArgs(structure_node->name)}});
    M->code.push_back(MaInstruction{
        OP_STORE, {.store = new MaStoreInstructionArgs(structure_node->name)}});
    return success();
  }
} // namespace mavka::mama