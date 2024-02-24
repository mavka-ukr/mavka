#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_property_get_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto property_get_node = ast_value->data.PropertyGetNode;
    const auto result = compile_node(M, code, property_get_node->left);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(
        MaInstruction::get(new MaGetInstructionArgs(property_get_node->name)));
    return success();
  }
} // namespace mavka::mama
