#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t н8;
typedef uint16_t н16;
typedef uint32_t н32;
typedef uint64_t н64;
typedef int8_t ц8;
typedef int16_t ц16;
typedef int32_t ц32;
typedef int64_t ц64;
typedef float р32;
typedef double р64;
typedef uint8_t логічне;
typedef н64 натуральне;
typedef ц64 ціле;
typedef р64 дійсне;
typedef void ніщо;
typedef void* невідома_адреса;
typedef void* невідома_памʼять;

typedef struct ю8 {
  натуральне розмір;
  н8* дані;
} ю8;

static char* ю8_в_cstr(ю8 value) {
  char* copy = (char*)malloc(value.розмір + 1);
  memcpy(copy, value.дані, value.розмір);
  copy[value.розмір] = 0;
  return copy;
}