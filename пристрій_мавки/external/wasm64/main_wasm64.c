#include "../include/mavka/main.h"
#include "../include/mavka/prystriy.h"

static size_t strlen(const char* str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

extern ц32 wasmMain(int argc, char** argv) {
  ю8* аргументи = (ю8*)pristriy_mavky_malloc(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  int r = (int)почати_мавку_ю8_ю8(argc, аргументи);

  if (r != 0) {
    goto exit;
  }

exit:
  pristriy_mavky_free(аргументи);
  return r;
}