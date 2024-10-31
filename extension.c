#include "setjmp.h"

extern int зберегти_інформацію_для_стрибка(void* буфер) {
  return setjmp(буфер);
}

extern void стрибнути_на_збережену_точку(void* буфер, int значення) {
  longjmp(буфер, значення);
}