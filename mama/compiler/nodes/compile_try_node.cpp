#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_try_node(MaCode* C,
                                        const mavka::ast::TryNode* try_node) {
    const auto try_i = MaInstruction::create_try(0);
    C->instructions.push_back(try_i);
    const auto result = compile_body(C, try_node->body);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(MaInstruction::create_try_done());
    try_i->numval = C->instructions.size();
    C->instructions.push_back(MaInstruction::create_store(try_node->name));
    const auto catch_result = compile_body(C, try_node->catch_body);
    if (catch_result->error) {
      return catch_result;
    }
    return success();
  }
} // namespace mavka::mama