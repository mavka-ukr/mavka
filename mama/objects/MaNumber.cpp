#include "../mama.h"

namespace mavka::mama {
  void number_structure_object_mag_call_diia_native_fn(MaMa* M,
                                                       MaObject* me,
                                                       MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_EMPTY(cell)) {
      PUSH_NUMBER(0);
      return;
    }
    if (IS_NUMBER(cell)) {
      PUSH(cell);
      return;
    }
    if (IS_YES(cell)) {
      PUSH_NUMBER(1);
      return;
    }
    if (IS_NO(cell)) {
      PUSH_NUMBER(0);
      return;
    }
    if (IS_OBJECT(cell)) {
      if (OBJECT_HAS(cell.v.object, MAG_NUMBER)) {
        PUSH(cell.v.object->properties[MAG_NUMBER]);
        M->diia_native_callback = [](MaMa* M) {
          POP_VALUE(mag_number_diia_cell);
          READ_TOP_FRAME();
          if (initcall(M, MA_ARGS_POSITIONED, mag_number_diia_cell,
                       {.line = frame->data.call->line,
                        .column = frame->data.call->column})) {
            M->diia_native_repeat = true;
          } else {
            M->stack.push(create_string(M, "Неможливо перетворити на число."));
            M->diia_native_throw = true;
          }
        };
        return;
      }
    }
    M->stack.push(create_string(M, "Неможливо перетворити на число."));
    M->diia_native_throw = true;
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