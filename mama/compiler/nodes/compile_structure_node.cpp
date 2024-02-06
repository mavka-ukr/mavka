#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_structure_node(
      MaCode* C,
      mavka::ast::StructureNode* structure_node) {
    return error(mavka::ast::make_ast_some(structure_node), "Not implemented");
  }
} // namespace mavka::mama