#include "mavka/main.h"
#include "mavka/prystriy.h"

size_t strlen(const char* str);

extern ц32 xmain(int argc, char** argv) {
  ю8* аргументи = (ю8*)пристрій_мавки_виділити_сиру_памʼять(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  int r = почати(argc, аргументи);

  пристрій_мавки_звільнити_сиру_памʼять(аргументи);

  return r;
}