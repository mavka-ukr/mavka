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
  const auto diia_cell = create_diia_native(M, diia_native_fn, nullptr);
  ma_object_set(diia_cell.v.object, "назва", create_string(M, "друк"));
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
  M->global_scope = S;

  init_structure(M);
  init_diia(M);
  init_number(M);
  init_logical(M);
  init_text(M);
  init_list(M);
  init_dict(M);

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

  M->code.push_back(MaInstruction{OP_THROW});

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