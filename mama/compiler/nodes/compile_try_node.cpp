#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_try_node(MaMa* M,
                                       const mavka::ast::TryNode* try_node) {
    M->code.push_back(
        MaInstruction{OP_TRY, {.try_ = new MaTryInstructionArgs()}});
    const auto try_instruction_index = M->code.size() - 1;
    const auto result = compile_body(M, try_node->body);
    if (result.error) {
      return result;
    }
    M->code.push_back(MaInstruction{
        OP_TRY_DONE, {.trydone = new MaTryDoneInstructionArgs()}});
    const auto try_done_instruction_index = M->code.size() - 1;
    M->code[try_instruction_index].args.try_->catch_index = M->code.size();
    M->code.push_back(MaInstruction{
        OP_STORE, {.store = new MaStoreInstructionArgs(try_node->name)}});
    const auto catch_result = compile_body(M, try_node->catch_body);
    if (catch_result.error) {
      return catch_result;
    }
    M->code[try_done_instruction_index].args.trydone->index =
        M->code.size() - 1;
    return success();
  }
} // namespace mavka::mama