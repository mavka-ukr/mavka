#include "../mavka.h"

namespace mavka {
  MaValue BibReadNativeFn(MaMa* M,
                          MaObject* o,
                          MaArgs* args,
                          const MaLocation& location) {
    const auto prefix = args->Get(0, "префікс");
    if (prefix.isObject() && prefix.asObject()->isText(M)) {
      std::cout << prefix.asText()->data;
    }
    std::string value;
    getline(std::cin, value);
    if (std::cin.eof()) {
      return MaValue::Empty();
    }
    return MaValue::Object(MaText::Create(M, value));
  }

  // взяти біб читати
  MaObject* BibInitReadModule(MaMa* M) {
    const auto read_module_object = MaModule::Create(M, "читати");
    const auto read_native =
        MaDiia::Create(M, "читати", BibReadNativeFn, nullptr);
    read_module_object->setProperty(M, "чародія_викликати", read_native);
    return read_module_object;
  }
} // namespace mavka