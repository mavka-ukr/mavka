#include <dlfcn.h>
#include "../../include/mavka_api_v0.h"
#include "../mavka.h"

namespace mavka {
  MaValue BibFsSyncReadNativeFn(MaMa* M,
                                MaObject* scope,
                                MaObject* diiaObject,
                                MaObject* args,
                                size_t li) {
    const auto path = args->getArg(M, "0", "шлях");
    if (path.isObject() && (path.asObject()->isText(M))) {
      const auto path_str = path.asObject()->textData;
      std::ifstream file(path_str);
      if (file.is_open()) {
        std::vector<uint8_t> data((std::istreambuf_iterator<char>(file)),
                                  std::istreambuf_iterator<char>());
        return MaValue::Object(M->createBytes(data));
      }
      return MaValue::Error(MaError::Create(
          M, "Не вдалося прочитати файл \"" + path_str + "\".", li));
    }
    return MaValue::Error(
        MaError::Create(M, "Очікується що шлях буде текстом.", li));
  }

  MaValue BibFsSyncReadTextNativeFn(MaMa* M,
                                    MaObject* scope,
                                    MaObject* diiaObject,
                                    MaObject* args,
                                    size_t li) {
    const auto path = args->getArg(M, "0", "шлях");
    if (path.isObject() && (path.asObject()->isText(M))) {
      const auto path_str = path.asObject()->textData;
      std::ifstream file(path_str);
      if (file.is_open()) {
        std::string text((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
        return MaValue::Object(M->createText(text));
      }
      return MaValue::Error(MaError::Create(
          M, "Не вдалося прочитати файл \"" + path_str + "\".", li));
    }
    return MaValue::Error(
        MaError::Create(M, "Очікується що шлях буде текстом.", li));
  }

  // взяти біб сфс
  MaObject* BibInitFsSyncModule(MaMa* M) {
    const auto mavka_module_o = M->createModule("сфс");
    mavka_module_o->setProperty(
        M, "прочитати",
        M->createNativeDiia("прочитати", BibFsSyncReadNativeFn, nullptr));
    mavka_module_o->setProperty(
        M, "прочитати_текст",
        M->createNativeDiia("прочитати_текст", BibFsSyncReadTextNativeFn,
                            nullptr));
    return mavka_module_o;
  }
} // namespace mavka