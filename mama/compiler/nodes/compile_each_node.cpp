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
      const auto to_result =
          compile_node(C, each_node->value->FromToSimpleNode->to);
      if (to_result->error) {
        return to_result;
      }
      C->instructions.push_back(
          new MaInstruction(OP_EACH_SIMPLE, 0, each_node->name));
      return success();
    }
    return error(mavka::ast::make_ast_some(each_node), "Not implemented");
  }
} // namespace mavka::mama