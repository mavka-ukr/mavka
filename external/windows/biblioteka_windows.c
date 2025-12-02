#include <windows.h>
#include "../biblioteka.h"
#include "../prystriy.h"

char* read_line_no_newline(size_t* out_len) {
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
  if (hStdin == INVALID_HANDLE_VALUE) {
    return NULL;
  }

  // Read wide characters (UTF-16) for proper Unicode support
  size_t wide_cap = 128;
  size_t wide_len = 0;
  WCHAR* wide_buf =
      (WCHAR*)HeapAlloc(GetProcessHeap(), 0, wide_cap * sizeof(WCHAR));
  if (!wide_buf)
    return NULL;

  WCHAR wc;
  DWORD charsRead;

  while (ReadConsoleW(hStdin, &wc, 1, &charsRead, NULL) && charsRead == 1) {
    if (wc == L'\n')
      break; // stop, but DON'T store '\n'

    if (wc == L'\r')
      continue; // skip '\r' in Windows line endings

    if (wide_len + 1 >= wide_cap) {
      wide_cap *= 2;
      WCHAR* tmp = (WCHAR*)HeapReAlloc(GetProcessHeap(), 0, wide_buf,
                                       wide_cap * sizeof(WCHAR));
      if (!tmp) {
        HeapFree(GetProcessHeap(), 0, wide_buf);
        return NULL;
      }
      wide_buf = tmp;
    }

    wide_buf[wide_len++] = wc;
  }

  // If nothing read, return NULL
  if (wide_len == 0) {
    HeapFree(GetProcessHeap(), 0, wide_buf);
    return NULL;
  }

  // Convert UTF-16 to UTF-8
  int utf8_size =
      WideCharToMultiByte(CP_UTF8, 0, wide_buf, wide_len, NULL, 0, NULL, NULL);
  if (utf8_size == 0) {
    HeapFree(GetProcessHeap(), 0, wide_buf);
    return NULL;
  }

  char* buf = (char*)HeapAlloc(GetProcessHeap(), 0, utf8_size + 1);
  if (!buf) {
    HeapFree(GetProcessHeap(), 0, wide_buf);
    return NULL;
  }

  WideCharToMultiByte(CP_UTF8, 0, wide_buf, wide_len, buf, utf8_size, NULL,
                      NULL);
  buf[utf8_size] = '\0';

  HeapFree(GetProcessHeap(), 0, wide_buf);

  if (out_len)
    *out_len = utf8_size;

  return buf;
}

extern логічне бібліотека_мавки_читати_кд(природне* вихід_розміру,
                                          п8** вихід_даних) {
  size_t len;
  char* data = read_line_no_newline(&len);

  if (!data) {
    return FALSE;
  }

  return пристрій_мавки_перекодувати_ю8_в_кд((природне)len, (п8*)data,
                                             вихід_розміру, вихід_даних, NULL);
}