#include "../mama.h"

namespace mavka::mama {
  void init_number(MaMa* M) {
    const auto number_structure_cell = create_structure(M, "число");
    M->global_scope->set_variable("число", number_structure_cell);
    M->number_structure_object = number_structure_cell.v.object;
  }
} // namespace mavka::mama