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

  // нативна функція C++ для виклику з Мавки
  typedef MavkaValue MavkaNativeFn(MavkaPointer mama,
                                   MavkaPointer diiaObject,
                                   MavkaPointer args,
                                   size_t li);

  // опції Мавки
  typedef struct MavkaOptions {
    // версія Мавки (а.б.в)
    char* version;

    // вказівник на МаМа
    MavkaPointer mama;

    // збільшити лічильник посилань обʼєкта для УО
    void (*retain)(MavkaPointer mama, MavkaPointer object);

    // зменшити лічильник посилань обʼєкта для УО
    // (видаляє обʼєкт коли лічильник стає 0)
    void (*release)(MavkaPointer mama, MavkaPointer object);

    // отримати властивість обʼєкта
    MavkaValue (*get)(MavkaPointer mama, MavkaPointer object, const char* name);

    // встановити властивість обʼєкта
    MavkaValue (*set)(MavkaPointer mama,
                      MavkaPointer object,
                      const char* name,
                      MavkaValue value);

    // отримати елемент обʼєкта
    MavkaValue (*getAt)(MavkaPointer mama, MavkaPointer object, MavkaValue key);

    // встановити елемент обʼєкта
    MavkaValue (*setAt)(MavkaPointer mama,
                        MavkaPointer object,
                        MavkaValue key,
                        MavkaValue value);

    // викликати обʼєкт
    MavkaValue (*call)(MavkaPointer mama,
                       MavkaPointer object,
                       size_t argc,
                       MavkaValue* argv,
                       size_t li);

    // створити дію
    MavkaPointer (*createDiia)(MavkaPointer mama,
                               const char* name,
                               std::function<MavkaNativeFn> fn);

    // створити модуль
    MavkaPointer (*createModule)(MavkaPointer mama, const char* name);

    // створити байти
    MavkaPointer (*createBytes)(MavkaPointer mama, const uint8_t* data);

    // створити текст
    MavkaPointer (*createText)(MavkaPointer mama, const char* text);

    // створити список
    MavkaPointer (*createList)(MavkaPointer mama);

    // створити словник
    MavkaPointer (*createDict)(MavkaPointer mama);
  } MavkaOptions;
} // namespace mavka::api::v0