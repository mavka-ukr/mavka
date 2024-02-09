#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_assign_by_element_node(
      MaMa* M,
      mavka::ast::AssignByElementNode* assign_by_element_node) {
    if (assign_by_element_node->op == "=") {
      const auto left_result = compile_node(M, assign_by_element_node->left);
      if (left_result.error) {
        return left_result;
      }
      M->code.push_back(MaInstruction{
          OP_GET, {.get = new MaGetInstructionArgs(MAG_SET_ELEMENT)}});
      M->code.push_back(MaInstruction{
          OP_INITCALL, {.initcall = new MaInitCallInstructionArgs()}});
      const auto initcall_instruction_index = M->code.size() - 1;
      const auto key_result = compile_node(M, assign_by_element_node->element);
      if (key_result.error) {
        return key_result;
      }
      M->code.push_back(MaInstruction{
          OP_STORE_ARG, {.storearg = new MaStoreArgInstructionArgs("0")}});
      const auto value_result = compile_node(M, assign_by_element_node->value);
      if (value_result.error) {
        return value_result;
      }
      M->code.push_back(MaInstruction{
          OP_STORE_ARG, {.storearg = new MaStoreArgInstructionArgs("1")}});
      M->code[initcall_instruction_index].args.initcall->index =
          M->code.size() + 1;
      M->code.push_back(MaInstruction{OP_CALL});
      return success();
    }
    return error(mavka::ast::make_ast_some(assign_by_element_node),
                 "Not implemented");
  }
} // namespace mavka::mama
