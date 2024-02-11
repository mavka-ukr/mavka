#include "../mama.h"

namespace mavka::mama {
  MaCell create_object(MaMa* M,
                       unsigned char type,
                       MaObject* structure_object,
                       void* d) {
    const auto object_object = new MaObject();
    object_object->type = type;
    object_object->d.ptr = d;
    object_object->structure = structure_object;
    for (const auto& method : structure_object->d.structure->methods) {
      const auto bound_diia_cell = bind_diia(M, method, object_object);
      ma_object_set(object_object, method->d.diia->name, bound_diia_cell);
    }
    return MaCell{MA_CELL_OBJECT, {.object = object_object}};
  }

  MaCell create_empty_object(MaMa* M) {
    return create_object(M, MA_OBJECT, M->object_structure_object, nullptr);
  }

  void init_object(MaMa* M) {
    const auto object_structure_cell = create_structure(M, "обʼєкт");
    M->global_scope->set_variable("обʼєкт", object_structure_cell);
    M->object_structure_object = object_structure_cell.v.object;
    M->structure_structure_object->structure = object_structure_cell.v.object;
  }
} // namespace mavka::mama