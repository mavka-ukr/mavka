#include <stdio.h>
#include <stdlib.h>

extern void* mavka_ext_malloc(int size) {
  return malloc(size);
}

extern void mavka_ext_free(void* ptr) {
  free(ptr);
}

extern void* mavka_ext_realloc(void* ptr, int size) {
  return realloc(ptr, size);
}

extern int mavka_ext_putchar(unsigned char c) {
  return putchar(c);
}