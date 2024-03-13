#include <functional>

namespace mavka::api::v0 {
  typedef void* MavkaPointer;

  typedef struct MavkaValue {
    unsigned char type;
    union {
      double number;
      MavkaPointer object;
    } data;
  } MavkaValue;

  typedef struct MavkaOptions {
    char* version;
    MavkaPointer mama;
    MavkaPointer (*ref)(MavkaPointer mama, MavkaPointer object);
    void (*retain)(MavkaPointer mama, MavkaPointer object);
    void (*release)(MavkaPointer mama, MavkaPointer object);
    MavkaValue (*get_property)(MavkaPointer mama,
                               MavkaPointer object,
                               const char* name);
    MavkaValue (*set_property)(MavkaPointer mama,
                               MavkaPointer object,
                               const char* name,
                               MavkaValue value);
    MavkaValue (*call)(MavkaPointer mama,
                       MavkaPointer object,
                       size_t argc,
                       MavkaValue* argv);
  } MavkaOptions;
} // namespace mavka::api::v0