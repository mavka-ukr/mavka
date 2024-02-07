#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_call_node(
      MaCode* C,
      const mavka::ast::CallNode* call_node) {
    for (const auto& arg : call_node->args) {
      const auto arg_result = compile_node(C, arg->value);
      if (arg_result->error) {
        return arg_result;
      }
      if (arg->name.empty()) {
        C->instructions.push_back(
            new MaInstruction(OP_SET_ARG, 0, std::to_string(arg->index)));
      } else {
        C->instructions.push_back(new MaInstruction(OP_SET_ARG, 0, arg->name));
      }
    }
    const auto result = compile_node(C, call_node->value);
    if (result->error) {
      return result;
    }
    C->instructions.push_back(new MaInstruction(OP_CALL));
    return success();
  }
} // namespace mavka::mama
