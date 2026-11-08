#include "./galloc.c"
#include "mavka/prystriy.h"

size_t strlen(const char* str);
char* strdup(const char* s);
void* memcpy(void* restrict dest, const void* restrict src, size_t n);

адреса пристрій_мавки_виділити(природне розмір) {
  return (адреса)malloc(розмір);
}

адреса пристрій_мавки_перевиділити(адреса значення, природне новий_розмір) {
  return (адреса)realloc(значення, новий_розмір);
}

void пристрій_мавки_звільнити(адреса значення) {
  free(значення);
}

size_t strlen(const char* str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char* strdup(const char* s) {
  if (s == NULL) {
    return NULL;
  }

  // 1. Calculate the length of the string
  size_t len = strlen(s);

  // 2. Allocate memory ( +1 byte for the null terminator '\0' )
  char* dup = (char*)malloc(len + 1);

  // 3. Check if malloc failed (out of memory)
  if (dup == NULL) {
    return NULL;
  }

  // 4. Copy the string contents into the new memory block
  memcpy(dup, s, len + 1);

  return dup;
}

void* memcpy(void* restrict dest, const void* restrict src, size_t n) {
  // Cast the void pointers to unsigned char pointers so we can operate byte-by-byte
  unsigned char* d = (unsigned char*)dest;
  const unsigned char* s = (const unsigned char*)src;

  // Loop through and copy each byte
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  // The standard specifies that memcpy always returns the original dest pointer
  return dest;
}
