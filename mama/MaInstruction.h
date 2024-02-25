#ifndef MA_INSTRUCTION_H
#define MA_INSTRUCTION_H

typedef enum {
  VPop,

  VConstant,
  VNumber,
  VEmpty,
  VYes,
  VNo,

  VInitargs,
  VPushArg,
  VStoreArg,
  VCall,
  VReturn,
  VDiia,
  VDiiaParam,

  VStore,
  VLoad,

  VJump,
  VJumpIfTrue,
  VJumpIfFalse,
  VEJumpIfTrue,
  VEJumpIfFalse,

  VGet,
  VSet,
  VESetR,

  VTry,
  VTryDone,
  VThrow,

  VList,
  VListAppend,
  VDict,
  VDictSet,

  VStruct,
  VStructParam,
  VStructMethod,

  VModule,
  VGive,
  VModuleDone,
  VKeepModule,
  VLoadModule,
  VModuleLoad,
  VTake,

  VEq,
  VGt,
  VGe,
  VLt,
  VLe,
  VContains,
  VIs,

  VNot,

  VNegative,
  VPositive,
  VBnot,

  VAdd,
  VSub,
  VMul,
  VDiv,
  VMod,
  VDivDiv,
  VPow,

  VXor,
  VBor,
  VBand,
  VShl,
  VShr,
} MaV;

std::string getopname(const MaV v);

struct MaInstructionLocation {
  size_t line;
  size_t column;
};

struct MaStoreInstructionArgs {
  std::string name;
};

struct MaInitArgsInstructionArgs {
  MaArgsType args_type;
};

struct MaGetInstructionArgs {
  std::string name;
};

struct MaSetInstructionArgs {
  std::string name;
};

struct MaDictSetInstructionArgs {
  std::string key;
};

struct MaLoadInstructionArgs {
  std::string name;
};

struct MaDiiaInstructionArgs {
  MaCode* code;
  std::string name;
  std::string path;
};

struct MaDiiaParamInstructionArgs {
  std::string name;
};

struct MaTryInstructionArgs {
  MaCode* try_code;
  MaCode* catch_code;
};

struct MaTryDoneInstructionArgs {
  size_t index;
};

struct MaThrowInstructionArgs {
  size_t line;
  size_t column;
};

struct MaStructInstructionArgs {
  std::string name;
};

struct MaStructParamInstructionArgs {
  std::string name;
};

struct MaStoreArgInstructionArgs {
  std::string name;
};

struct MaModuleInstructionArgs {
  MaCode* code;
  std::string name;
};

struct MaGiveInstructionArgs {
  std::string name;
};

struct MaTakeInstructionArgs {
  size_t jump_to;
  std::string path;
};

struct MaModuleLoadInstructionArgs {
  std::string name;
  std::string as;
};

struct MaInstruction {
  MaV v;
  union {
    size_t constant;
    double number;
    MaInitArgsInstructionArgs* initargs;
    MaStoreArgInstructionArgs* storearg;
    MaDiiaInstructionArgs* diia;
    MaDiiaParamInstructionArgs* diiaparam;
    MaStoreInstructionArgs* store;
    MaLoadInstructionArgs* load;
    size_t jump;
    size_t jumpiftrue;
    size_t jumpiffalse;
    MaGetInstructionArgs* get;
    MaSetInstructionArgs* set;
    MaTryInstructionArgs* try_;
    MaTryDoneInstructionArgs* trydone;
    MaThrowInstructionArgs* throw_;
    MaDictSetInstructionArgs* dictset;
    MaStructInstructionArgs* struct_;
    MaStructParamInstructionArgs* structparam;
    MaModuleInstructionArgs* module;
    MaGiveInstructionArgs* give;
    MaModuleLoadInstructionArgs* moduleload;
    MaTakeInstructionArgs* take;
  } args;
  MaInstructionLocation* location;

  static MaInstruction pop();
  static MaInstruction constant(size_t index);
  static MaInstruction number(double value);
  static MaInstruction empty();
  static MaInstruction yes();
  static MaInstruction no();
  static MaInstruction initargs(MaInitArgsInstructionArgs* args);
  static MaInstruction pusharg();
  static MaInstruction storearg(MaStoreArgInstructionArgs* args);
  static MaInstruction call(MaInstructionLocation* location);
  static MaInstruction return_();
  static MaInstruction diia(MaDiiaInstructionArgs* args);
  static MaInstruction diiaparam(MaDiiaParamInstructionArgs* args);
  static MaInstruction store(MaStoreInstructionArgs* args);
  static MaInstruction load(MaLoadInstructionArgs* args);
  static MaInstruction jump(size_t index);
  static MaInstruction jumpiftrue(size_t index);
  static MaInstruction jumpiffalse(size_t index);
  static MaInstruction get(MaGetInstructionArgs* args);
  static MaInstruction set(MaSetInstructionArgs* args);
  static MaInstruction try_(MaTryInstructionArgs* args);
  static MaInstruction trydone(MaTryDoneInstructionArgs* args);
  static MaInstruction throw_(MaThrowInstructionArgs* args);
  static MaInstruction list();
  static MaInstruction listappend();
  static MaInstruction dict();
  static MaInstruction dictset(MaDictSetInstructionArgs* args);
  static MaInstruction struct_(MaStructInstructionArgs* args);
  static MaInstruction structparam(MaStructParamInstructionArgs* args);
  static MaInstruction structmethod();
  static MaInstruction module(MaModuleInstructionArgs* args);
  static MaInstruction give(MaGiveInstructionArgs* args);
  static MaInstruction moduledone();
  static MaInstruction keepmodule();
  static MaInstruction loadmodule();
  static MaInstruction moduleload(MaModuleLoadInstructionArgs* args);
  static MaInstruction take(MaTakeInstructionArgs* args);
  static MaInstruction eq();
  static MaInstruction gt();
  static MaInstruction ge();
  static MaInstruction lt();
  static MaInstruction le();
  static MaInstruction contains();
  static MaInstruction is();
  static MaInstruction not_();
  static MaInstruction negative();
  static MaInstruction positive();
  static MaInstruction bnot();
  static MaInstruction add(MaInstructionLocation* location);
  static MaInstruction sub(MaInstructionLocation* location);
  static MaInstruction mul(MaInstructionLocation* location);
  static MaInstruction div(MaInstructionLocation* location);
  static MaInstruction mod(MaInstructionLocation* location);
  static MaInstruction divdiv(MaInstructionLocation* location);
  static MaInstruction pow(MaInstructionLocation* location);
  static MaInstruction xor_();
  static MaInstruction bor();
  static MaInstruction band();
  static MaInstruction shl();
  static MaInstruction shr();
};

#endif // MA_INSTRUCTION_H