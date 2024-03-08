#include "mavka.h"

using namespace mavka;

void init_print(MaMa* M) {
  const auto native_fn = [](MaMa* M, MaObject* native_o, MaArgs* args,
                            const MaLocation& location) {
    if (args->type == MA_ARGS_TYPE_POSITIONED) {
      for (const auto& arg : args->positioned) {
        std::cout << cell_to_string(M, arg) << std::endl;
      }
    } else {
      for (const auto& [key, value] : args->named) {
        std::cout << key << ": " << cell_to_string(M, value) << std::endl;
      }
    }
    return MaValue::Empty();
  };
  M->global_scope->SetSubject("друк",
                              MaNative::Create(M, "друк", native_fn, nullptr));
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

  const auto M = MaMa::Create();
  M->TakeFn = TakeFn;
  M->global_scope->SetSubject("версія_мавки", MaText::Create(M, MAVKA_VERSION));

  init_print(M);

  if (args.size() == 1) {
    const auto take_result =
        M->TakeFn(M, "біб", false, {"вбудоване", "діалог"}, {});
    if (take_result.IsError()) {
      std::cerr << cell_to_string(M, take_result.v.error->value) << std::endl;
      return 1;
    }
    return 0;
  } else {
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

    const auto take_result = TakePath(M, path, {});
    if (take_result.IsError()) {
      std::cerr << cell_to_string(M, take_result.v.error->value) << std::endl;
      return 1;
    }
  }

  return 0;
}