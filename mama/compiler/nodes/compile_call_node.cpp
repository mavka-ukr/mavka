#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_call_node(
      MaCode* C,
      const mavka::ast::CallNode* call_node) {
    const auto result = compile_node(C, call_node->value);
    if (result->error) {
      return result;
    }
    const auto args = call_node->args;
    for (const auto& arg : args) {
      const auto arg_result = compile_node(C, arg->value);
      if (arg_result->error) {
        return arg_result;
      }
    }
    std::vector reversed_args(args.rbegin(), args.rend());
    for (const auto& arg : reversed_args) {
      if (arg->name.empty()) {
        C->instructions.push_back(
            new MaInstruction(OP_SET_ARG, 0, std::to_string(arg->index)));
      } else {
        C->instructions.push_back(new MaInstruction(OP_SET_ARG, 0, arg->name));
      }
    }
    C->instructions.push_back(new MaInstruction(OP_CALL));
    return success();
  }
} // namespace mavka::mama
