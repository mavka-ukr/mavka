#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

логічне бібліотека_мавки_видалити(природне розмір_шляху, п8* дані_шляху) {
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

  // Get file attributes
  DWORD атрибути = GetFileAttributesW(широкий_шлях);
  if (атрибути == INVALID_FILE_ATTRIBUTES) {
    free(широкий_шлях);
    return FALSE;
  }

  if (атрибути & FILE_ATTRIBUTE_DIRECTORY) {
    // Delete directory recursively
    WIN32_FIND_DATAW знайдені_дані;
    HANDLE знайти_файл;

    size_t довжина_шаблону = wcslen(широкий_шлях) + 3;
    WCHAR* шаблон = (WCHAR*)malloc(довжина_шаблону * sizeof(WCHAR));
    if (!шаблон) {
      free(широкий_шлях);
      return FALSE;
    }
    swprintf(шаблон, довжина_шаблону, L"%s\\*", широкий_шлях);

    знайти_файл = FindFirstFileW(шаблон, &знайдені_дані);
    if (знайти_файл == INVALID_HANDLE_VALUE) {
      free(шаблон);
      free(широкий_шлях);
      return RemoveDirectoryW(широкий_шлях) ? TRUE : FALSE;
    }

    логічне успіх = TRUE;
    do {
      if (wcscmp(знайдені_дані.cFileName, L".") == 0 ||
          wcscmp(знайдені_дані.cFileName, L"..") == 0) {
        continue;
      }

      size_t довжина_повного_шляху =
          wcslen(широкий_шлях) + wcslen(знайдені_дані.cFileName) + 2;
      WCHAR* повний_шлях =
          (WCHAR*)malloc(довжина_повного_шляху * sizeof(WCHAR));
      if (!повний_шлях) {
        успіх = FALSE;
        break;
      }

      swprintf(повний_шлях, довжина_повного_шляху, L"%s\\%s", широкий_шлях,
               знайдені_дані.cFileName);

      // Convert back to UTF-8
      int утф8_довжина =
          WideCharToMultiByte(CP_UTF8, 0, повний_шлях, -1, NULL, 0, NULL, NULL);
      if (утф8_довжина > 0) {
        char* утф8_шлях = (char*)malloc(утф8_довжина);
        if (утф8_шлях) {
          WideCharToMultiByte(CP_UTF8, 0, повний_шлях, -1, утф8_шлях,
                              утф8_довжина, NULL, NULL);
          if (!бібліотека_мавки_видалити(strlen(утф8_шлях), (п8*)утф8_шлях)) {
            успіх = FALSE;
          }
          free(утф8_шлях);
        }
      }
      free(повний_шлях);
    } while (FindNextFileW(знайти_файл, &знайдені_дані));

    FindClose(знайти_файл);
    free(шаблон);
    free(широкий_шлях);

    if (!успіх) {
      return FALSE;
    }

    return RemoveDirectoryW(широкий_шлях);
  } else {
    // Delete file
    BOOL результат = DeleteFileW(широкий_шлях);
    free(широкий_шлях);
    return результат;
  }
}

логічне бібліотека_мавки_дописати_файл(природне розмір_шляху,
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

  // Open file using Windows API in append mode
  HANDLE файл = CreateFileW(широкий_шлях, FILE_APPEND_DATA, 0, NULL,
                            OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

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

логічне бібліотека_мавки_створити_папку(природне розмір_шляху, п8* дані_шляху) {
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

  // Check if directory already exists
  DWORD атрибути = GetFileAttributesW(широкий_шлях);
  if (атрибути != INVALID_FILE_ATTRIBUTES &&
      атрибути & FILE_ATTRIBUTE_DIRECTORY) {
    free(широкий_шлях);
    return TRUE;
  }

  // Create a copy to parse
  size_t копія_розмір = (широких_символів + 1) * sizeof(WCHAR);
  WCHAR* копія_шляху = (WCHAR*)malloc(копія_розмір);
  if (!копія_шляху) {
    free(широкий_шлях);
    return FALSE;
  }
  memcpy(копія_шляху, широкий_шлях, копія_розмір);

  // Create directories recursively
  for (int я = 0; я < широких_символів; я++) {
    if (копія_шляху[я] == L'\\' || копія_шляху[я] == L'/') {
      копія_шляху[я] = L'\0';
      if (я > 0 && я > 2) { // Skip drive letter (C: is 2 chars)
        if (!CreateDirectoryW(копія_шляху, NULL)) {
          DWORD помилка = GetLastError();
          if (помилка != ERROR_ALREADY_EXISTS) {
            free(копія_шляху);
            free(широкий_шлях);
            return FALSE;
          }
        }
      }
      копія_шляху[я] = L'\\';
    }
  }

  // Create the final directory
  if (!CreateDirectoryW(широкий_шлях, NULL)) {
    DWORD помилка = GetLastError();
    if (помилка != ERROR_ALREADY_EXISTS) {
      free(копія_шляху);
      free(широкий_шлях);
      return FALSE;
    }
    // ERROR_ALREADY_EXISTS occurred - verify it's actually a directory, not a file
    DWORD атрибути_фіналь = GetFileAttributesW(широкий_шлях);
    if (атрибути_фіналь == INVALID_FILE_ATTRIBUTES || !(атрибути_фіналь & FILE_ATTRIBUTE_DIRECTORY)) {
      free(копія_шляху);
      free(широкий_шлях);
      return FALSE;
    }
  }

  free(копія_шляху);
  free(широкий_шлях);
  return TRUE;
}