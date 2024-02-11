#include "../../external/utf8/utf8.h"
#include "../mama.h"

namespace mavka::mama {
  std::size_t utf8_len(const std::string& str) {
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
        .from_bytes(str)
        .size();
  }

  std::string utf8_substr(const std::string& str,
                          std::size_t start,
                          std::size_t length) {
    const auto utf32 =
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
            .from_bytes(str);
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
        .to_bytes(utf32.substr(start, length));
  }

  std::vector<std::string> utf8_chars(const std::string& str) {
    const auto utf32 =
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
            .from_bytes(str);
    std::vector<std::string> chars;
    for (const auto& c : utf32) {
      chars.push_back(
          std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
              .to_bytes(c));
    }
    return chars;
  }

  size_t utf8_find_index(const std::string& str, const std::string& substr) {
    const auto utf32 =
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
            .from_bytes(str);
    const auto utf32_substr =
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
            .from_bytes(substr);
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}
        .to_bytes(utf32.substr(0, utf32.find(utf32_substr)))
        .size();
  }

  size_t MaString::length() const {
    return utf8_len(this->data);
  }

  std::string MaString::substr(size_t start, size_t length) const {
    return utf8_substr(this->data, start, length);
  }

  std::vector<std::string> MaString::split(const std::string& delim) const {
    throw std::runtime_error("Not implemented");
  }

  MaCell ma_string_mag_add_diia_native_fn(MaMa* M,
                                          MaObject* me,
                                          std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return MA_MAKE_OBJECT(me);
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_EMPTY) {
      return create_string(M, me->d.string->data + "пусто");
    }
    if (cell.type == MA_CELL_NUMBER) {
      return create_string(
          M, me->d.string->data + ma_number_to_string(cell.v.number));
    }
    if (cell.type == MA_CELL_YES) {
      return create_string(M, me->d.string->data + "так");
    }
    if (cell.type == MA_CELL_NO) {
      return create_string(M, me->d.string->data + "ні");
    }
    if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT_STRING) {
        return create_string(
            M, me->d.string->data + cell.v.object->d.string->data);
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
        const auto substr = me->d.string->substr(i, 1);
        return create_string(M, substr);
      }
    }
    return MA_MAKE_EMPTY();
  }

  MaCell ma_string_split_diia_native_fn(MaMa* M,
                                        MaObject* me,
                                        std::map<std::string, MaCell>& args) {
    MaCell delim{};
    if (args.contains("0")) {
      delim = args["0"];
    } else {
      delim = create_string(M, "");
    }
    const auto list_cell = create_list(M);
    const auto parts = me->d.string->split(delim.v.object->d.string->data);
    for (const auto& part : parts) {
      list_cell.v.object->d.list->append(create_string(M, part));
    }
    return list_cell;
  }

  MaCell create_string(MaMa* M, const std::string& value) {
    const auto ma_object = new MaObject();
    ma_object->type = MA_OBJECT_STRING;
    const auto ma_string = new MaString();
    ma_string->data = value;
    ma_object->d.string = ma_string;
    ma_object->get = [](MaObject* me, const std::string& name) {
      if (name == "довжина") {
        return MA_MAKE_INTEGER(me->d.string->length());
      }
      return ma_object_get(me, name);
    };
    ma_object_set(
        ma_object, MAG_ADD,
        create_diia_native(M, ma_string_mag_add_diia_native_fn, ma_object));
    ma_object_set(ma_object, MAG_GET_ELEMENT,
                  create_diia_native(
                      M, ma_string_mag_get_element_diia_native_fn, ma_object));
    ma_object_set(
        ma_object, "розбити",
        create_diia_native(M, ma_string_split_diia_native_fn, ma_object));
    return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  }

  MaCell text_structure_object_mag_call_native_diia_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return create_string(M, "");
    }
    const auto cell = args.begin()->second;
    if (cell.type == MA_CELL_EMPTY) {
      return create_string(M, "пусто");
    } else if (cell.type == MA_CELL_NUMBER) {
      return create_string(M, ma_number_to_string(cell.v.number));
    } else if (cell.type == MA_CELL_YES) {
      return create_string(M, "так");
    } else if (cell.type == MA_CELL_NO) {
      return create_string(M, "ні");
    } else if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT_STRING) {
        return cell;
      }
    }
    M->stack.push(create_string(M, "Неможливо перетворити на текст."));
    M->need_to_throw = true;
    return MA_MAKE_EMPTY();
  }

  void init_text(MaMa* M) {
    const auto text_structure_object = new MaObject();
    text_structure_object->type = MA_OBJECT_STRUCTURE;
    text_structure_object->structure = M->structure_structure_object;
    const auto text_structure = new MaStructure();
    text_structure_object->d.structure = text_structure;
    ma_object_set(text_structure_object, "назва", create_string(M, "текст"));
    ma_object_set(
        text_structure_object, MAG_CALL,
        create_diia_native(M, text_structure_object_mag_call_native_diia_fn));
    const auto text_structure_cell =
        MaCell{MA_CELL_OBJECT, {.object = text_structure_object}};
    M->global_scope->set_variable("текст", text_structure_cell);
    M->text_structure_object = text_structure_object;
  }
} // namespace mavka::mama