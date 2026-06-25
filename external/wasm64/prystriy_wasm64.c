#include "./walloc.c"
#include "mavka/prystriy.h"

size_t strlen(const char* str);
char* dirname(char* path);
char* strrchr(const char* s, int c);
char* strdup(const char* s);
void* memcpy(void* restrict dest, const void* restrict src, size_t n);
char* basename(char* path);

size_t strlen(const char* str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char* dirname(char* path) {
  static char dot[] = ".";
  size_t len;

  // Return "." if path is NULL or an empty string
  if (path == NULL || *path == '\0') {
    return dot;
  }

  len = strlen(path);

  // Strip trailing slashes, but don't strip the leading slash if it's the only one
  while (len > 1 && path[len - 1] == '/') {
    path[--len] = '\0';
  }

  // If the path was just slashes (e.g., "///"), it's now "/"
  if (len == 1 && path[0] == '/') {
    return path;
  }

  // Find the last remaining slash
  char* last_slash = strrchr(path, '/');

  if (last_slash != NULL) {
    if (last_slash == path) {
      // Path is something like "/usr", dirname is "/"
      path[1] = '\0';
    } else {
      // Path is something like "/usr/bin", dirname is "/usr"
      *last_slash = '\0';
    }
    return path;
  }

  // No slashes remaining, so it's a relative file in the current directory
  return dot;
}

char* strrchr(const char* s, int c) {
  char* last = NULL;
  // The C standard specifies that 'c' is converted to 'unsigned char'
  unsigned char ch = (unsigned char)c;

  // Loop including the null terminator to handle searching for '\0' natively
  for (;;) {
    if ((unsigned char)*s == ch) {
      last = (char*)s;
    }
    if (*s == '\0') {
      break;
    }
    s++;
  }

  return last;
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

char* basename(char* path) {
  static char dot[] = ".";
  size_t len;

  // 1. If path is NULL or an empty string, return "."
  if (path == NULL || *path == '\0') {
    return dot;
  }

  len = strlen(path);

  // 2. Strip trailing slashes, but keep the first slash if it's the only one
  while (len > 1 && path[len - 1] == '/') {
    path[--len] = '\0';
  }

  // 3. If the path was entirely slashes (e.g., "///"), it's now "/"
  if (len == 1 && path[0] == '/') {
    return path;
  }

  // 4. Find the last remaining slash
  char* last_slash = strrchr(path, '/');

  // 5. If a slash is found, the component is everything after it
  if (last_slash != NULL) {
    return last_slash + 1;
  }

  // 6. If no slash is found, the entire string is the basename
  return path;
}

#include "../unix_wasm/prystriy_unix_wasm64.c"