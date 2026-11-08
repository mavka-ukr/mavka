#include <signal.h>
#include <string.h>

#include "mavka/main.h"
#include "mavka/prystriy.h"

int main(int argc, char** argv) {
  signal(SIGPIPE, SIG_IGN);

  ю8* аргументи = (ю8*)pristriy_mavky_malloc(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  ціле r = почати_мавку_ю8_ю8(argc, аргументи);

  pristriy_mavky_free(аргументи);

  return r;
}