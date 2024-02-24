#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_property_set_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto property_set_node = ast_value->data.PropertySetNode;
    const auto value_result = compile_node(M, code, property_set_node->value);
    if (value_result.error) {
      return value_result;
    }
    const auto result = compile_node(M, code, property_set_node->left);
    if (result.error) {
      return result;
    }
    code->instructions.push_back(
        MaInstruction::set(new MaSetInstructionArgs(property_set_node->name)));
    return success();
  }
} // namespace mavka::mama
