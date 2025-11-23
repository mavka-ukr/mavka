#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t п8;
typedef int32_t ц32;
typedef size_t природне;

typedef struct ю8 ю8;

struct ю8 {
  природне розмір;
  п8* дані;
};

extern ц32 старт(природне кількість_аргументів, ю8* аргументи);

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

// Helper function to convert UTF-16 to UTF-8
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
  // Get Unicode command line arguments
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

  // Free allocated UTF-8 buffers
  for (int i = 0; i < argc; i++) {
    free(allocated_buffers[i]);
  }
  free(allocated_buffers);
  free(аргументи);
  LocalFree(argv);

  return r;
}
#endif

#if defined(__linux__) || defined(__APPLE__)
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
#endif