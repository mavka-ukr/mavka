#include "../compiler.h"

namespace mavka::mama {
  MaCompilationResult* compile_mockup_subject_node(
      MaCode* C,
      mavka::ast::MockupSubjectNode* mockup_subject_node) {
    return error(mavka::ast::make_ast_some(mockup_subject_node),
                 "Not implemented");
  }
} // namespace mavka::mama