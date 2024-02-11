#include "../mama.h"

namespace mavka::mama {
  void init_logical(MaMa* M) {
    const auto logical_structure_object = new MaObject();
    logical_structure_object->type = MA_OBJECT_STRUCTURE;
    logical_structure_object->structure = M->structure_structure_object;
    const auto logical_structure = new MaStructure();
    logical_structure_object->d.structure = logical_structure;
    ma_object_set(logical_structure_object, "назва",
                  create_string(M, "логічне"));
    const auto logical_structure_cell =
        MaCell{MA_CELL_OBJECT, {.object = logical_structure_object}};
    M->global_scope->set_variable("логічне", logical_structure_cell);
    M->logical_structure_object = logical_structure_object;
  }
} // namespace mavka::mama