#include "mama/src/takeFs.h"
#include "mavka.h"

using namespace mavka;

MaValue take_fn(MaMa* M,
                const std::string& repository,
                bool relative,
                const std::vector<std::string>& parts,
                size_t li) {
  if (repository == "біб") {
    return TakeBib(M, parts, li);
  }
  return maTakeFsFn(M, repository, relative, parts, li);
}

void init_print(MaMa* M) {
  const auto native_fn = [](MaMa* M, MaObject* native_o, MaObject* args,
                            size_t li) {
    for (const auto& [key, value] : args->properties) {
      std::cout << cell_to_string(M, value) << std::endl;
    }
    return MaValue::Empty();
  };
  M->global_scope->setProperty(M, "друк",
                               MaDiia::Create(M, "друк", native_fn, nullptr));
}

void print_help() {
  std::cout << R"(Використання:
  мавка
  мавка [...опції] <модуль.м> [...аргументи]
  мавка [...опції] <команда> [...аргументи]

Доступні команди:
  <без команди> — запустити Діалог
    Опції: немає

  <модуль.м> — виконати модуль за шляхом
    Опції: немає

  взяти [|біб|пак|...] <а.б.в> — виконати модуль вказівкою взяти
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

void print_error_with_trace(MaMa* M, const MaValue& value) {
  const auto stackTrace = M->getStackTrace();
  if (!stackTrace.empty()) {
    std::cout << stackTrace << std::endl;
  }
  const auto location = M->locations[value.asError()->li];
  std::cerr << location.path << ":" << location.line << ":" << location.column
            << ": " << cell_to_string(M, value.v.error->value) << std::endl;
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);

  const auto M = MaMa::Create();
  M->take_fn = take_fn;
  M->global_scope->setProperty(M, "версія_мавки",
                               MaText::Create(M, MAVKA_VERSION));

  init_print(M);

  if (args.size() == 1) {
    const auto take_result = M->take("біб", false, {"вбудоване", "діалог"}, {});
    if (take_result.isError()) {
      print_error_with_trace(M, take_result);
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
    if (command == "взяти") {
      const auto& repo = args[2];
      if (repo == "біб" || repo == "пак") {
        const auto take_parts = mavka::internal::tools::explode(args[3], ".");
        const auto take_result = take_fn(M, repo, false, take_parts, {});
        if (take_result.isError()) {
          print_error_with_trace(M, take_result);
          return 1;
        }
      } else {
        const auto take_parts = mavka::internal::tools::explode(args[2], ".");
        const auto take_result = take_fn(M, "", false, take_parts, {});
        if (take_result.isError()) {
          print_error_with_trace(M, take_result);
          return 1;
        }
      }
    } else {
      const auto take_result = maTakeFsPath(M, args[1], true, {});
      if (take_result.isError()) {
        print_error_with_trace(M, take_result);
        return 1;
      }
    }
  }

  return 0;
}