#include <uv.h>

static void* каллок(size_t num, size_t size) {
  if (num == 0 || size == 0) {
    return пристрій_мавки_виділити(0);
  }

  if (num > SIZE_MAX / size) {
    return NULL;
  }

  size_t total = num * size;
  void* ptr = пристрій_мавки_виділити(total);

  if (ptr != NULL) {
    unsigned char* byte_ptr = (unsigned char*)ptr;
    for (size_t i = 0; i < total; i++) {
      byte_ptr[i] = 0;
    }
  }

  return ptr;
}

static void* мемсет(void* s, int c, size_t n) {
  unsigned char* p = (unsigned char*)s;
  unsigned char val = (unsigned char)c;

  while (n--) {
    *p++ = val;
  }

  return s;
}

static void* мемкоп(void* dest, const void* src, size_t n) {
  if (!dest || !src)
    return dest;

  unsigned char* d = (unsigned char*)dest;
  const unsigned char* s = (const unsigned char*)src;

  while (n--) {
    *d++ = *s++;
  }

  return dest;
}

static char* стрдуп(const char* s) {
  if (!s)
    return NULL;

  size_t len = strlen(s) + 1;
  char* dup = пристрій_мавки_виділити(len);

  if (dup) {
    мемкоп(dup, s, len);
  }

  return dup;
}

#include "./http.c"
#include "./inet.c"