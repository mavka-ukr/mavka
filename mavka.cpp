#include <fstream>
#include <iostream>
#include <string>
#include "mama/mama.h"

using namespace mavka::mama;

void init_empty(MaMa* M) {}

void init_number(MaMa* M, MaScope* gS) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_STRUCTURE;
  ma_object_set(ma_object, "назва", create_string("число"));
  const auto number_structure_cell =
      MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  gS->set_variable("число", number_structure_cell);
}

MaCell text_structure_object_mag_call_native_diia_fn(
    MaMa* M,
    MaObject* me,
    std::map<std::string, MaCell>& args) {
  if (args.empty()) {
    return create_string("");
  }
  const auto cell = args.begin()->second;
  if (cell.type == MA_CELL_EMPTY) {
    return create_string("пусто");
  } else if (cell.type == MA_CELL_NUMBER) {
    return create_string(ma_number_to_string(cell.v.number));
  } else if (cell.type == MA_CELL_YES) {
    return create_string("так");
  } else if (cell.type == MA_CELL_NO) {
    return create_string("ні");
  } else if (cell.type == MA_CELL_OBJECT) {
    if (cell.v.object->type == MA_OBJECT_STRING) {
      return cell;
    }
    if (cell.v.object->structure) {
      return create_string(ma_object_get(cell.v.object->structure, "назва")
                               .v.object->d.string->data);
    }
  }
  return create_string("");
}

void init_text(MaMa* M, MaScope* gS) {
  const auto text_structure_object = new MaObject();
  text_structure_object->type = MA_OBJECT_STRUCTURE;
  ma_object_set(text_structure_object, "назва", create_string("текст"));
  ma_object_set(
      text_structure_object, MAG_CALL,
      create_diia_native(text_structure_object_mag_call_native_diia_fn));

  const auto text_structure = new MaStructure();
  text_structure_object->d.structure = text_structure;

  const auto text_structure_cell =
      MaCell{MA_CELL_OBJECT, {.object = text_structure_object}};

  gS->set_variable("текст", text_structure_cell);
}

void init_logical(MaMa* M) {}

void init_diia(MaMa* M) {}

void init_print(MaMa* M, MaScope* S) {
  const auto diia_native_fn = [](MaMa* M, MaObject* me,
                                 std::map<std::string, MaCell>& args) {
    for (const auto& [key, value] : args) {
      std::cout << cell_to_string(value) << std::endl;
    }
    return MA_MAKE_EMPTY();
  };
  const auto diia_cell = create_diia_native(diia_native_fn);
  ma_object_set(diia_cell.v.object, "назва", create_string("друк"));
  S->set_variable("друк", diia_cell);
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);

  if (args.size() == 1) {
    std::cout << "Використання: мавка <файл.м>" << std::endl;
    return 1;
  }

  const auto& filename = args[1];

  auto file = std::ifstream(filename);
  if (!file.is_open()) {
    std::cout << "Не вдалося прочитати файл " << filename << std::endl;
    return 1;
  }
  const auto source = std::string(std::istreambuf_iterator<char>(file),
                                  std::istreambuf_iterator<char>());

  const auto M = new MaMa();
  const auto S = new MaScope(nullptr);

  init_empty(M);
  init_number(M, S);
  init_text(M, S);
  init_logical(M);
  init_diia(M);

  const auto frame = new MaCallFrame();
  frame->scope = S;
  M->call_stack.push(frame);
  init_print(M, S);

  mavka::parser::MavkaParserResult program_parser_result;
  try {
    program_parser_result = mavka::parser::parse(source, filename);
    if (!program_parser_result.errors.empty()) {
      for (const auto& error : program_parser_result.errors) {
        std::cout << error.path << ":" << error.line << ":" << error.column
                  << ": " << error.message << std::endl;
      }
      return 1;
    }
  } catch (std::exception& e) {
    std::cout << "Помилка парсингу: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cout << "Невідома помилка парсингу." << std::endl;
    return 1;
  }

  for (const auto& node : program_parser_result.program_node->body) {
    const auto result = compile_node(M, node);
    if (result.error) {
      std::cout << result.error->message << std::endl;
      return 1;
    }
  }

  DEBUG_DO({
    print_code(M);
    std::cout << "---" << std::endl;
    M;
  })

  mavka::mama::run(M);

  // while (M->stack.size()) {
  //   const auto value = M->stack.top();
  //   M->stack.pop();
  //   print_cell(value);
  // }

  return 0;
}