#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "mama/mama.h"

using namespace mavka::mama;

void init_print(MaMa* M, MaScope* S) {
  const auto diia_native_fn = [](MaMa* M, MaObject* me, MaArgs* args) {
    if (args->type == MA_ARGS_POSITIONED) {
      for (const auto& arg : args->positioned) {
        std::cout << cell_to_string(arg) << std::endl;
      }
    } else {
      for (const auto& [key, value] : args->named) {
        std::cout << key << ": " << cell_to_string(value) << std::endl;
      }
    }
    M->stack.push(MA_MAKE_EMPTY());
    return;
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
  std::cout << MAVKA_VERSION << std::endl;
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);
  const auto cwd = std::filesystem::current_path();

  const auto M = new MaMa();
  M->cwd = cwd;
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

  const auto frame = new MaFrame(FRAME_TYPE_ROOT);
  frame->scope = S;
  M->frames.push(frame);
  init_print(M, S);

  if (args.size() == 1) {
    std::cout << "Експериментальна Мавка " << MAVKA_VERSION << std::endl;
    std::string line;
    do {
      std::cout << "› ";
      std::getline(std::cin, line);
      if (line == "вийти") {
        return 0;
      }
      const auto parser_result = mavka::parser::parse(line, "[консоль]");
      if (!parser_result.errors.empty()) {
        const auto error = parser_result.errors[0];
        std::cout << error.path + ":" + std::to_string(error.line) + ":" +
                         std::to_string(error.column) + ": " + error.message
                  << std::endl;
        continue;
      }
      const auto line_code = new MaCode();
      const auto body_compilation_result =
          compile_body(M, line_code, parser_result.program_node->body, true);
      if (body_compilation_result.error) {
        std::cout << "[консоль]:" +
                         std::to_string(body_compilation_result.error->line) +
                         ":" +
                         std::to_string(body_compilation_result.error->column) +
                         ": " + body_compilation_result.error->message
                  << std::endl;
        continue;
      }
      const auto restore_stack_size = M->stack.size();
      mavka::mama::run(M, line_code, 0);
      const auto result = M->stack.top();
      mavka::mama::restore_stack(M, restore_stack_size);
      std::cout << cell_to_string(result) << std::endl;
    } while (true);
    return 1;
  } else if (args.size() == 2) {
    const auto& command = args[1];
    if (command == "допомога") {
      print_help();
      return 0;
    }
    if (command == "версія") {
      print_version();
      return 0;
    }

    const auto& path = args[1];

    mavka::mama::run(
        M,
        new MaCode(
            {.instructions = {MaInstruction{
                 OP_TAKE,
                 {.take = new MaTakeInstructionArgs(INT64_MAX, path)}}}}),
        0);
  } else {
    print_help();
    return 1;
  }

  return 0;
}