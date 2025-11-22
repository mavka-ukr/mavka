#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t п8;
typedef int32_t ц32;
typedef size_t природне;

typedef struct ю8 ю8;

struct ю8 {
  природне розмір;
  п8* дані;
};

extern ц32 старт(природне кількість_аргументів, ю8* аргументи);

int main(int argc, char** argv) {
  ю8* аргументи = (ю8*)malloc(argc * sizeof(ю8));
  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }
  int r = старт(argc, аргументи);
  free(аргументи);
  return r;
}