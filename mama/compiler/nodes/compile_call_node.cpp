#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_call_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::CallNode* call_node) {
    const auto result = compile_node(M, code, call_node->value);
    if (result.error) {
      return result;
    }

    const auto args_type =
        call_node->args.empty()
            ? MA_ARGS_POSITIONED
            : (call_node->args[0]->name.empty() ? MA_ARGS_POSITIONED
                                                : MA_ARGS_NAMED);

    code->instructions.push_back(MaInstruction::initcall(new MaInitCallInstructionArgs({
        .args_type = args_type,
        .line = call_node->start_line,
        .column = call_node->start_column,
    })));
    const auto initcall_instruction_index = code->instructions.size() - 1;

    for (const auto& arg : call_node->args) {
      const auto arg_result = compile_node(M, code, arg->value);
      if (arg_result.error) {
        return arg_result;
      }
      if (arg->name.empty()) {
        code->instructions.push_back(MaInstruction::pusharg());
      } else {
        code->instructions.push_back(
            MaInstruction::storearg(new MaStoreArgInstructionArgs(arg->name)));
      }
    }

    code->instructions[initcall_instruction_index].args.initcall->return_index =
        code->instructions.size() + 1;

    code->instructions.push_back(MaInstruction::call());

    return success();
  }
} // namespace mavka::mama
