#include "../mama.h"

namespace mavka::mama {
  MaCell create_diia(MaMa* M, const int& index, MaObject* me) {
    const auto diia = new MaDiia();
    diia->index = index;
    diia->me = me;
    return create_object(M, MA_OBJECT_DIIA, M->diia_structure_object, diia);
  }

  MaCell create_diia_native(MaMa* M,
                            const std::function<DiiaNativeFn>& diia_native_fn,
                            MaObject* me) {
    const auto diia_native = new MaDiiaNative();
    diia_native->fn = diia_native_fn;
    diia_native->me = me;
    return create_object(M, MA_OBJECT_DIIA_NATIVE, M->diia_structure_object,
                         diia_native);
  }

  MaCell bind_diia(MaMa* M, MaObject* diia, MaObject* object) {
    const auto diia_cell = create_diia(M, diia->d.diia->index, object);
    diia_cell.v.object->d.diia->scope = diia->d.diia->scope;
    diia_cell.v.object->d.diia->params = diia->d.diia->params;
    return diia_cell;
  }

  void init_diia(MaMa* M) {
    const auto diia_structure_cell = create_structure(M, "Дія");
    M->global_scope->set_variable("Дія", diia_structure_cell);
    M->diia_structure_object = diia_structure_cell.v.object;
  }
} // namespace mavka::mama