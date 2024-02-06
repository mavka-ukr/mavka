#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_chain_node(MaCode* C,
                                          mavka::ast::ChainNode* chain_node) {
    const auto result = compile_node(C, chain_node->left);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(
        MaInstruction::create_get(chain_node->right->name));
    return success();
  }
} // namespace mavka::mama
