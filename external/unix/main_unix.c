#include <stdlib.h>
#include <string.h>
#include "../main.h"

int main(int argc, char** argv) {
  ю8* аргументи = (ю8*)malloc(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  int r = старт(argc, аргументи);

  free(аргументи);

  return r;
}