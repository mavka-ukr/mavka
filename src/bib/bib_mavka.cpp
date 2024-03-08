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

  // взяти біб мавка
  MaObject* BibInitMavkaModule(MaMa* M) {
    const auto mavka_module_object = MaModule::Create(M, "мавка");
    mavka_module_object->SetProperty("версія",
                                     MaText::Create(M, MAVKA_VERSION));
    mavka_module_object->SetProperty(
        "виконати",
        MaNative::Create(M, "виконати", BibMavkaEvalNativeFn, nullptr));
    return mavka_module_object;
  }
} // namespace mavka