
#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_dictionary_node(
      MaMa* M,
      const mavka::ast::DictionaryNode* dictionary_node) {
    M->code.push_back(MaInstruction{OP_DICT});
    for (const auto& element : dictionary_node->elements) {
      const auto result = compile_node(M, element->value);
      if (result.error) {
        return result;
      }
      M->code.push_back(MaInstruction{OP_DICT_SET,
                                      {.dictset = new MaDictSetInstructionArgs(
                                           element->key->StringNode->value)}});
    }
    return success();
  }
} // namespace mavka::mama