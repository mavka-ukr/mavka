#ifndef CALL_FRAME_H
#define CALL_FRAME_H

enum MaCallFrameType { CF_TYPE_CALL, CF_TYPE_MODULE, CF_TYPE_TRY };
enum MaCallFrameCallType {
  CF_CALL_TYPE_DIIA,
  CF_CALL_TYPE_DIIA_NATIVE,
  CF_CALL_TYPE_STRUCTURE
};

struct MaCallFrameCallArgs {
  MaCallFrameCallType type;
  union {
    MaObject* diia;
    MaObject* diia_native;
    MaObject* structure;
  } o;
  size_t return_index;
  std::map<std::string, MaCell> args;
  size_t line;
  size_t column;
  size_t restore_stack_size;
};

struct MaCallFrameModuleArgs {
  MaObject* module;
  size_t restore_stack_size;
};

struct MaCallFrameTryArgs {
  size_t catch_index;
};

struct MaCallFrame {
  MaCallFrameType type;
  MaScope* scope;
  union {
    MaCallFrameCallArgs* call;
    MaCallFrameModuleArgs* module;
    MaCallFrameTryArgs* try_;
  } data;

  static MaCallFrame* call(MaScope* scope, MaCallFrameCallArgs* data);
  static MaCallFrame* module(MaScope* scope, MaCallFrameModuleArgs* data);
  static MaCallFrame* try_(MaScope* scope, MaCallFrameTryArgs* data);
};

#endif // CALL_FRAME_H