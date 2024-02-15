#include <csetjmp>

#include "../../external/utf8/utf8.h"
#include "../mama.h"

// TODO: переписати це все

namespace mavka::mama {

  static jmp_buf buf;

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

  void ma_string_split_diia_native_fn(MaMa* M, MaObject* me, MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "роздільник", MA_MAKE_EMPTY());
    if (IS_STRING(cell)) {
      const auto delim = cell.v.object->d.string->data;
      if (delim.empty()) {
        const auto list = create_list(M);
        for (const auto& c : utf8_chars(me->d.string->data)) {
          list.v.object->d.list->data.push_back(create_string(M, c));
        }
        M->stack.push(list);
        return;
      }
      std::vector<std::string> result;
      std::string current;
      for (const auto& c : utf8_chars(me->d.string->data)) {
        if (c == delim) {
          result.push_back(current);
          current.clear();
        } else {
          current += c;
        }
      }
      result.push_back(current);
      const auto list = create_list(M);
      for (const auto& s : result) {
        list.v.object->d.list->data.push_back(create_string(M, s));
      }
      M->stack.push(list);
    } else {
      M->stack.push(
          create_string(M, "Для дії \"розбити\" потрібен текстовий аргумент."));
      M->diia_native_throw = true;
    }
  }

  void ma_string_replace_diia_native_fn(MaMa* M, MaObject* me, MaArgs* args) {
    const auto first = FRAME_GET_ARG(args, 0, "старе", MA_MAKE_EMPTY());
    if (!IS_STRING(first)) {
      M->stack.push(create_string(
          M, "Для дії \"замінити\" перший аргумент повинен бути текстом."));
      M->diia_native_throw = true;
      return;
    }
    const auto second = FRAME_GET_ARG(args, 1, "нове", MA_MAKE_EMPTY());
    if (!IS_STRING(second)) {
      M->stack.push(create_string(
          M, "Для дії \"замінити\" другий аргумент повинен бути текстом."));
      M->diia_native_throw = true;
      return;
    }
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
    M->stack.push(create_string(M, new_string));
  }

  void ma_string_starts_with_diia_native_fn(MaMa* M,
                                            MaObject* me,
                                            MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_STRING(cell)) {
      if (me->d.string->data.find(cell.v.object->d.string->data) == 0) {
        M->stack.push(MA_MAKE_YES());
        return;
      }
      M->stack.push(MA_MAKE_NO());
      return;
    } else {
      M->stack.push(create_string(
          M, "Для дії \"починається\" потрібен текстовий аргумент."));
      M->diia_native_throw = true;
    }
  }

  void ma_string_ends_with_diia_native_fn(MaMa* M, MaObject* me, MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_STRING(cell)) {
      const auto str = cell.v.object->d.string;
      if (me->d.string->length() < str->length()) {
        M->stack.push(MA_MAKE_NO());
        return;
      }
      if (me->d.string->substr(me->d.string->length() - str->length(),
                               str->length()) == str->data) {
        M->stack.push(MA_MAKE_YES());
        return;
      }
      M->stack.push(MA_MAKE_NO());
      return;
    } else {
      M->stack.push(create_string(
          M, "Для дії \"закінчується\" потрібен текстовий аргумент."));
      M->diia_native_throw = true;
    }
  }

  void ma_string_trim_diia_native_fn(MaMa* M, MaObject* me, MaArgs* args) {
    M->stack.push(create_string(M, internal::tools::trim(me->d.string->data)));
  }

  void ma_string_mag_add_diia_native_fn(MaMa* M, MaObject* me, MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (cell.type == MA_CELL_EMPTY) {
      M->stack.push(create_string(M, me->d.string->data + "пусто"));
      return;
    }
    if (cell.type == MA_CELL_NUMBER) {
      M->stack.push(create_string(
          M, me->d.string->data + ma_number_to_string(cell.v.number)));
      return;
    }
    if (cell.type == MA_CELL_YES) {
      M->stack.push(create_string(M, me->d.string->data + "так"));
      return;
    }
    if (cell.type == MA_CELL_NO) {
      M->stack.push(create_string(M, me->d.string->data + "ні"));
      return;
    }
    if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT_STRING) {
        M->stack.push(create_string(
            M, me->d.string->data + cell.v.object->d.string->data));
        return;
      }
    }
    M->stack.push(create_string(M, "Неможливо додати до тексту обʼєкт типу \"" +
                                       getcelltypename(cell) + "\"."));
    M->diia_native_throw = true;
  }

  void ma_string_mag_contains_diia_native_fn(MaMa* M,
                                             MaObject* me,
                                             MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_STRING(cell)) {
      if (me->d.string->data.find(cell.v.object->d.string->data) !=
          std::string::npos) {
        M->stack.push(MA_MAKE_YES());
        return;
      }
      M->stack.push(MA_MAKE_NO());
      return;
    } else {
      M->stack.push(create_string(
          M, "Для дії \"чародія_містить\" потрібен текстовий аргумент."));
      M->diia_native_throw = true;
    }
  }

  void ma_string_mag_get_element_diia_native_fn(MaMa* M,
                                                MaObject* me,
                                                MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "позиція", MA_MAKE_EMPTY());
    if (cell.type == MA_CELL_NUMBER) {
      const auto i = cell.v.number;
      if (i < me->d.string->length()) {
        const auto substr = me->d.string->substr(i, 1);
        M->stack.push(create_string(M, substr));
        return;
      }
    }
    M->stack.push(MA_MAKE_EMPTY());
  }

  void ma_string_mag_iterator_diia_native_fn(MaMa* M,
                                             MaObject* me,
                                             MaArgs* args) {
    M->stack.push(create_string(
        M, "Дія \"" + std::string(MAG_ITERATOR) + "\" тимчасово недоступна."));
    M->diia_native_throw = true;
  }

  void ma_string_mag_number_diia_native_fn(MaMa* M,
                                           MaObject* me,
                                           MaArgs* args) {
    M->stack.push(MA_MAKE_NUMBER(std::stod(me->d.string->data)));
  }

  MaCell ma_string_get_handler(MaMa* M, MaObject* me, const std::string& name) {
    if (name == "довжина") {
      return MA_MAKE_INTEGER(me->d.string->length());
    }
    if (!me->properties.contains(name)) {
      M->stack.push(create_string(
          M, "Властивість \"" + name + "\" не визначено для типу \"текст\"."));
      M->diia_native_throw = true;
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
    ma_object_set(
        string_cell.v.object, MAG_NUMBER,
        create_diia_native(M, MAG_NUMBER, ma_string_mag_number_diia_native_fn,
                           string_cell.v.object));
    return string_cell;
  }

  void text_structure_object_mag_call_diia_native_fn(MaMa* M,
                                                     MaObject* me,
                                                     MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (IS_STRING(cell)) {
      PUSH(create_string(M, "пусто"));
      return;
    }
    if (IS_NUMBER(cell)) {
      PUSH(create_string(M, ma_number_to_string(cell.v.number)));
      return;
    }
    if (IS_YES(cell)) {
      PUSH(create_string(M, "так"));
      return;
    }
    if (IS_NO(cell)) {
      PUSH(create_string(M, "ні"));
      return;
    }
    if (IS_OBJECT(cell)) {
      if (cell.v.object->type == MA_OBJECT_STRING) {
        PUSH(cell);
        return;
      } else if (OBJECT_HAS(cell.v.object, MAG_TEXT)) {
        PUSH(cell.v.object->properties[MAG_TEXT]);
        M->diia_native_callback = [](MaMa* M) {
          POP_VALUE(mag_number_diia_cell);
          READ_TOP_FRAME();
          if (initcall(M, MA_ARGS_POSITIONED, mag_number_diia_cell,
                       {.return_index = frame->data.call->return_index,
                        .line = frame->data.call->line,
                        .column = frame->data.call->column})) {
            M->diia_native_repeat = true;
          } else {
            PUSH(create_string(M, "Неможливо перетворити на текст."));
            M->diia_native_throw = true;
          }
        };
        return;
      }
    }
    M->stack.push(create_string(M, "Неможливо перетворити на текст."));
    M->diia_native_throw = true;
  }

  void init_text(MaMa* M) {
    const auto text_structure_cell = create_structure(M, "текст");
    M->global_scope->set_variable("текст", text_structure_cell);
    M->text_structure_object = text_structure_cell.v.object;
    ma_object_set(
        text_structure_cell.v.object, MAG_CALL,
        create_diia_native(M, MAG_CALL,
                           text_structure_object_mag_call_diia_native_fn,
                           text_structure_cell.v.object));
  }
} // namespace mavka::mama