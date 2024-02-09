#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_try_node(MaMa* M,
                                        const mavka::ast::TryNode* try_node) {
    // const auto try_i = MaInstruction::create_try(0);
    // M->instructions.push_back(try_i);
    // const auto result = compile_body(M, try_node->body);
    // if (result->error) {
    //   return result;
    // }
    // M->instructions.push_back(MaInstruction::create_try_done());
    // try_i->numval = M->instructions.size();
    // M->instructions.push_back(MaInstruction::create_store(try_node->name));
    // const auto catch_result = compile_body(M, try_node->catch_body);
    // if (catch_result->error) {
    //   return catch_result;
    // }
    return success();
  }
} // namespace mavka::mama