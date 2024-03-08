#include <dlfcn.h>
#include "../../include/mavka_api_v0.h"
#include "../mavka.h"

namespace mavka {
  MaCell BibMavkaEvalNativeFn(MaMa* M,
                              MaObject* o,
                              MaArgs* args,
                              const MaLocation& location) {
    const auto code = args->Get(0, "код");
    if (code.IsObject() && code.IsObjectText()) {
      return M->Eval(code.AsText()->data, location);
    }
    return MaCell::Error(
        MaError::Create(M, "Очікується що код буде текстом.", location));
  }

  MaCell BibMavkaExtendNativeFn(MaMa* M,
                                MaObject* o,
                                MaArgs* args,
                                const MaLocation& location) {
    const auto version_cell = args->Get(0, "версія");
    if (!version_cell.IsNumber()) {
      return MaCell::Error(
          MaError::Create(M, "Очікується що версія буде числом.", location));
    }
    const auto path_cell = args->Get(1, "шлях");
    if (!(path_cell.IsObject() && path_cell.IsObjectText())) {
      return MaCell::Error(
          MaError::Create(M, "Очікується що шлях буде текстом.", location));
    }

    void* dobject = dlopen(path_cell.AsText()->data.c_str(), RTLD_LAZY);
    if (!dobject) {
      return MaCell::Error(
          MaError::Create(M, std::string(dlerror()), location));
    }
    dlerror();

    void* extfptr = dlsym(dobject, "мавка_розширити_модуль");
    if (extfptr == nullptr) {
      return MaCell::Error(
          MaError::Create(M, std::string(dlerror()), location));
    }

    double (*load_extension)(mavka::api::v0::MavkaOptions mavkaOptions);
    const auto f = reinterpret_cast<decltype(load_extension)>(extfptr);
    f({.version = (char*)MAVKA_VERSION});

    return MaCell::Empty();
  }

  // взяти біб мавка
  MaObject* BibInitMavkaModule(MaMa* M) {
    const auto mavka_module_o = MaModule::Create(M, "мавка");
    mavka_module_o->SetProperty("версія", MaText::Create(M, MAVKA_VERSION));
    mavka_module_o->SetProperty(
        "виконати",
        MaNative::Create(M, "виконати", BibMavkaEvalNativeFn, nullptr));
    mavka_module_o->SetProperty(
        "розширити",
        MaNative::Create(M, "розширити", BibMavkaExtendNativeFn, nullptr));
    return mavka_module_o;
  }
} // namespace mavka