#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_diia_node(MaMa* M,
                                        mavka::ast::DiiaNode* diia_node) {
    if (diia_node->structure.empty()) {
      const auto result = compile_diia(
          M, diia_node->async, diia_node->generics, diia_node->name,
          diia_node->params, diia_node->return_types, diia_node->body);
      if (result.error) {
        return result;
      }
      M->code.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(diia_node->name)}});
    } else {
      if (diia_node->ee) {
        return error(ast::make_ast_some(diia_node),
                     "Спец дії наразі не підтримуються.");
      }
      const auto result = compile_method(
          M, diia_node->structure, diia_node->ee, diia_node->async,
          diia_node->generics, diia_node->name, diia_node->params,
          diia_node->return_types, diia_node->body);
      if (result.error) {
        return result;
      }
    }

    return success();
  }
} // namespace mavka::mama