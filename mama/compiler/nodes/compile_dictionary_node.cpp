
#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_dictionary_node(
      MaCode* C,
      mavka::ast::DictionaryNode* dictionary_node) {
    C->instructions.push_back(new MaInstruction(OP_DICT));
    for (const auto& element : dictionary_node->elements) {
      const auto result = compile_node(C, element->value);
      if (result->error) {
        return result;
      }
      C->instructions.push_back(
          new MaInstruction(OP_DICT_SET, 0, element->key->StringNode->value));
    }
    return success();
  }
} // namespace mavka::mama