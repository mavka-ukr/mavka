#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_list_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::ASTValue* ast_value) {
    const auto list_node = ast_value->data.ListNode;
    code->instructions.push_back(MaInstruction::list());
    for (auto& element : list_node->elements) {
      const auto result = compile_node(M, code, element);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(MaInstruction::listappend());
    }
    return success();
  }
} // namespace mavka::mama
