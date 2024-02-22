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

    const auto instruction_location = new MaInstructionLocation(
        call_node->start_line, call_node->start_column);

    code->instructions.push_back(
        MaInstruction::initargs(new MaInitArgsInstructionArgs(args_type)));

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

    code->instructions.push_back(MaInstruction::call(instruction_location));

    return success();
  }
} // namespace mavka::mama
