#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_call_node(MaMa* M,
                                        const mavka::ast::CallNode* call_node) {
    const auto result = compile_node(M, call_node->value);
    if (result.error) {
      return result;
    }

    M->code.push_back(MaInstruction{
        OP_INITCALL, {.initcall = new MaInitCallInstructionArgs()}});
    const auto initcall_instruction_index = M->code.size() - 1;

    const auto args = call_node->args;
    for (const auto& arg : args) {
      const auto arg_result = compile_node(M, arg->value);
      if (arg_result.error) {
        return arg_result;
      }
      if (arg->name.empty()) {
        M->code.push_back(MaInstruction{
            OP_STORE_ARG,
            {.storearg =
                 new MaStoreArgInstructionArgs(std::to_string(arg->index))}});
      } else {
        M->code.push_back(MaInstruction{
            OP_STORE_ARG,
            {.storearg = new MaStoreArgInstructionArgs(arg->name)}});
      }
    }

    M->code[initcall_instruction_index].args.initcall->index =
        M->code.size() + 1;

    M->code.push_back(MaInstruction{OP_CALL});

    return success();
  }
} // namespace mavka::mama
