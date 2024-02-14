#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_simple_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::AssignSimpleNode* assign_simple_node) {
    if (assign_simple_node->op == "=") {
      const auto result = compile_node(M, code, assign_simple_node->value);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(MaInstruction{
          OP_STORE,
          {.store = new MaStoreInstructionArgs(assign_simple_node->name)}});
      return success();
    }
    return error(
        mavka::ast::make_ast_some(assign_simple_node),
        "Вказівка \"" + assign_simple_node->op + "\" тимчасово недоступна.");
  }
} // namespace mavka::mama
