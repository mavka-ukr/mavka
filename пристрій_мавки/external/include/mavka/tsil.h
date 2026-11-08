#ifndef TSIL_H
#define TSIL_H

#include "./numbertypes.h"

typedef bool логічне;

typedef uint8_t п8;
typedef uint16_t п16;
typedef uint32_t п32;
typedef uint64_t п64;
typedef int8_t ц8;
typedef int16_t ц16;
typedef int32_t ц32;
typedef int64_t ц64;
typedef float р32;
typedef double р64;

typedef size_t природне;
typedef ssize_t ціле;

typedef void ніщо;
typedef void* адреса;

typedef struct ю8 ю8;
typedef struct кд кд;

struct ю8 {
  п8* дані;
  природне розмір;
};

struct кд {
  п8* дані;
  природне розмір;
};

static const логічне ні = 0;
static const логічне так = 1;
static const адреса пусто = 0;

#endif // TSIL_H