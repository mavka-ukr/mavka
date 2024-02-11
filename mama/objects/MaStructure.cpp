#include "../mama.h"

namespace mavka::mama {
  MaCell create_structure(MaMa* M, const std::string& name) {
    const auto structure_object = new MaObject();
    structure_object->type = MA_OBJECT_STRUCTURE;
    structure_object->structure = M->structure_structure_object;
    const auto structure = new MaStructure();
    structure_object->d.structure = structure;
    ma_object_set(structure_object, "назва", create_string(M, name));
    return MaCell{MA_CELL_OBJECT, {.object = structure_object}};
  }

  void init_structure(MaMa* M) {
    const auto structure_structure_object = new MaObject();
    structure_structure_object->type = MA_OBJECT_STRUCTURE;
    const auto structure_structure = new MaStructure();
    structure_structure_object->d.structure = structure_structure;
    ma_object_set(structure_structure_object, "назва",
                  create_string(M, "Структура"));
    const auto structure_structure_cell =
        MaCell{MA_CELL_OBJECT, {.object = structure_structure_object}};
    M->global_scope->set_variable("Структура", structure_structure_cell);
    M->structure_structure_object = structure_structure_object;
    structure_structure_object->structure = M->structure_structure_object;
  }
} // namespace mavka::mama