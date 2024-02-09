#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_module_node(
      MaMa* M,
      const mavka::ast::ModuleNode* module_node) {
    // auto jump_out_of_module_instruction = MaInstruction{OP_JUMP};
    // M->instructions.push_back(jump_out_of_module_instruction);
    //
    // const auto module_index = M->instructions.size();
    //
    // const auto body_result = compile_body(M, module_node->body);
    // if (body_result->error) {
    //   return body_result;
    // }
    // M->instructions.push_back(
    //     MaInstruction{OP_LOAD, {.load = new
    //     MaLoadInstructionArgs("пусто")}});
    // M->instructions.push_back(MaInstruction{OP_RETURN});
    //
    // jump_out_of_module_instruction.args.jump = M->instructions.size();
    // M->instructions.push_back(
    //     new MaInstruction(OP_MODULE, module_index, module_node->name));

    return success();
  }
} // namespace mavka::mama