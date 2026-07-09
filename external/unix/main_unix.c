#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>
#include "mavka/main.h"

int main(int argc, char** argv) {
  signal(SIGPIPE, SIG_IGN);

  ю8* аргументи = (ю8*)malloc(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  int r = почати(argc, аргументи);

  free(аргументи);

  if (r != 0) {
    return r;
  }

  return uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}