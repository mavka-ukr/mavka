#include <dlfcn.h>
#include "../../include/mavka_api_v0.h"
#include "../mavka.h"

namespace mavka {
  mavka::api::v0::MavkaValue maValue2MavkaApiV0Value(const MaValue& value) {
    return mavka::api::v0::MavkaValue{
        .type = (api::v0::MavkaValueType)value.type,
        .data = {.object = value.v.ptr},
    };
  }
  MaValue mavkaApiV0Value2MaValue(const mavka::api::v0::MavkaValue& value) {
    return MaValue{(MaValueType)value.type, {.ptr = value.data.object}};
  }

  MaValue BibMavkaEvalNativeFn(MaMa* M,
                               MaObject* scope,
                               MaObject* diiaObject,
                               MaObject* args,
                               size_t li) {
    const auto code = args->getArg(M, "0", "код");
    if (code.isObject() && code.asObject()->isText(M)) {
      return M->eval(scope, code.asObject()->textData, li);
    }
    return MaValue::Error(
        MaError::Create(M, "Очікується що код буде текстом.", li));
  }

  MaValue BibMavkaExtendNativeFn(MaMa* M,
                                 MaObject* scope,
                                 MaObject* diiaObject,
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

    void* dobject = dlopen(path_cell.asObject()->textData.c_str(), RTLD_LAZY);
    if (!dobject) {
      return MaValue::Error(MaError::Create(M, std::string(dlerror()), li));
    }
    dlerror();

    void* extfptr = dlsym(dobject, "мавка_розширити");
    if (extfptr == nullptr) {
      return MaValue::Error(MaError::Create(M, std::string(dlerror()), li));
    }

    MaValue (*load_extension)(mavka::api::v0::Mavka* mavka);
    const auto f = reinterpret_cast<decltype(load_extension)>(extfptr);
    const auto mavkaApiV0 = new mavka::api::v0::Mavka{
        .version = (char*)MAVKA_VERSION,
        .M = M,
        .retain =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto maObject = static_cast<MaObject*>(object);
              maObject->retain();
            },
        .release =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto maObject = static_cast<MaObject*>(object);
              maObject->release();
            },
        .get =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object, const char* name) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maValue2MavkaApiV0Value(maObject->getProperty(M, name));
            },
        .set =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object, const char* name,
               mavka::api::v0::MavkaValue value) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              maObject->setProperty(
                  M, std::string(name),
                  MaValue::Object(static_cast<MaObject*>(value.data.object)));
              return maValue2MavkaApiV0Value(MaValue::Empty());
            },
        .getAt =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object,
               mavka::api::v0::MavkaValue key) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              const auto diiaValue = maObject->getProperty(M, MAG_GET_ELEMENT);
              const auto args = M->createObject(M->object_structure_object);
              args->setProperty(M, "0", mavkaApiV0Value2MaValue(key));
              const auto result = diiaValue.call(M, M->global_scope, args, 0);
              return maValue2MavkaApiV0Value(result);
            },
        .setAt =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object,
               mavka::api::v0::MavkaValue key,
               mavka::api::v0::MavkaValue value) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              const auto diiaValue = maObject->getProperty(M, MAG_SET_ELEMENT);
              const auto args = M->createObject(M->object_structure_object);
              args->setProperty(M, "0", mavkaApiV0Value2MaValue(key));
              args->setProperty(M, "1", mavkaApiV0Value2MaValue(value));
              const auto result = diiaValue.call(M, M->global_scope, args, 0);
              return maValue2MavkaApiV0Value(result);
            },
        .getArg =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object, size_t index,
               const char* name) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maValue2MavkaApiV0Value(
                  maObject->getArg(M, std::to_string(index), name));
            },
        .getArgOrDefault =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object, size_t index,
               const char* name,
               const mavka::api::v0::MavkaValue& defaultValue) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maValue2MavkaApiV0Value(
                  maObject->getArg(M, std::to_string(index), name,
                                   mavkaApiV0Value2MaValue(defaultValue)));
            },
        .call =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object, size_t argc,
               mavka::api::v0::MavkaValue* argv, size_t li) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto value =
                  MaValue::Object(static_cast<MaObject*>(object));
              const auto args = M->createObject(M->object_structure_object);
              for (size_t i = 0; i < argc; ++i) {
                args->setProperty(M, std::to_string(i),
                                  MaValue::Object(static_cast<MaObject*>(
                                      argv[i].data.object)));
              }
              return maValue2MavkaApiV0Value(
                  value.call(M, M->global_scope, args, {}));
            },
        .createObject =
            [](mavka::api::v0::Mavka* mavka) {
              const auto M = static_cast<MaMa*>(mavka->M);
              return (void*)M->createObject(M->object_structure_object);
            },
        .createStructure =
            [](mavka::api::v0::Mavka* mavka, const char* name) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto structureObject = M->createStructure(name);
              return (void*)structureObject;
            },
        .addParamToStructure =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer structureObject, const char* name) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(structureObject);
              maObject->structurePushParam(MaDiiaParam(name, MaValue::Empty()));
            },
        .addMethodToStructure =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer structureObject, const char* name,
               mavka::api::v0::MavkaPointer diiaObject) {
              const auto maObject = static_cast<MaObject*>(structureObject);
              maObject->structurePushMethod(static_cast<MaObject*>(diiaObject));
            },
        .createDiia =
            [](mavka::api::v0::Mavka* mavka, const char* name,
               mavka::api::v0::MavkaNativeFn fn) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto diiaObject = M->createNativeDiia(
                  name,
                  [fn, mavka](MaMa* M, MaObject* scope, MaObject* diiaObject,
                              MaObject* args, size_t li) {
                    return mavkaApiV0Value2MaValue(
                        fn(mavka, diiaObject, args, li));
                  },
                  nullptr);
              return (void*)diiaObject;
            },
        .createModule =
            [](mavka::api::v0::Mavka* mavka, const char* name) {
              const auto M = static_cast<MaMa*>(mavka->M);
              return (void*)M->createModule(name);
            },
        .createBytes =
            [](mavka::api::v0::Mavka* mavka, const uint8_t* data) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto vecData =
                  std::vector<uint8_t>(data, data + sizeof(data));
              return (void*)M->createBytes(vecData);
            },
        .createText =
            [](mavka::api::v0::Mavka* mavka, const char* text) {
              const auto M = static_cast<MaMa*>(mavka->M);
              return (void*)M->createText(text);
            },
        .createList =
            [](mavka::api::v0::Mavka* mavka) {
              const auto M = static_cast<MaMa*>(mavka->M);
              return (void*)M->createList();
            },
        .createDict =
            [](mavka::api::v0::Mavka* mavka) {
              const auto M = static_cast<MaMa*>(mavka->M);
              return (void*)M->createDict();
            },
        .isObjectStructure =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isStructure(M);
            },
        .isObjectDiia =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isDiia(M);
            },
        .isObjectModule =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isModule(M);
            },
        .isObjectBytes =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isBytes(M);
            },
        .isObjectText =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isText(M);
            },
        .getTextData =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->textData.data();
            },
        .isObjectList =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isList(M);
            },
        .isObjectDict =
            [](mavka::api::v0::Mavka* mavka,
               mavka::api::v0::MavkaPointer object) {
              const auto M = static_cast<MaMa*>(mavka->M);
              const auto maObject = static_cast<MaObject*>(object);
              return maObject->isDict(M);
            },
    };
    return f(mavkaApiV0);
  }

  // взяти біб мавка
  MaObject* BibInitMavkaModule(MaMa* M) {
    const auto mavkaModuleObject = M->createModule("мавка");
    mavkaModuleObject->setProperty(M, "версія", M->createText(MAVKA_VERSION));
    mavkaModuleObject->setProperty(
        M, "виконати",
        M->createNativeDiia("виконати", BibMavkaEvalNativeFn, nullptr));
    mavkaModuleObject->setProperty(
        M, "розширити",
        M->createNativeDiia("розширити", BibMavkaExtendNativeFn, nullptr));
    return mavkaModuleObject;
  }
} // namespace mavka