#pragma once

#ifndef OPS_H
#define OPS_H

// OP is unsigned char (byte) so it can be 0-255
#define OP_POP 0

// pushes: 1-19
#define OP_PUSH_NUMBER 1
#define OP_PUSH_STRING 2

// arithmetics/binary: 20-49
#define OP_ADD 20
#define OP_SUB 21
#define OP_MUL 22
#define OP_DIV 23
#define OP_MOD 24
#define OP_DIVDIV 25
#define OP_POW 26
#define OP_XOR 27
#define OP_BOR 28
#define OP_BAND 29
#define OP_SHL 30
#define OP_SHR 31

// comparison: 50-69
#define OP_AND 50
#define OP_OR 51
#define OP_EQ 52
#define OP_NE 53
#define OP_LT 54
#define OP_LE 55
#define OP_GT 56
#define OP_GE 57

// jumps: 70-89
#define OP_JUMP 70
#define OP_JUMP_IF_FALSE 71

// calls: 90-119
#define OP_CALL 90

// unary: 120-139
#define OP_NEGATIVE 120
#define OP_POSITIVE 121
#define OP_BNOT 122

// load: 140-169
#define OP_LOAD 140
#define OP_LOAD_ARG 141

// store: 170-189
#define OP_STORE 170
#define OP_STORE_DIIA 44

// others: 190-255
#define OP_GET 190
#define OP_SET 191
#define OP_RETURN 192
#define OP_GET_ELEMENT 193
#define OP_SET_ELEMENT 194
#define OP_THROW 195
#define OP_EACH_SIMPLE 196
#define OP_SET_ARG 197
#define OP_LIST 198
#define OP_LIST_APPEND 199
#define OP_CLEAR_ARGS 200

#endif // OPS_H