#include "../mama.h"

namespace mavka::mama {
  void init_number(MaMa* M) {
    const auto number_structure_object = new MaObject();
    number_structure_object->type = MA_OBJECT_STRUCTURE;
    number_structure_object->structure = M->structure_structure_object;
    const auto number_structure = new MaStructure();
    number_structure_object->d.structure = number_structure;
    ma_object_set(number_structure_object, "назва", create_string(M, "число"));
    const auto number_structure_cell =
        MaCell{MA_CELL_OBJECT, {.object = number_structure_object}};
    M->global_scope->set_variable("число", number_structure_cell);
    M->number_structure_object = number_structure_object;
  }
} // namespace mavka::mama