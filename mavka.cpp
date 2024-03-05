#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "lib_bundle.h"
#include "mama/src/mama.h"

using namespace mavka::mama;

std::string cell_to_string(MaCell cell, int depth = 0);

std::string cell_to_string(MaCell cell, int depth) {
  if (IS_EMPTY(cell)) {
    return "пусто";
  }
  if (IS_NUMBER(cell)) {
    if (std::isinf(cell.AsNumber())) {
      return "нескінченність";
    }
    if (std::isnan(cell.AsNumber())) {
      return "невизначеність";
    }
    return ma_number_to_string(cell.v.number);
  }
  if (IS_YES(cell)) {
    return "так";
  }
  if (IS_NO(cell)) {
    return "ні";
  }
  if (IS_OBJECT(cell)) {
    if (cell.v.object->type == MA_OBJECT) {
      std::vector<std::string> items;
      for (const auto& param : cell.v.object->structure->d.structure->params) {
        const auto value = cell.v.object->GetProperty(param.name);
        items.push_back(param.name + "=" + cell_to_string(value, depth + 1));
      }
      return cell.v.object->structure->d.structure->name + "(" +
             mavka::internal::tools::implode(items, ", ") + ")";
    }
    if (cell.v.object->type == MA_OBJECT_DIIA) {
      const auto name = cell.v.object->d.diia->name;
      if (name == "") {
        return "<дія>";
      }
      return "<дія " + name + ">";
    }
    if (cell.v.object->type == MA_OBJECT_NATIVE) {
      const auto name = cell.v.object->d.native->name;
      if (name == "") {
        return "<дія>";
      }
      return "<дія " + name + ">";
    }
    if (cell.v.object->type == MA_OBJECT_STRING) {
      if (depth > 0) {
        return "\"" + cell.v.object->d.text->data + "\"";
      }
      return cell.v.object->d.text->data;
    }
    if (cell.v.object->type == MA_OBJECT_LIST) {
      std::vector<std::string> items;
      for (const auto& item : cell.v.object->d.list->data) {
        items.push_back(cell_to_string(item, depth + 1));
      }
      return "[" + mavka::internal::tools::implode(items, ", ") + "]";
    }
    if (cell.v.object->type == MA_OBJECT_DICT) {
      std::vector<std::string> items;
      for (const auto& item : cell.v.object->d.dict->data) {
        items.push_back(cell_to_string(item.first, depth + 1) + "=" +
                        cell_to_string(item.second, depth + 1));
      }
      return "(" + mavka::internal::tools::implode(items, ", ") + ")";
    }
    if (cell.v.object->type == MA_OBJECT_STRUCTURE) {
      return "<структура " + cell.v.object->d.structure->name + ">";
    }
    if (cell.v.object->type == MA_OBJECT_MODULE) {
      const auto name = cell.v.object->d.module->name;
      std::vector<std::string> items;
      for (const auto& [k, v] : cell.v.object->properties) {
        if (k != "назва") {
          items.push_back(k);
        }
      }
      return "<модуль " + name + "[" +
             mavka::internal::tools::implode(items, ", ") + "]>";
    }
  }
  if (IS_ARGS(cell)) {
    return "<аргументи>";
  }
  if (IS_ERROR(cell)) {
    return "<помилка>";
  }
  return "<невідомо>";
}

void init_print(MaMa* M) {
  const auto native_fn = [](MaMa* M, MaObject* me, MaArgs* args,
                            const MaLocation& location) {
    if (args->type == MA_ARGS_TYPE_POSITIONED) {
      for (const auto& arg : args->positioned) {
        std::cout << cell_to_string(arg) << std::endl;
      }
    } else {
      for (const auto& [key, value] : args->named) {
        std::cout << key << ": " << cell_to_string(value) << std::endl;
      }
    }
    return MaCell::Empty();
  };
  M->global_scope->SetSubject("друк",
                              MaNative::Create(M, "друк", native_fn, nullptr));
}

void init_read(MaMa* M) {
  const auto native_fn = [](MaMa* M, MaObject* me, MaArgs* args,
                            const MaLocation& location) {
    const auto prefix = args->Get(0, "префікс");
    if (prefix.IsObject() && prefix.IsObjectText()) {
      std::cout << prefix.AsText()->data;
    }
    std::string value;
    getline(std::cin, value);
    if (std::cin.eof()) {
      return MaCell::Empty();
    }
    return MaCell::Object(MaText::Create(M, value));
  };
  M->global_scope->SetSubject(
      "читати", MaNative::Create(M, "читати", native_fn, nullptr));
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

MaCell TakePath(MaMa* M,
                const std::string& raw_path,
                const MaLocation& location) {
  const auto canonical_path = std::filesystem::weakly_canonical(raw_path);
  const auto path = canonical_path.string();
  if (!std::filesystem::exists(canonical_path)) {
    return MaCell::Error(MaError::Create(
        M, "Шлях \"" + canonical_path.string() + "\" не існує.", location));
  }
  if (!std::filesystem::is_regular_file(canonical_path)) {
    return MaCell::Error(MaError::Create(
        M, "Шлях \"" + path + "\" не вказує на файл.", location));
  }

  if (M->loaded_file_modules.contains(path)) {
    return MaCell::Object(M->loaded_file_modules[path]);
  }

  auto file = std::ifstream(path);
  if (!file.is_open()) {
    return MaCell::Error(MaError::Create(
        M, "Не вдалося прочитати файл \"" + path + "\".", location));
  }

  const auto fs_path = std::filesystem::path(path);
  const auto name = fs_path.stem().string();

  const auto source = std::string(std::istreambuf_iterator(file),
                                  std::istreambuf_iterator<char>());

  return M->DoTake(path, name, source, location);
}

MaCell TakeFn(MaMa* M,
              const std::string& repository,
              bool relative,
              const std::vector<std::string>& parts,
              const MaLocation& location) {
  if (repository == "біб") {
    const auto path =
        "біб/" + mavka::internal::tools::implode(parts, "/") + ".м";
    if (lib_modules.contains(path)) {
      if (M->loaded_file_modules.contains(path)) {
        return MaCell::Object(M->loaded_file_modules[path]);
      }
      const auto name = parts.back();
      return M->DoTake(path, name, lib_modules[path], location);
    }
    return MaCell::Error(MaError::Create(
        M, "Модуль \"" + path + "\" не знайдено в бібліотеці.", location));
  }
  if (!repository.empty()) {
    return MaCell::Error(
        MaError::Create(M, "Не підтримується взяття з репозиторію.", location));
  }
  if (relative) {
    return MaCell::Error(MaError::Create(
        M, "Не підтримується взяття відносного шляху.", location));
  }
  const auto cwd = std::filesystem::current_path();
  const auto raw_path =
      cwd.string() + "/" + mavka::internal::tools::implode(parts, "/") + ".м";
  return TakePath(M, raw_path, location);
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);

  const auto M = MaMa::Create();
  M->TakeFn = TakeFn;

  init_print(M);
  init_read(M);

  if (args.size() == 1) {
    const auto take_result = M->TakeFn(M, "біб", false, {"вбудоване", "ірм"}, {});
    if (take_result.IsError()) {
      std::cerr << cell_to_string(take_result.v.error->value) << std::endl;
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
      std::cerr << cell_to_string(take_result.v.error->value) << std::endl;
      return 1;
    }
  }

  return 0;
}