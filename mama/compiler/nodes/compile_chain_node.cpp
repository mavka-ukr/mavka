#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_chain_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto chain_node = ast_value->data.ChainNode;
    const auto result = compile_node(M, code, chain_node->left);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(
        MaInstruction::get(new MaGetInstructionArgs(chain_node->right->name)));
    return success();
  }
} // namespace mavka::mama
