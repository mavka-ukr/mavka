
#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_dictionary_node(
      MaMa* M,
      const mavka::ast::DictionaryNode* dictionary_node) {
    M->code.push_back(MaInstruction::dict());
    for (const auto& element : dictionary_node->elements) {
      const auto result = compile_node(M, element->value);
      if (result.error) {
        return result;
      }
      M->code.push_back(MaInstruction::dictset(
          new MaDictSetInstructionArgs(element->key->StringNode->value)));
    }
    return success();
  }
} // namespace mavka::mama