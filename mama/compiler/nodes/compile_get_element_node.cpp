#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_get_element_node(
      MaMa* M,
      const mavka::ast::GetElementNode* get_element_node) {
    const auto value_result = compile_node(M, get_element_node->value);
    if (value_result.error) {
      return value_result;
    }
    M->code.push_back(MaInstruction{
        OP_GET, {.get = new MaGetInstructionArgs(MAG_GET_ELEMENT)}});
    M->code.push_back(MaInstruction{
        OP_INITCALL, {.initcall = new MaInitCallInstructionArgs()}});
    const auto initcall_instruction_index = M->code.size() - 1;
    const auto key_result = compile_node(M, get_element_node->index);
    if (key_result.error) {
      return key_result;
    }
    M->code.push_back(MaInstruction{
        OP_STORE_ARG, {.storearg = new MaStoreArgInstructionArgs("0")}});
    M->code[initcall_instruction_index].args.initcall->index =
        M->code.size() + 1;
    M->code.push_back(MaInstruction{OP_CALL});
    return success();
  }
} // namespace mavka::mama