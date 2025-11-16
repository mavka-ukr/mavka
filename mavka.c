#include <stdbool.h>
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
typedef struct Шлях Шлях;
typedef struct ВихідФайлу ВихідФайлу;

struct ю8 {
  природне розмір;
  п8* дані;
};

struct Шлях {
  природне розмір;
  п8* дані;
};

struct ВихідФайлу {
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

extern bool __прочитати_файл(Шлях* шлях, ВихідФайлу* вихід_файлу) {
  char* шлях_рядок = (char*)malloc(шлях->розмір + 1);
  for (природне і = 0; і < шлях->розмір; і++) {
    шлях_рядок[і] = (char)шлях->дані[і];
  }
  шлях_рядок[шлях->розмір] = '\0';

  FILE* файл = fopen(шлях_рядок, "rb");
  free(шлях_рядок);
  if (!файл) {
    return false;
  }

  fseek(файл, 0, SEEK_END);
  вихід_файлу->розмір = ftell(файл);
  fseek(файл, 0, SEEK_SET);

  вихід_файлу->дані = (п8*)malloc(вихід_файлу->розмір);
  if (!вихід_файлу->дані) {
    fclose(файл);
    return false;
  }

  fread(вихід_файлу->дані, 1, вихід_файлу->розмір, файл);
  fclose(файл);
  return true;
}

extern int старт();

int main() {
  return старт();
}