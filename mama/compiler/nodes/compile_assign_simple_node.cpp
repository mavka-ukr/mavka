#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_assign_simple_node(
      MaCode* C,
      mavka::ast::AssignSimpleNode* assign_simple_node) {
    const auto result = compile_node(C, assign_simple_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(
        MaInstruction::create_store(assign_simple_node->name));
    return success();
  }
} // namespace mavka::mama
