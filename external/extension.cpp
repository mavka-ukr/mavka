#include <stdio.h>
#include <stdlib.h>

extern "C" void* mavka_sysext_malloc(int size) {
  return malloc(size);
}

extern "C" void mavka_sysext_free(void* ptr) {
  free(ptr);
}

extern "C" void* mavka_sysext_realloc(void* ptr, int size) {
  return realloc(ptr, size);
}

extern "C" int mavka_sysext_putchar(unsigned char c) {
  return putchar(c);
}

extern "C" unsigned char* прочитати_файл(unsigned char* шлях) {
  FILE* файл = fopen((char*)шлях, "rb");
  if (файл == NULL) {
    return NULL;
  }
  fseek(файл, 0, SEEK_END);
  long довжина = ftell(файл);
  fseek(файл, 0, SEEK_SET);
  unsigned char* буфер = (unsigned char*)malloc(довжина + 1);
  fread(буфер, 1, довжина, файл);
  fclose(файл);
  буфер[довжина] = 0;
  return буфер;
}