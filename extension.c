typedef typeof(sizeof(0)) size_t;
extern void *malloc(size_t size);

#include "setjmp.h"

extern void *make_setjmp_buffer() {
  jmp_buf *buf = malloc(sizeof(jmp_buf));
  return buf;
}