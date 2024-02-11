#include "../mama.h"

namespace mavka::mama {
  MaCell ma_structure_get_handler(MaMa* M,
                                  MaObject* me,
                                  const std::string& name) {
    if (name == "назва") {
      return create_string(M, me->d.structure->name);
    }
    if (!me->properties.contains(name)) {
      M->stack.push(create_string(
          M,
          "Властивість \"" + name + "\" не визначено для типу \"Структура\"."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
    return me->properties[name];
  }

  MaCell structure_structure_object_get_structure_native_diia_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return MA_MAKE_EMPTY();
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_EMPTY) {
      return MA_MAKE_EMPTY();
    }
    if (cell.type == MA_CELL_NUMBER) {
      return MA_MAKE_OBJECT(M->number_structure_object);
    }
    if (cell.type == MA_CELL_YES || cell.type == MA_CELL_NO) {
      return MA_MAKE_OBJECT(M->logical_structure_object);
    }
    return MA_MAKE_OBJECT(cell.v.object->structure);
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

  void init_structure_2(MaMa* M) {
    ma_object_set(M->structure_structure_object, "дізнатись",
                  create_diia_native(
                      M, "дізнатись",
                      structure_structure_object_get_structure_native_diia_fn,
                      M->structure_structure_object));

  }
} // namespace mavka::mama