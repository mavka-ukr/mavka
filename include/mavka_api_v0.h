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

    inline bool isError() const { return type == MavkaValueTypeError; };
    inline bool isEmpty() const { return type == MavkaValueTypeEmpty; };
    inline bool isNumber() const { return type == MavkaValueTypeNumber; };
    inline bool isYes() const { return type == MavkaValueTypeYes; };
    inline bool isNo() const { return type == MavkaValueTypeNo; };
    inline bool isObject() const { return type == MavkaValueTypeObject; };
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

    // вказівник на сковп з якого викликано дію для розширення
    MavkaPointer scope;

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

    // отримати аргумент
    MavkaValue (*getArg)(Mavka* mavka,
                         MavkaPointer object,
                         size_t index,
                         const char* name);

    // отримати аргумент або значення за замовчуванням
    MavkaValue (*getArgOrDefault)(Mavka* mavka,
                                  MavkaPointer object,
                                  size_t index,
                                  const char* name,
                                  const MavkaValue& defaultValue);

    // викликати обʼєкт
    MavkaValue (*call)(Mavka* mavka,
                       MavkaPointer object,
                       size_t argc,
                       MavkaValue* argv,
                       size_t li);

    // створити обʼєкт
    MavkaPointer (*createObject)(Mavka* mavka);

    // створити структуру
    MavkaPointer (*createStructure)(Mavka* mavka, const char* name);

    // додати параметр до структури
    void (*addParamToStructure)(Mavka* mavka,
                                MavkaPointer structureObject,
                                const char* name);

    // додати метод до структури
    void (*addMethodToStructure)(Mavka* mavka,
                                 MavkaPointer structureObject,
                                 const char* name,
                                 MavkaPointer diiaObject);

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

    // створити помилку
    MavkaPointer (*createError)(Mavka* mavka,
                                const MavkaValue& value,
                                size_t li);

    // перевірити чи обʼєкт є структурою
    bool (*isObjectStructure)(Mavka* mavka, MavkaPointer object);

    // перевірити чи обʼєкт є дією
    bool (*isObjectDiia)(Mavka* mavka, MavkaPointer object);

    // перевірити чи обʼєкт є модулем
    bool (*isObjectModule)(Mavka* mavka, MavkaPointer object);

    // перевірити чи обʼєкт є байтами
    bool (*isObjectBytes)(Mavka* mavka, MavkaPointer object);

    // перевірити чи обʼєкт є текстом
    bool (*isObjectText)(Mavka* mavka, MavkaPointer object);

    // отримати дані тексу як char*
    char* (*getTextData)(Mavka* mavka, MavkaPointer object);

    // перевірити чи обʼєкт є списком
    bool (*isObjectList)(Mavka* mavka, MavkaPointer object);

    // перевірити чи обʼєкт є словником
    bool (*isObjectDict)(Mavka* mavka, MavkaPointer object);
  } Mavka;
} // namespace mavka::api::v0