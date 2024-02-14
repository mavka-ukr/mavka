
#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_dictionary_node(
      MaMa* M,
      MaCode* code,
      const mavka::ast::DictionaryNode* dictionary_node) {
    code->instructions.push_back(MaInstruction{OP_DICT});
    for (const auto& element : dictionary_node->elements) {
      const auto result = compile_node(M, code, element->value);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(MaInstruction{OP_DICT_SET,
                                      {.dictset = new MaDictSetInstructionArgs(
                                           element->key->StringNode->value)}});
    }
    return success();
  }
} // namespace mavka::mama