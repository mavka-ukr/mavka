#include <cstdint>
#include <functional>

// АПІ Мавки для C++ розширень. Версія 0 є нестабільною і може змінитись в
// будь-який момент.
namespace mavka::api::v0 {
  // вказівник на обʼєкт Мавки або якісь дані
  typedef void* MavkaPointer;

  // тип значення Мавки (не обʼєкта, а саме значення)
  enum MavkaValueType : uint8_t {
    MavkaValueTypeError = 0,
    MavkaValueTypeEmpty = 1,
    MavkaValueTypeNumber = 2,
    MavkaValueTypeYes = 3,
    MavkaValueTypeNo = 4,
    MavkaValueTypeObject = 5,
  };

  // Значення Мавки
  typedef struct MavkaValue {
    MavkaValueType type;
    union {
      double number;
      MavkaPointer object;
    } data;
  } MavkaValue;

  struct Mavka;

  // нативна функція C++ для виклику з Мавки
  typedef MavkaValue MavkaNativeFn(Mavka* mavka,
                                   MavkaPointer diiaObject,
                                   MavkaPointer args,
                                   size_t li);

  typedef struct Mavka {
    // версія Мавки (а.б.в)
    char* version;

    // вказівник на МаМа
    MavkaPointer M;

    // збільшити лічильник посилань обʼєкта для УО
    void (*retain)(Mavka* mavka, MavkaPointer object);

    // зменшити лічильник посилань обʼєкта для УО
    // (видаляє обʼєкт коли лічильник стає 0)
    void (*release)(Mavka* mavka, MavkaPointer object);

    // отримати властивість обʼєкта
    MavkaValue (*get)(Mavka* mavka, MavkaPointer object, const char* name);

    // встановити властивість обʼєкта
    MavkaValue (*set)(Mavka* mavka,
                      MavkaPointer object,
                      const char* name,
                      MavkaValue value);

    // отримати елемент обʼєкта
    MavkaValue (*getAt)(Mavka* mavka, MavkaPointer object, MavkaValue key);

    // встановити елемент обʼєкта
    MavkaValue (*setAt)(Mavka* mavka,
                        MavkaPointer object,
                        MavkaValue key,
                        MavkaValue value);

    // викликати обʼєкт
    MavkaValue (*call)(Mavka* mavka,
                       MavkaPointer object,
                       size_t argc,
                       MavkaValue* argv,
                       size_t li);

    // створити дію
    MavkaPointer (*createDiia)(Mavka* mavka,
                               const char* name,
                               MavkaNativeFn fn);

    // створити модуль
    MavkaPointer (*createModule)(Mavka* mavka, const char* name);

    // створити байти
    MavkaPointer (*createBytes)(Mavka* mavka, const uint8_t* data);

    // створити текст
    MavkaPointer (*createText)(Mavka* mavka, const char* text);

    // створити список
    MavkaPointer (*createList)(Mavka* mavka);

    // створити словник
    MavkaPointer (*createDict)(Mavka* mavka);
  } Mavka;
} // namespace mavka::api::v0