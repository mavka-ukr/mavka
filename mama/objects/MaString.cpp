#include "../mama.h"

namespace mavka::mama {
  MaCell ma_string_mag_diia_native_fn(MaMa* M,
                                      MaObject* me,
                                      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return MA_MAKE_OBJECT(me);
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_EMPTY) {
      return create_string(me->d.string->data + "пусто");
    }
    if (cell.type == MA_CELL_NUMBER) {
      return create_string(me->d.string->data +
                           ma_number_to_string(cell.v.number));
    }
    if (cell.type == MA_CELL_YES) {
      return create_string(me->d.string->data + "так");
    }
    if (cell.type == MA_CELL_NO) {
      return create_string(me->d.string->data + "ні");
    }
    if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT_STRING) {
        return create_string(me->d.string->data +
                             cell.v.object->d.string->data);
      }
    }
    return MA_MAKE_OBJECT(me);
  }
} // namespace mavka::mama