#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult* compile_call_node(
      MaMa* M,
      const mavka::ast::CallNode* call_node) {
    const auto result = compile_node(M, call_node->value);
    if (result->error) {
      return result;
    }

    M->instructions.push_back(MaInstruction{
        OP_INITCALL, {.initcall = new MaInitCallInstructionArgs()}});
    const auto initcall_instruction_index = M->instructions.size() - 1;

    const auto args = call_node->args;
    for (const auto& arg : args) {
      const auto arg_result = compile_node(M, arg->value);
      if (arg_result->error) {
        return arg_result;
      }
      if (arg->name.empty()) {
        M->instructions.push_back(MaInstruction{
            OP_SET_ARG,
            {.setarg =
                 new MaSetArgInstructionArgs(std::to_string(arg->index))}});
      } else {
        M->instructions.push_back(MaInstruction{
            OP_SET_ARG, {.setarg = new MaSetArgInstructionArgs(arg->name)}});
      }
    }

    M->instructions[initcall_instruction_index].args.initcall->index =
        M->instructions.size() + 1;

    M->instructions.push_back(MaInstruction{OP_CALL});

    return success();
  }
} // namespace mavka::mama
