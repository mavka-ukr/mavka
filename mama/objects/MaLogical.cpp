#include "../mama.h"

namespace mavka::mama {
  void init_logical(MaMa* M) {
    const auto logical_structure_cell = create_structure(M, "логічне");
    M->global_scope->set_variable("логічне", logical_structure_cell);
    M->logical_structure_object = logical_structure_cell.v.object;
  }
} // namespace mavka::mama