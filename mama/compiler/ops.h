#pragma once

#ifndef OPS_H
#define OPS_H

typedef enum {
  OP_POP,

  OP_PUSH_NUMBER,
  OP_PUSH_STRING,

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

  OP_AND,
  OP_OR,
  OP_EQ,
  OP_NE,
  OP_LT,
  OP_LE,
  OP_GT,
  OP_GE,

  OP_JUMP,
  OP_JUMP_IF_FALSE,

  OP_CALL,

  OP_NEGATIVE,
  OP_POSITIVE,
  OP_BNOT,

  OP_LOAD,
  OP_LOAD_ARG,

  OP_STORE,

  OP_GET,
  OP_SET,
  OP_RETURN,
  OP_GET_ELEMENT,
  OP_SET_ELEMENT,
  OP_THROW,
  OP_EACH_SIMPLE,
  OP_SET_ARG,
  OP_LIST,
  OP_LIST_APPEND,
  OP_CLEAR_ARGS,
  OP_DICT,
  OP_DICT_SET,
  OP_STRUCT,
  OP_STRUCT_PARAM,
  OP_DIIA,
  OP_DIIA_PARAM,
} OP;

inline std::string getopname(const OP op) {
  switch (op) {
    case OP_PUSH_NUMBER:
      return "OP_PUSH_NUMBER";
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
    case OP_PUSH_STRING:
      return "OP_PUSH_STRING";
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
    case OP_JUMP:
      return "OP_JUMP";
    case OP_THROW:
      return "OP_THROW";
    case OP_EQ:
      return "OP_EQ";
    case OP_NE:
      return "OP_NE";
    case OP_LT:
      return "OP_LT";
    case OP_LE:
      return "OP_LE";
    case OP_GT:
      return "OP_GT";
    case OP_GE:
      return "OP_GE";
    case OP_AND:
      return "OP_AND";
    case OP_OR:
      return "OP_OR";
    case OP_CALL:
      return "OP_CALL";
    case OP_RETURN:
      return "OP_RETURN";
    case OP_LOAD_ARG:
      return "OP_LOAD_ARG";
    case OP_POP:
      return "OP_POP";
    case OP_SET_ELEMENT:
      return "OP_SET_ELEMENT";
    case OP_SET_ARG:
      return "OP_SET_ARG";
    case OP_LIST:
      return "OP_LIST";
    case OP_LIST_APPEND:
      return "OP_LIST_APPEND";
    case OP_GET_ELEMENT:
      return "OP_GET_ELEMENT";
    case OP_NEGATIVE:
      return "OP_NEGATIVE";
    case OP_POSITIVE:
      return "OP_POSITIVE";
    case OP_DIIA:
      return "OP_DIIA";
    case OP_EACH_SIMPLE:
      return "OP_EACH_SIMPLE";
    case OP_CLEAR_ARGS:
      return "OP_CLEAR_ARGS";
    default:
      break;
  }
  return std::to_string(op);
}

#endif // OPS_H