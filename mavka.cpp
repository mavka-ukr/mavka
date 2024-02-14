#include <filesystem>
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

  const auto& path = args[1];

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

  const auto frame = new MaCallFrame();
  frame->scope = S;
  M->call_stack.push(frame);
  init_print(M, S);

  M->code.push_back(
      MaInstruction{OP_TAKE, {.take = new MaTakeInstructionArgs(INT64_MAX,path)}});

  mavka::mama::run(M);

  return 0;
}