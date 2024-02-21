#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_try_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::TryNode* try_node) {
    code->instructions.push_back(MaInstruction::try_(new MaTryInstructionArgs()));
    const auto try_instruction_index = code->instructions.size() - 1;
    const auto result = compile_body(M, code, try_node->body);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(MaInstruction::trydone(new MaTryDoneInstructionArgs()));
    const auto try_done_instruction_index = code->instructions.size() - 1;
    code->instructions[try_instruction_index].args.try_->catch_index = code->instructions.size();
    code->instructions.push_back(
        MaInstruction::store(new MaStoreInstructionArgs(try_node->name)));
    const auto catch_result = compile_body(M, code, try_node->catch_body);
    if (catch_result.error) {
      return catch_result;
    }
    code->instructions[try_done_instruction_index].args.trydone->index =
        code->instructions.size() - 1;
    return success();
  }
} // namespace mavka::mama