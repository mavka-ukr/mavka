#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_diia_node(
      MaCode* C,
      const mavka::ast::DiiaNode* diia_node) {
    if (diia_node->structure.empty()) {
      const auto result = compile_diia(
          C, diia_node->async, diia_node->generics, diia_node->name,
          diia_node->params, diia_node->return_types, diia_node->body);
      if (result->error) {
        return result;
      }
      C->instructions.push_back(
          new MaInstruction(OP_STORE, 0, diia_node->name));
    } else {
      const auto result = compile_method(
          C, diia_node->structure, diia_node->async, diia_node->generics,
          diia_node->name, diia_node->params, diia_node->return_types,
          diia_node->body);
      if (result->error) {
        return result;
      }
    }

    return success();
  }
} // namespace mavka::mama