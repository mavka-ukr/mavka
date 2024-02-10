#pragma once

#ifndef OPS_H
#define OPS_H

typedef enum {
  OP_POP,

  OP_CONSTANT,
  OP_NUMBER,
  OP_EMPTY,
  OP_YES,
  OP_NO,

  OP_INITCALL,
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

  OP_EQ,
  OP_GT,
  OP_GE,
  OP_LT,
  OP_LE,

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

inline std::string getopname(const OP op) {
  switch (op) {
    case OP_CONSTANT:
      return "OP_CONSTANT";
    case OP_ADD:
      return "OP_ADD";
    case OP_SUB:
      return "OP_SUB";
    case OP_MUL:
      return "OP_MUL";
    case OP_DIV:
      return "OP_DIV";
    case OP_MOD:
      return "OP_MOD";
    case OP_DIVDIV:
      return "OP_DIVDIV";
    case OP_POW:
      return "OP_POW";
    case OP_STORE:
      return "OP_STORE";
    case OP_LOAD:
      return "OP_LOAD";
    case OP_GET:
      return "OP_GET";
    case OP_SET:
      return "OP_SET";
    case OP_XOR:
      return "OP_XOR";
    case OP_BOR:
      return "OP_BOR";
    case OP_BAND:
      return "OP_BAND";
    case OP_SHL:
      return "OP_SHL";
    case OP_SHR:
      return "OP_SHR";
    case OP_BNOT:
      return "OP_BNOT";
    case OP_JUMP_IF_FALSE:
      return "OP_JUMP_IF_FALSE";
    case OP_JUMP_IF_TRUE:
      return "OP_JUMP_IF_TRUE";
    case OP_E_JUMP_IF_FALSE:
      return "OP_E_JUMP_IF_FALSE";
    case OP_E_JUMP_IF_TRUE:
      return "OP_E_JUMP_IF_TRUE";
    case OP_JUMP:
      return "OP_JUMP";
    case OP_THROW:
      return "OP_THROW";
    case OP_EQ:
      return "OP_EQ";
    case OP_LT:
      return "OP_LT";
    case OP_LE:
      return "OP_LE";
    case OP_GT:
      return "OP_GT";
    case OP_GE:
      return "OP_GE";
    case OP_CALL:
      return "OP_CALL";
    case OP_RETURN:
      return "OP_RETURN";
    case OP_POP:
      return "OP_POP";
    case OP_LIST:
      return "OP_LIST";
    case OP_LIST_APPEND:
      return "OP_LIST_APPEND";
    case OP_NEGATIVE:
      return "OP_NEGATIVE";
    case OP_POSITIVE:
      return "OP_POSITIVE";
    case OP_DIIA:
      return "OP_DIIA";
    case OP_DICT:
      return "OP_DICT";
    case OP_DICT_SET:
      return "OP_DICT_SET";
    case OP_STRUCT:
      return "OP_STRUCT";
    case OP_GIVE:
      return "OP_GIVE";
    case OP_MODULE:
      return "OP_MODULE";
    case OP_TRY:
      return "OP_TRY";
    case OP_TRY_DONE:
      return "OP_TRY_DONE";
    case OP_NOT:
      return "OP_NOT";
    case OP_INITCALL:
      return "OP_INITCALL";
    case OP_DIIA_PARAM:
      return "OP_DIIA_PARAM";
    case OP_STRUCT_PARAM:
      return "OP_STRUCT_PARAM";
    case OP_STRUCT_METHOD:
      return "OP_STRUCT_METHOD";
    case OP_MODULE_DONE:
      return "OP_MODULE_DONE";
    case OP_STORE_ARG:
      return "OP_STORE_ARG";
    case OP_NUMBER:
      return "OP_NUMBER";
    default:
      break;
  }
  return std::to_string(op);
}

#endif // OPS_H