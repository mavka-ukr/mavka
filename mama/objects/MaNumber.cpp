#include "../mama.h"

namespace mavka::mama {
  MaCell number_structure_object_mag_call_native_diia_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return MA_MAKE_NUBMER(0);
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_EMPTY) {
      return MA_MAKE_NUBMER(0);
    } else if (cell.type == MA_CELL_NUMBER) {
      return cell;
    } else if (cell.type == MA_CELL_YES) {
      return MA_MAKE_NUBMER(1);
    } else if (cell.type == MA_CELL_NO) {
      return MA_MAKE_NUBMER(0);
    } else if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT_STRING) {
        return MA_MAKE_NUBMER(std::stod(cell.v.object->d.string->data));
      }
    }
    M->stack.push(create_string(M, "Неможливо перетворити на число."));
    M->need_to_throw = true;
    return MA_MAKE_EMPTY();
  }

  void init_number(MaMa* M) {
    const auto number_structure_cell = create_structure(M, "число");
    M->global_scope->set_variable("число", number_structure_cell);
    M->number_structure_object = number_structure_cell.v.object;
    ma_object_set(
        number_structure_cell.v.object, MAG_CALL,
        create_diia_native(M, MAG_CALL,
                           number_structure_object_mag_call_native_diia_fn,
                           number_structure_cell.v.object));
  }
} // namespace mavka::mama