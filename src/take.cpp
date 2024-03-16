#include "mavka.h"

namespace mavka {
#include "../MAVKA_LIB_MODULES.h"

  MaValue TakeBib(MaMa* M, const std::vector<std::string>& parts, size_t li) {
    const auto full_path =
        "біб/" + mavka::internal::tools::implode(parts, "/") + ".м";
    if (M->loaded_file_modules.contains(full_path)) {
      return MaValue::Object(M->loaded_file_modules[full_path]);
    }
    if (full_path == "біб/читати.м") {
      const auto read_module_object = BibInitReadModule(M);
      M->loaded_file_modules[full_path] = read_module_object;
      return MaValue::Object(read_module_object);
    }
    if (full_path == "біб/мавка.м") {
      const auto mavka_module_object = BibInitMavkaModule(M);
      M->loaded_file_modules[full_path] = mavka_module_object;
      return MaValue::Object(mavka_module_object);
    }
    if (full_path == "біб/сфс.м") {
      const auto fss_module_object = BibInitFsSyncModule(M);
      M->loaded_file_modules[full_path] = fss_module_object;
      return MaValue::Object(fss_module_object);
    }
    if (MAVKA_LIB_MODULES.contains(full_path)) {
      const auto& name = parts.back();
      return M->doTake(full_path, name, MAVKA_LIB_MODULES[full_path], li);
    }
    return MaValue::Error(MaError::Create(
        M, "Модуль \"" + full_path + "\" не знайдено в бібліотеці.", li));
  }

  MaValue TakePath(MaMa* M, const std::string& raw_path, size_t li) {
    const auto canonical_path = std::filesystem::weakly_canonical(raw_path);
    const auto path = canonical_path.string();
    if (!std::filesystem::exists(canonical_path)) {
      return MaValue::Error(MaError::Create(
          M, "Шлях \"" + canonical_path.string() + "\" не існує.", li));
    }
    if (!std::filesystem::is_regular_file(canonical_path)) {
      return MaValue::Error(
          MaError::Create(M, "Шлях \"" + path + "\" не вказує на файл.", li));
    }

    if (M->loaded_file_modules.contains(path)) {
      return MaValue::Object(M->loaded_file_modules[path]);
    }

    auto file = std::ifstream(path);
    if (!file.is_open()) {
      return MaValue::Error(MaError::Create(
          M, "Не вдалося прочитати файл \"" + path + "\".", li));
    }

    const auto fs_path = std::filesystem::path(path);
    const auto name = fs_path.stem().string();

    const auto source = std::string(std::istreambuf_iterator(file),
                                    std::istreambuf_iterator<char>());

    return M->doTake(path, name, source, li);
  }

  MaValue TakeFn(MaMa* M,
                 const std::string& repository,
                 bool relative,
                 const std::vector<std::string>& parts,
                 size_t li) {
    if (repository == "біб") {
      return TakeBib(M, parts, li);
    }
    if (!repository.empty()) {
      return MaValue::Error(
          MaError::Create(M, "Не підтримується взяття з репозиторію.", li));
    }
    if (relative) {
      return MaValue::Error(
          MaError::Create(M, "Не підтримується взяття відносного шляху.", li));
    }
    const auto cwd = std::filesystem::current_path();
    const auto raw_path =
        cwd.string() + "/" + mavka::internal::tools::implode(parts, "/") + ".м";
    return TakePath(M, raw_path, li);
  }
} // namespace mavka