#include <stdio.h>
#include <stdlib.h>

extern void* mavka_sysext_malloc(int size) {
  return malloc(size);
}

extern void mavka_sysext_free(void* ptr) {
  free(ptr);
}

extern void* mavka_sysext_realloc(void* ptr, int size) {
  return realloc(ptr, size);
}

extern int mavka_sysext_putchar(unsigned char c) {
  return putchar(c);
}