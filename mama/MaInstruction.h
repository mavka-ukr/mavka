#ifndef MA_INSTRUCTION_H
#define MA_INSTRUCTION_H

typedef enum {
  OP_POP,

  OP_CONSTANT,
  OP_NUMBER,
  OP_EMPTY,
  OP_YES,
  OP_NO,

  OP_INITCALL,
  OP_PUSH_ARG,
  OP_STORE_ARG,
  OP_CALL,
  OP_RETURN,
  OP_DIIA,
  OP_DIIA_PARAM,

  OP_STORE,
  OP_LOAD,

  OP_JUMP,
  OP_JUMP_IF_TRUE,
  OP_JUMP_IF_FALSE,
  OP_E_JUMP_IF_TRUE,
  OP_E_JUMP_IF_FALSE,

  OP_GET,
  OP_SET,
  OP_E_SETR,

  OP_TRY,
  OP_TRY_DONE,
  OP_THROW,

  OP_LIST,
  OP_LIST_APPEND,
  OP_DICT,
  OP_DICT_SET,

  OP_STRUCT,
  OP_STRUCT_PARAM,
  OP_STRUCT_METHOD,

  OP_MODULE,
  OP_GIVE,
  OP_MODULE_DONE,
  OP_KEEP_MODULE,
  OP_LOAD_MODULE,
  OP_MODULE_LOAD,
  OP_TAKE,

  OP_EQ,
  OP_GT,
  OP_GE,
  OP_LT,
  OP_LE,
  OP_CONTAINS,
  OP_IS,

  OP_NOT,

  OP_NEGATIVE,
  OP_POSITIVE,
  OP_BNOT,

  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_MOD,
  OP_DIVDIV,
  OP_POW,

  OP_XOR,
  OP_BOR,
  OP_BAND,
  OP_SHL,
  OP_SHR,
} OP;

std::string getopname(const OP op);

struct MaStoreInstructionArgs {
  std::string name;
};

struct MaInitCallInstructionArgs {
  MaArgsType args_type;
  size_t line;
  size_t column;
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
  OP op;
  union {
    size_t constant;
    double number;
    MaInitCallInstructionArgs* initcall;
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

  static MaInstruction pop();
  static MaInstruction constant(size_t index);
  static MaInstruction number(double value);
  static MaInstruction empty();
  static MaInstruction yes();
  static MaInstruction no();
  static MaInstruction initcall(MaInitCallInstructionArgs* args);
  static MaInstruction pusharg();
  static MaInstruction storearg(MaStoreArgInstructionArgs* args);
  static MaInstruction call();
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
  static MaInstruction add();
  static MaInstruction sub();
  static MaInstruction mul();
  static MaInstruction div();
  static MaInstruction mod();
  static MaInstruction divdiv();
  static MaInstruction pow();
  static MaInstruction xor_();
  static MaInstruction bor();
  static MaInstruction band();
  static MaInstruction shl();
  static MaInstruction shr();
};

#endif // MA_INSTRUCTION_H