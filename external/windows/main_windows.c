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

  HANDLE купа = GetProcessHeap();
  п8* utf8_str = (п8*)HeapAlloc(купа, 0, size_needed);
  if (!utf8_str) {
    *out_size = 0;
    return NULL;
  }

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

  HANDLE купа = GetProcessHeap();

  ю8* аргументи = (ю8*)HeapAlloc(купа, 0, argc * sizeof(ю8));
  if (!аргументи) {
    LocalFree(argv);
    return 1;
  }

  п8** allocated_buffers = (п8**)HeapAlloc(купа, 0, argc * sizeof(п8*));
  if (!allocated_buffers) {
    HeapFree(купа, 0, аргументи);
    LocalFree(argv);
    return 1;
  }

  for (int i = 0; i < argc; i++) {
    природне size;
    allocated_buffers[i] = utf16_to_utf8(argv[i], &size);
    аргументи[i].розмір = size;
    аргументи[i].дані = allocated_buffers[i];
  }

  int r = старт(argc, аргументи);

  for (int i = 0; i < argc; i++) {
    if (allocated_buffers[i]) {
      HeapFree(купа, 0, allocated_buffers[i]);
    }
  }
  HeapFree(купа, 0, allocated_buffers);
  HeapFree(купа, 0, аргументи);
  LocalFree(argv);

  return r;
}