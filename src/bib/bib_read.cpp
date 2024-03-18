#include "../mavka.h"

namespace mavka {
  MaValue BibReadNativeFn(MaMa* M,
                          MaObject* scope,
                          MaObject* diiaObject,
                          MaObject* args,
                          size_t li) {
    const auto prefix = args->getArg(M, "0", "префікс");
    if (prefix.isObject() && prefix.asObject()->isText(M)) {
      std::cout << prefix.asObject()->textData;
    }
    std::string value;
    getline(std::cin, value);
    if (std::cin.eof()) {
      return MaValue::Empty();
    }
    return MaValue::Object(M->createText(value));
  }

  // взяти біб читати
  MaObject* BibInitReadModule(MaMa* M) {
    const auto read_module_object = M->createModule("читати");
    const auto read_native =
        M->createNativeDiia("читати", BibReadNativeFn, nullptr);
    read_module_object->setProperty(M, "чародія_викликати", read_native);
    return read_module_object;
  }
} // namespace mavka