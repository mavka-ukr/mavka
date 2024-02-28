#include "../mama.h"

namespace mavka::mama {
  MaCell number_structure_object_mag_call_diia_native_fn(MaMa* M,
                                                         MaObject* o,
                                                         MaArgs* args) {
    const auto cell = ARGS_GET(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_EMPTY(cell)) {
      RETURN_NUMBER(0);
    }
    if (IS_NUMBER(cell)) {
      RETURN(cell);
    }
    if (IS_YES(cell)) {
      RETURN_NUMBER(1);
    }
    if (IS_NO(cell)) {
      RETURN_NUMBER(0);
    }
    if (IS_OBJECT(cell)) {
      if (OBJECT_HAS(cell.v.object, MAG_NUMBER)) {
        return ma_call(M, cell.v.object->properties[MAG_NUMBER], {}, {});
      }
    }
    M->throw_cell = create_string(M, "Неможливо перетворити на число.");
    throw MaException();
  }

  void init_number(MaMa* M) {
    const auto number_structure_cell = create_structure(M, "число");
    M->global_scope->set_variable("число", number_structure_cell);
    M->number_structure_object = number_structure_cell.v.object;
    ma_object_set(
        number_structure_cell.v.object, MAG_CALL,
        create_diia_native(M, MAG_CALL,
                           number_structure_object_mag_call_diia_native_fn,
                           number_structure_cell.v.object));
  }
} // namespace mavka::mama