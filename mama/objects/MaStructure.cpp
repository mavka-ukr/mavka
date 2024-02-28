#include "../mama.h"

namespace mavka::mama {
  MaCell ma_structure_get_handler(MaMa* M,
                                  MaObject* o,
                                  const std::string& name) {
    if (name == "назва") {
      return create_string(M, o->d.structure->name);
    }
    if (!o->properties.contains(name)) {
      M->throw_cell =
          create_string(M, "Властивість \"" + name +
                               "\" не визначено для типу \"Структура\".");
      throw MaException();
    }
    return o->properties[name];
  }

  MaCell structure_structure_object_get_structure_diia_native_fn(MaMa* M,
                                                                 MaObject* o,
                                                                 MaArgs* args) {
    const auto cell = ARGS_GET(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_EMPTY(cell)) {
      RETURN_EMPTY();
    }
    if (IS_NUMBER(cell)) {
      RETURN_OBJECT(M->number_structure_object);
    }
    if (IS_YES(cell) || IS_NO(cell)) {
      RETURN_OBJECT(M->logical_structure_object);
    }
    RETURN_OBJECT(cell.v.object->structure);
  }

  MaCell create_structure(MaMa* M, const std::string& name) {
    const auto structure = new MaStructure();
    structure->name = name;
    const auto structure_object = new MaObject();
    structure_object->type = MA_OBJECT_STRUCTURE;
    structure_object->d.structure = structure;
    structure_object->structure = structure_object;
    structure_object->get = ma_structure_get_handler;
    structure_object->call = [](MaMa* M, MaObject* o, MaArgs* args,
                                MaInstructionLocation* location) {
      const auto object_cell = create_object(M, MA_OBJECT, o, nullptr);
      for (int i = 0; i < o->d.structure->params.size(); ++i) {
        const auto& param = o->d.structure->params[i];
        const auto arg_value =
            ARGS_GET(args, i, param.name, param.default_value);
        ma_object_set(object_cell.v.object, param.name, arg_value);
      }
      RETURN(object_cell);
    };
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
                      structure_structure_object_get_structure_diia_native_fn,
                      M->structure_structure_object));
  }
} // namespace mavka::mama