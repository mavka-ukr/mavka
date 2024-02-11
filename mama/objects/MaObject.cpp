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
      const auto diia_name =
          ma_object_get(method, "назва").v.object->d.string->data;
      const auto bound_diia_cell = bind_diia(M, method, object_object);
      ma_object_set(object_object, diia_name, bound_diia_cell);
    }
    return MaCell{MA_CELL_OBJECT, {.object = object_object}};
  }

  MaCell create_empty_object(MaMa* M) {
    return create_object(M, MA_OBJECT, M->object_structure_object, nullptr);
  }
} // namespace mavka::mama