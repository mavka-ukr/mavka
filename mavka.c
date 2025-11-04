#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t п8;
typedef uint16_t п16;
typedef uint32_t п32;
typedef uint64_t п64;
typedef int32_t ц32;
typedef size_t природне;
typedef struct ю8 ю8;

struct ю8 {
  природне розмір;
  п8* дані;
};

extern void __надрукувати_ю8(ю8* значення) {
  for (природне і = 0; і < значення->розмір; і++) {
    putchar(значення->дані[і]);
  }
  putchar('\n');
}

extern void __надрукувати_д64(double значення) {
  printf("%lf\n", значення);
}

extern п8* __виділити_сиру_памʼять(природне розмір) {
  return (п8*)malloc(розмір);
}

extern п8* __перевиділити_сиру_памʼять(п8* значення, природне новий_розмір) {
  return (п8*)realloc(значення, новий_розмір);
}

extern void __звільнити_сиру_памʼять(п8* значення) {
  free(значення);
}

extern void __вийти(ц32 код_виходу) {
  exit(код_виходу);
}

extern int старт();

int main() {
  return старт();
}