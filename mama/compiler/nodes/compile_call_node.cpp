#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_call_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::CallNode* call_node) {
    const auto result = compile_node(M, code, call_node->value);
    if (result.error) {
      return result;
    }

    code->instructions.push_back(
        MaInstruction{OP_INITCALL,
                      {.initcall = new MaInitCallInstructionArgs({
                           .line = call_node->start_line,
                           .column = call_node->start_column,
                       })}});
    const auto initcall_instruction_index = code->instructions.size() - 1;

    for (const auto& arg : call_node->args) {
      const auto arg_result = compile_node(M, code, arg->value);
      if (arg_result.error) {
        return arg_result;
      }
      if (arg->name.empty()) {
        code->instructions.push_back(MaInstruction{
            OP_STORE_ARG,
            {.storearg =
                 new MaStoreArgInstructionArgs(std::to_string(arg->index))}});
      } else {
        code->instructions.push_back(MaInstruction{
            OP_STORE_ARG,
            {.storearg = new MaStoreArgInstructionArgs(arg->name)}});
      }
    }

    code->instructions[initcall_instruction_index].args.initcall->index =
        code->instructions.size() + 1;

    code->instructions.push_back(MaInstruction{OP_CALL});

    return success();
  }
} // namespace mavka::mama
