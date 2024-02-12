#include "../../external/utf8/utf8.h"
#include "../mama.h"

// TODO: переписати це все

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

  MaCell ma_string_split_diia_native_fn(MaMa* M,
                                        MaObject* me,
                                        std::map<std::string, MaCell>& args) {
    M->stack.push(create_string(M, "Дія \"розбити\" тимчасово недоступна."));
    M->need_to_throw = true;
    return MA_MAKE_EMPTY();
  }

  MaCell ma_string_replace_diia_native_fn(MaMa* M,
                                          MaObject* me,
                                          std::map<std::string, MaCell>& args) {
    if (args.size() != 2) {
      M->stack.push(
          create_string(M, "Для дії \"замінити\" потрібно два аргументи."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
    const auto first = args.begin()->second;
    const auto second = (++args.begin())->second;
    const auto first_string = first.v.object->d.string->data;
    const auto second_string = second.v.object->d.string->data;
    std::string new_string;
    for (std::size_t i = 0; i < me->d.string->length(); i++) {
      const auto substr = me->d.string->substr(i, 1);
      if (substr == first_string) {
        new_string += second_string;
      } else {
        new_string += substr;
      }
    }
    return create_string(M, new_string);
  }

  MaCell ma_string_starts_with_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      M->stack.push(
          create_string(M, "Для дії \"починається\" потрібен аргумент."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
    const auto cell = args.begin()->second;
    if (IS_STRING(cell)) {
      if (me->d.string->data.find(cell.v.object->d.string->data) == 0) {
        return MA_MAKE_YES();
      }
      return MA_MAKE_NO();
    } else {
      M->stack.push(create_string(
          M, "Для дії \"починається\" потрібен текстовий аргумент."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
  }

  MaCell ma_string_ends_with_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      M->stack.push(
          create_string(M, "Для дії \"закінчується\" потрібен аргумент."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
    const auto cell = args.begin()->second;
    if (IS_STRING(cell)) {
      const auto str = cell.v.object->d.string;
      if (me->d.string->length() < str->length()) {
        return MA_MAKE_NO();
      }
      if (me->d.string->substr(me->d.string->length() - str->length(),
                               str->length()) == str->data) {
        return MA_MAKE_YES();
      }
      return MA_MAKE_NO();
    } else {
      M->stack.push(create_string(
          M, "Для дії \"закінчується\" потрібен текстовий аргумент."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
  }

  MaCell ma_string_trim_diia_native_fn(MaMa* M,
                                       MaObject* me,
                                       std::map<std::string, MaCell>& args) {
    return create_string(M, internal::tools::trim(me->d.string->data));
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

  MaCell ma_string_mag_contains_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    if (args.empty()) {
      return MA_MAKE_NO();
    }
    const auto cell = args.begin()->second;
    if (IS_STRING(cell)) {
      if (me->d.string->data.find(cell.v.object->d.string->data) !=
          std::string::npos) {
        return MA_MAKE_YES();
      }
      return MA_MAKE_NO();
    } else {
      M->stack.push(create_string(
          M, "Для дії \"чародія_містить\" потрібен текстовий аргумент."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
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

  MaCell ma_string_mag_iterator_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    M->stack.push(
        create_string(M, "Дія \"чародія_перебір\" тимчасово недоступна."));
    M->need_to_throw = true;
    return MA_MAKE_EMPTY();
  }

  MaCell ma_string_mag_number_diia_native_fn(
      MaMa* M,
      MaObject* me,
      std::map<std::string, MaCell>& args) {
    M->stack.push(
        create_string(M, "Дія \"чародія_число\" тимчасово недоступна."));
    M->need_to_throw = true;
    return MA_MAKE_EMPTY();
  }

  MaCell ma_string_get_handler(MaMa* M, MaObject* me, const std::string& name) {
    if (name == "довжина") {
      return MA_MAKE_INTEGER(me->d.string->length());
    }
    if (!me->properties.contains(name)) {
      M->stack.push(create_string(
          M, "Властивість \"" + name + "\" не визначено для типу \"текст\"."));
      M->need_to_throw = true;
      return MA_MAKE_EMPTY();
    }
    return me->properties[name];
  }

  MaCell create_string(MaMa* M, const std::string& value) {
    const auto string = new MaString();
    string->data = value;
    const auto string_cell =
        create_object(M, MA_OBJECT_STRING, M->text_structure_object, string);
    string_cell.v.object->get = ma_string_get_handler;
    ma_object_set(
        string_cell.v.object, "розбити",
        create_diia_native(M, "розбити", ma_string_split_diia_native_fn,
                           string_cell.v.object));
    ma_object_set(
        string_cell.v.object, "замінити",
        create_diia_native(M, "замінити", ma_string_replace_diia_native_fn,
                           string_cell.v.object));
    ma_object_set(string_cell.v.object, "починається",
                  create_diia_native(M, "починається",
                                     ma_string_starts_with_diia_native_fn,
                                     string_cell.v.object));
    ma_object_set(string_cell.v.object, "закінчується",
                  create_diia_native(M, "закінчується",
                                     ma_string_ends_with_diia_native_fn,
                                     string_cell.v.object));
    ma_object_set(string_cell.v.object, "обтяти",
                  create_diia_native(M, "обтяти", ma_string_trim_diia_native_fn,
                                     string_cell.v.object));
    ma_object_set(
        string_cell.v.object, MAG_ADD,
        create_diia_native(M, MAG_ADD, ma_string_mag_add_diia_native_fn,
                           string_cell.v.object));
    ma_object_set(string_cell.v.object, MAG_CONTAINS,
                  create_diia_native(M, MAG_CONTAINS,
                                     ma_string_mag_contains_diia_native_fn,
                                     string_cell.v.object));
    ma_object_set(string_cell.v.object, MAG_GET_ELEMENT,
                  create_diia_native(M, MAG_GET_ELEMENT,
                                     ma_string_mag_get_element_diia_native_fn,
                                     string_cell.v.object));
    ma_object_set(string_cell.v.object, MAG_ITERATOR,
                  create_diia_native(M, MAG_ITERATOR,
                                     ma_string_mag_iterator_diia_native_fn,
                                     string_cell.v.object));
    ma_object_set(string_cell.v.object, "чародія_число",
                  create_diia_native(M, "чародія_число",
                                     ma_string_mag_number_diia_native_fn,
                                     string_cell.v.object));
    return string_cell;
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
    const auto text_structure_cell = create_structure(M, "текст");
    M->global_scope->set_variable("текст", text_structure_cell);
    M->text_structure_object = text_structure_cell.v.object;
    ma_object_set(
        text_structure_cell.v.object, MAG_CALL,
        create_diia_native(M, MAG_CALL,
                           text_structure_object_mag_call_native_diia_fn,
                           text_structure_cell.v.object));
  }
} // namespace mavka::mama