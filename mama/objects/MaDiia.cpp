#include "../mama.h"

namespace mavka::mama {
  MaCell create_diia(MaMa* M, const int& index) {
    const auto diia_object = new MaObject();
    diia_object->type = MA_OBJECT_DIIA;
    diia_object->structure = M->diia_structure_object;

    const auto diia = new MaDiia();
    diia->index = index;

    diia_object->d.diia = diia;

    return MaCell{MA_CELL_OBJECT, {.object = diia_object}};
  }

  MaCell create_diia(MaMa* M, const int& index, MaObject* me) {
    const auto diia_cell = create_diia(M, index);
    diia_cell.v.object->d.diia->me = me;
    return diia_cell;
  }

  MaCell create_diia_native(MaMa* M,
                            const std::function<DiiaNativeFn>& diia_native_fn) {
    const auto diia_native_object = new MaObject();
    diia_native_object->type = MA_OBJECT_DIIA_NATIVE;
    diia_native_object->structure = M->diia_structure_object;

    const auto diia_native = new MaDiiaNative();
    diia_native->fn = diia_native_fn;

    diia_native_object->d.diia_native = diia_native;

    return MaCell{MA_CELL_OBJECT, {.object = diia_native_object}};
  }

  MaCell create_diia_native(MaMa* M,
                            const std::function<DiiaNativeFn>& diia_native_fn,
                            MaObject* me) {
    const auto diia_native_cell = create_diia_native(M, diia_native_fn);
    diia_native_cell.v.object->d.diia_native->me = me;
    return diia_native_cell;
  }

  MaCell bind_diia(MaMa* M, MaObject* diia, MaObject* object) {
    const auto diia_cell = create_diia(M, diia->d.diia->index, object);
    diia_cell.v.object->d.diia->scope = diia->d.diia->scope;
    diia_cell.v.object->d.diia->params = diia->d.diia->params;
    return diia_cell;
  }

  void init_diia(MaMa* M) {
    const auto diia_structure_object = new MaObject();
    diia_structure_object->type = MA_OBJECT_STRUCTURE;
    diia_structure_object->structure = M->structure_structure_object;
    const auto diia_structure = new MaStructure();
    diia_structure_object->d.structure = diia_structure;
    ma_object_set(diia_structure_object, "назва", create_string(M, "Дія"));
    const auto diia_structure_cell =
        MaCell{MA_CELL_OBJECT, {.object = diia_structure_object}};
    M->global_scope->set_variable("Дія", diia_structure_cell);
    M->diia_structure_object = diia_structure_object;
  }
} // namespace mavka::mama