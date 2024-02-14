#include "../mama.h"

namespace mavka::mama {
  void number_structure_object_mag_call_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      M->stack.push(MA_MAKE_NUBMER(0));
      return;
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_EMPTY) {
      M->stack.push(MA_MAKE_NUBMER(0));
      return;
    } else if (cell.type == MA_CELL_NUMBER) {
      M->stack.push(cell);
      return;
    } else if (cell.type == MA_CELL_YES) {
      M->stack.push(MA_MAKE_NUBMER(1));
      return;
    } else if (cell.type == MA_CELL_NO) {
      M->stack.push(MA_MAKE_NUBMER(0));
      return;
    } else if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->properties.contains(MAG_NUMBER)) {
        M->stack.push(cell.v.object->properties[MAG_NUMBER]);
        M->diia_native_redirect = [](MaMa* M) {
          POP_VALUE(mag_number_diia_cell);
          if (!initcall(M, mag_number_diia_cell, {.return_index = M->i + 1})) {
            M->stack.push(create_string(M, "Неможливо перетворити на число."));
            M->diia_native_throw = true;
            return false;
          }
          return true;
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