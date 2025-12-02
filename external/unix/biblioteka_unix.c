#include <stdio.h>
#include <stdlib.h>
#include "../biblioteka.h"
#include "../prystriy.h"

char* read_line_no_newline(size_t* out_len) {
  size_t cap = 128;
  size_t len = 0;
  char* buf = malloc(cap);
  if (!buf)
    return NULL;

  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      break; // stop, but DON'T store '\n'

    if (len + 1 >= cap) {
      cap *= 2;
      char* tmp = realloc(buf, cap);
      if (!tmp) {
        free(buf);
        return NULL;
      }
      buf = tmp;
    }

    buf[len++] = c;
  }

  // If nothing read and EOF, return NULL
  if (len == 0 && c == EOF) {
    free(buf);
    return NULL;
  }

  buf[len] = '\0';

  if (out_len)
    *out_len = len;

  return buf;
}

extern логічне бібліотека_мавки_читати_кд(природне* вихід_розміру,
                                          п8** вихід_даних) {
  size_t len;
  char* data = read_line_no_newline(&len);

  if (!data) {
    return false;
  }

  return пристрій_мавки_перекодувати_ю8_в_кд((природне)len, (п8*)data,
                                             вихід_розміру, вихід_даних, NULL);
}