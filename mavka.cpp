#include <fstream>
#include <iostream>
#include <string>
#include "mama/mama.h"

using namespace mavka::mama;

void init_print(MaMa* M, MaScope* S) {
  const auto diia_native_fn = [](MaMa* M, MaObject* me,
                                 std::map<std::string, MaCell>& args) {
    for (const auto& [key, value] : args) {
      std::cout << cell_to_string(value) << std::endl;
    }
    return MA_MAKE_EMPTY();
  };
  const auto diia_cell = create_diia_native(M, "друк", diia_native_fn, nullptr);
  S->set_variable("друк", diia_cell);
}

void print_help() {
  std::cout << R"(Використання:
  мавка [...опції] <модуль.м> [...аргументи]
  мавка [...опції] <команда> [...аргументи]

Доступні команди:
  <модуль.м> — виконати модуль
    Опції: немає

  версія — показати версію Мавки
    Опції: немає

  допомога — показати це повідолення
    Опції: немає)"
            << std::endl;
}

void print_version() {
  std::cout << "0.100.0" << std::endl;
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);

  if (args.size() == 1) {
    print_help();
    return 1;
  }

  if (args.size() == 2) {
    const auto command = args[1];
    if (command == "допомога") {
      print_help();
      return 0;
    }
    if (command == "версія") {
      print_version();
      return 0;
    }
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
  M->global_scope = S;

  init_structure(M);
  init_object(M);
  init_diia(M);
  init_module(M);
  init_number(M);
  init_logical(M);
  init_text(M);
  init_list(M);
  init_dict(M);
  init_structure_2(M);

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
      std::cout << filename << ":" << result.error->line << ":"
                << result.error->column << ": " << result.error->message
                << std::endl;
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