#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_each_node(MaMa* M,
                                         mavka::ast::EachNode* each_node) {
    // if (each_node->value->FromToSimpleNode) {
    //   const auto from_result =
    //       compile_node(M, each_node->value->FromToSimpleNode->from);
    //   if (from_result->error) {
    //     return from_result;
    //   }
    //   M->instructions.push_back(MaInstruction::create_store(each_node->name));
    //
    //   const auto start_index = M->instructions.size();
    //
    //   M->instructions.push_back(MaInstruction::create_load(each_node->name));
    //   const auto to_result =
    //       compile_node(M, each_node->value->FromToSimpleNode->to);
    //   if (to_result->error) {
    //     return to_result;
    //   }
    //   M->instructions.push_back(new MaInstruction(OP_GT));
    //   const auto jump_out_i = new MaInstruction(OP_JUMP_IF_TRUE);
    //   M->instructions.push_back(jump_out_i);
    //
    //   const auto result = compile_body(M, each_node->body);
    //   if (result->error) {
    //     return result;
    //   }
    //
    //   M->instructions.push_back(MaInstruction::create_load(each_node->name));
    //   M->instructions.push_back(MaInstruction::create_push_number(1));
    //   M->instructions.push_back(new MaInstruction(OP_ADD));
    //   M->instructions.push_back(MaInstruction::create_store(each_node->name));
    //
    //   M->instructions.push_back(MaInstruction::create_jump(start_index));
    //
    //   jump_out_i->numval = M->instructions.size();
    //
    //   return success();
    // }
    return error(mavka::ast::make_ast_some(each_node), "Not implemented");
  }
} // namespace mavka::mama