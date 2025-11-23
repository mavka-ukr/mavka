#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../main.h"

п8* utf16_to_utf8(const wchar_t* utf16_str, природне* out_size) {
  if (!utf16_str) {
    *out_size = 0;
    return NULL;
  }

  int size_needed =
      WideCharToMultiByte(CP_UTF8, 0, utf16_str, -1, NULL, 0, NULL, NULL);
  if (size_needed <= 0) {
    *out_size = 0;
    return NULL;
  }

  п8* utf8_str = (п8*)malloc(size_needed);
  WideCharToMultiByte(CP_UTF8, 0, utf16_str, -1, (char*)utf8_str, size_needed,
                      NULL, NULL);
  *out_size = size_needed - 1; // Exclude null terminator
  return utf8_str;
}

int main(void) {
  int argc;
  wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);
  if (!argv) {
    return 1;
  }

  ю8* аргументи = (ю8*)malloc(argc * sizeof(ю8));
  п8** allocated_buffers = (п8**)malloc(argc * sizeof(п8*));

  for (int i = 0; i < argc; i++) {
    природне size;
    allocated_buffers[i] = utf16_to_utf8(argv[i], &size);
    аргументи[i].розмір = size;
    аргументи[i].дані = allocated_buffers[i];
  }

  int r = старт(argc, аргументи);

  for (int i = 0; i < argc; i++) {
    free(allocated_buffers[i]);
  }
  free(allocated_buffers);
  free(аргументи);
  LocalFree(argv);

  return r;
}