#ifndef MA_FRAME_H
#define MA_FRAME_H

enum MaFrameType { FRAME_TYPE_CALL, FRAME_TYPE_MODULE, FRAME_TYPE_TRY };
enum MaFrameCallType {
  FRAME_CALL_TYPE_DIIA,
  FRAME_CALL_TYPE_DIIA_NATIVE,
  FRAME_CALL_TYPE_STRUCTURE
};

struct MaCallFrameCallArgs {
  MaFrameCallType type;
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

struct MaFrameModuleArgs {
  MaObject* module;
  size_t restore_stack_size;
};

struct MaFrameTryArgs {
  size_t catch_index;
};

struct MaFrame {
  MaFrameType type;
  MaScope* scope;
  union {
    MaCallFrameCallArgs* call;
    MaFrameModuleArgs* module;
    MaFrameTryArgs* try_;
  } data;

  static MaFrame* call(MaScope* scope, MaCallFrameCallArgs* data);
  static MaFrame* module(MaScope* scope, MaFrameModuleArgs* data);
  static MaFrame* try_(MaScope* scope, MaFrameTryArgs* data);
};

#endif // MA_FRAME_H