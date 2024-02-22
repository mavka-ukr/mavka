
#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_dictionary_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::ASTValue* ast_value) {
    const auto dictionary_node = ast_value->data.DictionaryNode;
    code->instructions.push_back(MaInstruction::dict());
    for (const auto& element : dictionary_node->elements) {
      const auto result = compile_node(M, code, element->value);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(MaInstruction::dictset(
          new MaDictSetInstructionArgs(element->key->data.StringNode->value)));
    }
    return success();
  }
} // namespace mavka::mama
