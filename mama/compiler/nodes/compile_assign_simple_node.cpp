#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_simple_node(
      MaMa* M,
      const mavka::ast::AssignSimpleNode* assign_simple_node) {
    const auto result = compile_node(M, assign_simple_node->value);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction{
        OP_STORE,
        {.store = new MaStoreInstructionArgs(assign_simple_node->name)}});
    return success();
  }
} // namespace mavka::mama
