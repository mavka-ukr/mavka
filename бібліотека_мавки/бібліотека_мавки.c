#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t п8;
typedef uint16_t п16;
typedef uint32_t п32;
typedef uint64_t п64;
typedef int8_t ц8;
typedef int16_t ц16;
typedef int32_t ц32;
typedef int64_t ц64;
typedef float д32;
typedef double д64;
typedef uint8_t логічне;
typedef п64 природне;
typedef ц64 ціле;
typedef д64 дійсне;
typedef void ніщо;
typedef void* невідома_адреса;
typedef void* невідома_памʼять;

typedef struct ю8 {
  природне розмір;
  п8* дані;
} ю8;

static char* ю8_в_cstr(ю8 value) {
  char* copy = (char*)malloc(value.розмір + 1);
  memcpy(copy, value.дані, value.розмір);
  copy[value.розмір] = 0;
  return copy;
}