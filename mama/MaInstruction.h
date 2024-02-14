#pragma once

#ifndef MA_INSTRUCTION_H
#define MA_INSTRUCTION_H

#include "compiler/ops.h"

namespace mavka::mama {
  struct MaStoreInstructionArgs {
    std::string name;
  };

  struct MaInitCallInstructionArgs {
    size_t index;
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
    int index;
    std::string name;
  };

  struct MaDiiaParamInstructionArgs {
    std::string name;
  };

  struct MaTryInstructionArgs {
    size_t catch_index;
  };

  struct MaTryDoneInstructionArgs {
    size_t index;
  };

  struct MaStructInstructionArgs {
    std::string name;
    size_t constructor_index;
  };

  struct MaStructParamInstructionArgs {
    std::string name;
  };

  struct MaStoreArgInstructionArgs {
    std::string name;
  };

  struct MaModuleInstructionArgs {
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
      size_t jump;
      size_t jumpiffalse;
      size_t jumpiftrue;
      size_t constant;
      double number;
      MaStoreInstructionArgs* store;
      MaInitCallInstructionArgs* initcall;
      MaGetInstructionArgs* get;
      MaSetInstructionArgs* set;
      MaDictSetInstructionArgs* dictset;
      MaLoadInstructionArgs* load;
      MaDiiaInstructionArgs* diia;
      MaDiiaParamInstructionArgs* diiaparam;
      MaTryInstructionArgs* try_;
      MaTryDoneInstructionArgs* trydone;
      MaStructInstructionArgs* struct_;
      MaStructParamInstructionArgs* structparam;
      MaStoreArgInstructionArgs* storearg;
      MaModuleInstructionArgs* module;
      MaGiveInstructionArgs* give;
      size_t lt;
      MaTakeInstructionArgs* take;
      MaModuleLoadInstructionArgs* moduleload;
    } args;
  };
} // namespace mavka::mama
#endif // MA_INSTRUCTION_H