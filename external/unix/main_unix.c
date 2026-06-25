#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mavka/main.h"

#ifdef PROGRAM_USE_READLINE
#include <readline/readline.h>
#include "mavka/prystriy.h"

extern логічне _користувацький_пристрій_мавки_читати_ю8(
    природне розмір_перед,
    п8* дані_перед,
    природне* вихід_розміру,
    п8** вихід_даних,
    природне дозволити_історію,
    природне* кінець_файлу) {
  char* data = readline((char*)дані_перед);
  if (!data) {
    *кінець_файлу = true;

    return true;
  }

  *вихід_розміру = (природне)strlen(data);
  *вихід_даних = (п8*)data;
  *кінець_файлу = false;

  return true;
}
#endif

int main(int argc, char** argv) {
#ifdef PROGRAM_USE_READLINE
  змінити_користувацький_пристрій_мавки_читати_ю8(
      _користувацький_пристрій_мавки_читати_ю8);
#endif

  ю8* аргументи = (ю8*)malloc(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  int r = почати(argc, аргументи);

  free(аргументи);

  return r;
}