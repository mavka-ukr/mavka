#include "../mama.h"

namespace mavka::mama {
  MaCell ma_structure_get_handler(MaMa* M,
                                  MaObject* me,
                                  const std::string& name) {
    if (name == "назва") {
      return create_string(M, me->d.structure->name);
    }
    return ma_object_get(me, name);
  }

  MaCell create_structure(MaMa* M, const std::string& name) {
    const auto structure = new MaStructure();
    structure->name = name;
    const auto structure_object = new MaObject();
    structure_object->type = MA_OBJECT_STRUCTURE;
    structure_object->d.structure = structure;
    structure_object->structure = structure_object;
    structure_object->get = ma_structure_get_handler;
    return MaCell{MA_CELL_OBJECT, {.object = structure_object}};
  }

  void init_structure(MaMa* M) {
    const auto structure_structure_cell = create_structure(M, "Структура");
    M->structure_structure_object = structure_structure_cell.v.object;
    M->global_scope->set_variable("Структура", structure_structure_cell);
    structure_structure_cell.v.object->structure =
        structure_structure_cell.v.object;
  }
} // namespace mavka::mama