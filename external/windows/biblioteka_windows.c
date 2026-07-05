#include <math.h>
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

р64 бібліотека_мавки_корінь2_р64(р64 значення) {
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

логічне бібліотека_мавки_видалити(п8* дані_шляху, природне розмір_шляху) {
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях =
      (WCHAR*)пристрій_мавки_виділити((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  DWORD атрибути = GetFileAttributesW(широкий_шлях);
  if (атрибути == INVALID_FILE_ATTRIBUTES) {
    пристрій_мавки_звільнити(широкий_шлях);
    return FALSE;
  }

  if (атрибути & FILE_ATTRIBUTE_DIRECTORY) {
    WIN32_FIND_DATAW знайдені_дані;
    HANDLE знайти_файл;

    size_t довжина_шаблону = lstrlenW(широкий_шлях) + 3;
    WCHAR* шаблон =
        (WCHAR*)пристрій_мавки_виділити(довжина_шаблону * sizeof(WCHAR));
    if (!шаблон) {
      пристрій_мавки_звільнити(широкий_шлях);
      return FALSE;
    }
    wsprintfW(шаблон, L"%s\\*", широкий_шлях);

    знайти_файл = FindFirstFileW(шаблон, &знайдені_дані);
    if (знайти_файл == INVALID_HANDLE_VALUE) {
      пристрій_мавки_звільнити(шаблон);
      пристрій_мавки_звільнити(широкий_шлях);
      return RemoveDirectoryW(широкий_шлях) ? TRUE : FALSE;
    }

    логічне успіх = TRUE;
    do {
      if (lstrcmpW(знайдені_дані.cFileName, L".") == 0 ||
          lstrcmpW(знайдені_дані.cFileName, L"..") == 0) {
        continue;
      }

      size_t довжина_повного_шляху =
          lstrlenW(широкий_шлях) + lstrlenW(знайдені_дані.cFileName) + 2;
      WCHAR* повний_шлях = (WCHAR*)пристрій_мавки_виділити(
          довжина_повного_шляху * sizeof(WCHAR));
      if (!повний_шлях) {
        успіх = FALSE;
        break;
      }

      wsprintfW(повний_шлях, L"%s\\%s", широкий_шлях, знайдені_дані.cFileName);

      int утф8_довжина =
          WideCharToMultiByte(CP_UTF8, 0, повний_шлях, -1, NULL, 0, NULL, NULL);
      if (утф8_довжина > 0) {
        char* утф8_шлях = (char*)пристрій_мавки_виділити(утф8_довжина);
        if (утф8_шлях) {
          WideCharToMultiByte(CP_UTF8, 0, повний_шлях, -1, утф8_шлях,
                              утф8_довжина, NULL, NULL);

          int утф8_чиста_довжина = утф8_довжина - 1;
          if (!бібліотека_мавки_видалити((п8*)утф8_шлях, утф8_чиста_довжина)) {
            успіх = FALSE;
          }
          пристрій_мавки_звільнити(утф8_шлях);
        }
      }
      пристрій_мавки_звільнити(повний_шлях);
    } while (FindNextFileW(знайти_файл, &знайдені_дані));

    FindClose(знайти_файл);
    пристрій_мавки_звільнити(шаблон);
    пристрій_мавки_звільнити(широкий_шлях);

    if (!успіх) {
      return FALSE;
    }

    return RemoveDirectoryW(широкий_шлях);
  } else {
    BOOL результат = DeleteFileW(широкий_шлях);
    пристрій_мавки_звільнити(широкий_шлях);
    return результат;
  }
}

логічне бібліотека_мавки_дописати_файл(п8* дані_шляху,
                                       природне розмір_шляху,
                                       п8* дані_даних,
                                       природне розмір_даних) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях =
      (WCHAR*)пристрій_мавки_виділити((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Open file using Windows API in append mode
  HANDLE файл = CreateFileW(широкий_шлях, FILE_APPEND_DATA, 0, NULL,
                            OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

  пристрій_мавки_звільнити(широкий_шлях);

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

логічне бібліотека_мавки_записати_файл(п8* дані_шляху,
                                       природне розмір_шляху,
                                       п8* дані_даних,
                                       природне розмір_даних) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях =
      (WCHAR*)пристрій_мавки_виділити((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Create file using Windows API
  HANDLE файл = CreateFileW(широкий_шлях, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL, NULL);

  пристрій_мавки_звільнити(широкий_шлях);

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

логічне бібліотека_мавки_прочитати_файл(п8* дані_шляху,
                                        природне розмір_шляху,
                                        Дані* вихід) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях =
      (WCHAR*)пристрій_мавки_виділити((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Open file using Windows API
  HANDLE файл = CreateFileW(широкий_шлях, GENERIC_READ, FILE_SHARE_READ, NULL,
                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  пристрій_мавки_звільнити(широкий_шлях);

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
  вихід->дані = (п8*)пристрій_мавки_виділити(вихід->розмір);
  if (!вихід->дані) {
    CloseHandle(файл);
    return FALSE;
  }

  // Read file
  DWORD прочитано;
  if (!ReadFile(файл, вихід->дані, вихід->розмір, &прочитано, NULL)) {
    пристрій_мавки_звільнити(вихід->дані);
    CloseHandle(файл);
    return FALSE;
  }

  CloseHandle(файл);

  return прочитано == вихід->розмір;
}

логічне бібліотека_мавки_створити_папку(п8* дані_шляху, природне розмір_шляху) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях =
      (WCHAR*)пристрій_мавки_виділити((широких_символів + 1) * sizeof(WCHAR));
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
    пристрій_мавки_звільнити(широкий_шлях);
    return TRUE;
  }

  // Create a copy to parse
  size_t копія_розмір = (широких_символів + 1) * sizeof(WCHAR);
  WCHAR* копія_шляху = (WCHAR*)пристрій_мавки_виділити(копія_розмір);
  if (!копія_шляху) {
    пристрій_мавки_звільнити(широкий_шлях);
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
            пристрій_мавки_звільнити(копія_шляху);
            пристрій_мавки_звільнити(широкий_шлях);
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
      пристрій_мавки_звільнити(копія_шляху);
      пристрій_мавки_звільнити(широкий_шлях);
      return FALSE;
    }
    // ERROR_ALREADY_EXISTS occurred - verify it's actually a directory, not a file
    DWORD атрибути_фіналь = GetFileAttributesW(широкий_шлях);
    if (атрибути_фіналь == INVALID_FILE_ATTRIBUTES ||
        !(атрибути_фіналь & FILE_ATTRIBUTE_DIRECTORY)) {
      пристрій_мавки_звільнити(копія_шляху);
      пристрій_мавки_звільнити(широкий_шлях);
      return FALSE;
    }
  }

  пристрій_мавки_звільнити(копія_шляху);
  пристрій_мавки_звільнити(широкий_шлях);
  return TRUE;
}

static WCHAR* utf8_to_wide(const п8* utf8) {
  if (!utf8) {
    return NULL;
  }

  int count = MultiByteToWideChar(CP_UTF8, 0, (const char*)utf8, -1, NULL, 0);
  if (count == 0) {
    return NULL;
  }

  WCHAR* wide = (WCHAR*)пристрій_мавки_виділити(count * sizeof(WCHAR));
  if (!wide) {
    return NULL;
  }

  if (MultiByteToWideChar(CP_UTF8, 0, (const char*)utf8, -1, wide, count) ==
      0) {
    пристрій_мавки_звільнити(wide);
    return NULL;
  }

  return wide;
}
