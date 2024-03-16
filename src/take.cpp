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
      return M->takeSource(full_path, name, MAVKA_LIB_MODULES[full_path], true,
                           li);
    }
    return MaValue::Error(MaError::Create(
        M, "Модуль \"" + full_path + "\" не знайдено в бібліотеці.", li));
  }
} // namespace mavka