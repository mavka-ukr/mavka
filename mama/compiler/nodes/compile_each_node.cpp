#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_each_node(MaCode* C,
                                         mavka::ast::EachNode* each_node) {
    if (each_node->value->FromToSimpleNode) {
      const auto from_result =
          compile_node(C, each_node->value->FromToSimpleNode->from);
      if (from_result->error) {
        return from_result;
      }
      C->instructions.push_back(MaInstruction::create_store(each_node->name));

      const auto start_index = C->instructions.size();

      C->instructions.push_back(MaInstruction::create_load(each_node->name));
      const auto to_result =
          compile_node(C, each_node->value->FromToSimpleNode->to);
      if (to_result->error) {
        return to_result;
      }
      C->instructions.push_back(new MaInstruction(OP_GT));
      const auto jump_out_i = new MaInstruction(OP_JUMP_IF_TRUE);
      C->instructions.push_back(jump_out_i);

      const auto result = compile_body(C, each_node->body);
      if (result->error) {
        return result;
      }

      C->instructions.push_back(MaInstruction::create_load(each_node->name));
      C->instructions.push_back(MaInstruction::create_push_number(1));
      C->instructions.push_back(new MaInstruction(OP_ADD));
      C->instructions.push_back(MaInstruction::create_store(each_node->name));

      C->instructions.push_back(MaInstruction::create_jump(start_index));

      jump_out_i->numval = C->instructions.size();

      return success();
    }
    return error(mavka::ast::make_ast_some(each_node), "Not implemented");
  }
} // namespace mavka::mama