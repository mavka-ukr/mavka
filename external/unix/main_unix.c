#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mavka/main.h"

#ifdef PROGRAM_USE_READLINE
#include <readline/readline.h>
#include "mavka/prystriy.h"

extern логічне _користувацький_пристрій_мавки_читати_кд(
    природне розмір_перед,
    п8* дані_перед,
    природне* вихід_розміру,
    п8** вихід_даних,
    природне дозволити_історію,
    природне* кінець_файлу) {
  природне prefix_size = 0;
  п8* prefix = NULL;
  природне позиція_помилки;

  if (!пристрій_мавки_перекодувати_кд_в_ю8(
          розмір_перед, дані_перед, &prefix_size, &prefix, &позиція_помилки)) {
    return false;
  }

  char* data = readline((char*)prefix);
  free(prefix);
  if (!data) {
    *кінець_файлу = true;

    return true;
  }

  size_t len = strlen(data);

  *кінець_файлу = false;

  return пристрій_мавки_перекодувати_ю8_в_кд((природне)len, (п8*)data,
                                             вихід_розміру, вихід_даних, NULL);
}
#endif

int main(int argc, char** argv) {
#ifdef PROGRAM_USE_READLINE
  змінити_користувацький_пристрій_мавки_читати_кд(
      _користувацький_пристрій_мавки_читати_кд);
#endif

  ю8* аргументи = (ю8*)malloc(argc * sizeof(ю8));

  for (int i = 0; i < argc; i++) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (п8*)argv[i];
  }

  int r = старт(argc, аргументи);

  free(аргументи);

  return r;
}