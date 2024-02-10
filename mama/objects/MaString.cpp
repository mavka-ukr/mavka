#include "../mama.h"

namespace mavka::mama {
  std::size_t utf8_len(const std::string& utf8) {
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
        .from_bytes(utf8)
        .size();
  }

  size_t MaString::length() const {
    return utf8_len(this->data);
  }

  MaCell ma_string_mag_add_diia_native_fn(MaMa* M,
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

  MaCell ma_string_mag_get_element_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return MA_MAKE_EMPTY();
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_NUMBER) {
      const auto i = cell.v.number;
      if (i < me->d.string->length()) {
        const auto substr = me->d.string->data.substr(i, 1);
        return create_string(substr);
      }
    }
    return MA_MAKE_EMPTY();
  }
} // namespace mavka::mama