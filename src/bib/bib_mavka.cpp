#include <dlfcn.h>
#include "../../include/mavka_api_v0.h"
#include "../mavka.h"

namespace mavka {
  MaValue BibMavkaEvalNativeFn(MaMa* M,
                               MaObject* native_o,
                               MaObject* args,
                               size_t li) {
    const auto code = args->getArg(M, "0", "код");
    if (code.isObject() && code.asObject()->isText(M)) {
      return M->eval(code.asText()->data, li);
    }
    return MaValue::Error(
        MaError::Create(M, "Очікується що код буде текстом.", li));
  }

  MaValue BibMavkaExtendNativeFn(MaMa* M,
                                 MaObject* native_o,
                                 MaObject* args,
                                 size_t li) {
    const auto version_cell = args->getArg(M, "0", "версія");
    if (!version_cell.isNumber()) {
      return MaValue::Error(
          MaError::Create(M, "Очікується що версія буде числом.", li));
    }
    const auto path_cell = args->getArg(M, "1", "шлях");
    if (!(path_cell.isObject() && path_cell.asObject()->isText(M))) {
      return MaValue::Error(
          MaError::Create(M, "Очікується що шлях буде текстом.", li));
    }

    void* dobject = dlopen(path_cell.asText()->data.c_str(), RTLD_LAZY);
    if (!dobject) {
      return MaValue::Error(MaError::Create(M, std::string(dlerror()), li));
    }
    dlerror();

    void* extfptr = dlsym(dobject, "мавка_розширити");
    if (extfptr == nullptr) {
      return MaValue::Error(MaError::Create(M, std::string(dlerror()), li));
    }

    MaValue (*load_extension)(mavka::api::v0::MavkaOptions mavkaOptions);
    const auto f = reinterpret_cast<decltype(load_extension)>(extfptr);
    return f({
        .version = (char*)MAVKA_VERSION,
        .mama = M,
        .ref =
            [](mavka::api::v0::MavkaPointer mama,
               mavka::api::v0::MavkaPointer object) {
              const auto maObject = static_cast<MaObject*>(object);
              maObject->retain();
              return static_cast<mavka::api::v0::MavkaPointer>(maObject);
            },
        .retain =
            [](mavka::api::v0::MavkaPointer mama,
               mavka::api::v0::MavkaPointer object) {
              const auto maObject = static_cast<MaObject*>(object);
              maObject->retain();
            },
        .release =
            [](mavka::api::v0::MavkaPointer mama,
               mavka::api::v0::MavkaPointer object) {
              const auto maObject = static_cast<MaObject*>(object);
              maObject->release();
            },
        .get_property =
            [](mavka::api::v0::MavkaPointer mama,
               mavka::api::v0::MavkaPointer object, const char* name) {
              const auto M = static_cast<MaMa*>(mama);
              const auto maObject = static_cast<MaObject*>(object);
              const auto value = maObject->getProperty(M, std::string(name));
              return mavka::api::v0::MavkaValue{
                  .type = value.type,
                  .data = {.object = value.v.object},
              };
            },
        .set_property =
            [](mavka::api::v0::MavkaPointer mama,
               mavka::api::v0::MavkaPointer object, const char* name,
               mavka::api::v0::MavkaValue value) {
              const auto M = static_cast<MaMa*>(mama);
              const auto maObject = static_cast<MaObject*>(object);
              maObject->setProperty(
                  M, std::string(name),
                  MaValue::Object(static_cast<MaObject*>(value.data.object)));
              return mavka::api::v0::MavkaValue{
                  .type = value.type,
                  .data = {.object = value.data.object},
              };
            },
        .call =
            [](mavka::api::v0::MavkaPointer mama,
               mavka::api::v0::MavkaPointer object, size_t argc,
               mavka::api::v0::MavkaValue* argv) {
              const auto M = static_cast<MaMa*>(mama);
              const auto value =
                  MaValue::Object(static_cast<MaObject*>(object));
              std::vector<MaValue> args;
              for (size_t i = 0; i < argc; ++i) {
                args.push_back(MaValue::Object(
                    static_cast<MaObject*>(argv[i].data.object)));
              }
              const auto result = value.call(M, args, {});
              return mavka::api::v0::MavkaValue{
                  .type = value.type,
                  .data = {.object = result.v.object},
              };
            },
    });
  }

  // взяти біб мавка
  MaObject* BibInitMavkaModule(MaMa* M) {
    const auto mavka_module_o = MaModule::Create(M, "мавка");
    mavka_module_o->setProperty(M, "версія", MaText::Create(M, MAVKA_VERSION));
    mavka_module_o->setProperty(
        M, "виконати",
        MaDiia::Create(M, "виконати", BibMavkaEvalNativeFn, nullptr));
    mavka_module_o->setProperty(
        M, "розширити",
        MaDiia::Create(M, "розширити", BibMavkaExtendNativeFn, nullptr));
    return mavka_module_o;
  }
} // namespace mavka