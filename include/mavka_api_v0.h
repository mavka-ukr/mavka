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
  } MavkaOptions;
} // namespace mavka::api::v0