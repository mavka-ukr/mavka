#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

р64 бібліотека_мавки_синус_р64(р64 значення) {
  return sin(значення);
}

р64 бібліотека_мавки_косинус_р64(р64 значення) {
  return cos(значення);
}

р64 бібліотека_мавки_тангенс_р64(р64 значення) {
  return tan(значення);
}

р64 бібліотека_мавки_арксинус_р64(р64 значення) {
  return asin(значення);
}

р64 бібліотека_мавки_арккосинус_р64(р64 значення) {
  return acos(значення);
}

р64 бібліотека_мавки_арктангенс_р64(р64 значення) {
  return atan(значення);
}

р64 бібліотека_мавки_арктангенс2_р64(р64 а, р64 б) {
  return atan2(а, б);
}

р64 бібліотека_мавки_абсолютне_р64(р64 значення) {
  return fabs(значення);
}

р64 бібліотека_мавки_експонента_р64(р64 значення) {
  return exp(значення);
}

р64 бібліотека_мавки_корінь_р64(р64 значення) {
  return sqrt(значення);
}

р64 бібліотека_мавки_стеля_р64(р64 значення) {
  return ceil(значення);
}

р64 бібліотека_мавки_підлога_р64(р64 значення) {
  return floor(значення);
}

р64 бібліотека_мавки_округлити_р64(р64 значення) {
  return round(значення);
}

р64 бібліотека_мавки_остача_від_ділення_р64(р64 а, р64 б) {
  return fmod(а, б);
}

логічне бібліотека_мавки_записати_файл(природне розмір_шляху,
                                       п8* дані_шляху,
                                       природне розмір_даних,
                                       п8* дані_даних) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)malloc((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Create file using Windows API
  HANDLE файл = CreateFileW(широкий_шлях, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL, NULL);

  free(широкий_шлях);

  if (файл == INVALID_HANDLE_VALUE) {
    return FALSE;
  }

  // Write file
  DWORD записано;
  if (!WriteFile(файл, дані_даних, розмір_даних, &записано, NULL)) {
    CloseHandle(файл);
    return FALSE;
  }

  CloseHandle(файл);
  return записано == розмір_даних;
}

логічне бібліотека_мавки_прочитати_файл(природне розмір_шляху,
                                        п8* дані_шляху,
                                        Дані* вихід) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)malloc((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Open file using Windows API
  HANDLE файл = CreateFileW(широкий_шлях, GENERIC_READ, FILE_SHARE_READ, NULL,
                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  free(широкий_шлях);

  if (файл == INVALID_HANDLE_VALUE) {
    return FALSE;
  }

  // Get file size
  LARGE_INTEGER розмір_файлу;
  if (!GetFileSizeEx(файл, &розмір_файлу)) {
    CloseHandle(файл);
    return FALSE;
  }

  вихід->розмір = (природне)розмір_файлу.QuadPart;

  // Allocate buffer
  вихід->дані = (п8*)malloc(вихід->розмір);
  if (!вихід->дані) {
    CloseHandle(файл);
    return FALSE;
  }

  // Read file
  DWORD прочитано;
  if (!ReadFile(файл, вихід->дані, вихід->розмір, &прочитано, NULL)) {
    free(вихід->дані);
    CloseHandle(файл);
    return FALSE;
  }

  CloseHandle(файл);

  return прочитано == вихід->розмір;
}