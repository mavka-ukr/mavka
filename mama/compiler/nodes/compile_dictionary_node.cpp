
#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_dictionary_node(
      MaCode* C,
      mavka::ast::DictionaryNode* dictionary_node) {
    return error(mavka::ast::make_ast_some(dictionary_node), "Not implemented");
  }
} // namespace mavka::mama