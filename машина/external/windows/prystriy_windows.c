#include <stdio.h>
#include <windows.h>
#include "mavka/prystriy.h"

логічне (*користувацький_пристрій_мавки_читати_кд)(природне розмір_перед,
                                                   п8* дані_перед,
                                                   природне* вихід_розміру,
                                                   п8** вихід_даних,
                                                   природне дозволити_історію,
                                                   природне* кінець_файлу) =
    NULL;

void out_utf8_data(п8* дані, природне розмір) {
  if (розмір == 0) {
    return;
  }

  // Convert UTF-8 to UTF-16 for Windows
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані, розмір, NULL, 0);
  if (широких_символів == 0) {
    return;
  }

  WCHAR* широкий_буфер =
      (WCHAR*)HeapAlloc(GetProcessHeap(), 0, широких_символів * sizeof(WCHAR));
  if (!широкий_буфер) {
    return;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані, розмір, широкий_буфер,
                      широких_символів);

  // Write to console using Windows API
  HANDLE консоль = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD записано;
  WriteConsoleW(консоль, широкий_буфер, широких_символів, &записано, NULL);

  HeapFree(GetProcessHeap(), 0, широкий_буфер);
}

void out_utf8_string(char* дані) {
  if (!дані) {
    return;
  }

  // Calculate string length
  природне довжина = 0;
  while (дані[довжина] != '\0') {
    довжина++;
  }

  out_utf8_data((п8*)дані, довжина);
}

extern логічне пристрій_мавки_отримати_версію(природне* вихід_розміру,
                                              п8** вихід_даних) {
  char* версія_ю8 = PROGRAM_VERSION;

  природне довжина_версії_ю8 = 0;
  while (версія_ю8[довжина_версії_ю8] != '\0') {
    довжина_версії_ю8++;
  }

  природне позиція_помилки;

  if (пристрій_мавки_перекодувати_ю8_в_кд(довжина_версії_ю8, (п8*)версія_ю8,
                                          вихід_розміру, вихід_даних,
                                          &позиція_помилки)) {
    return TRUE;
  }

  return FALSE;
}

extern void пристрій_мавки_вивести_формат(природне значення) {
  HANDLE консоль = GetStdHandle(STD_OUTPUT_HANDLE);

  // Enable virtual terminal processing for ANSI color support
  DWORD режим;
  if (GetConsoleMode(консоль, &режим)) {
    SetConsoleMode(консоль, режим | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  }

  WORD атрибути;
  switch (значення) {
    case 0: // ФОчистити - reset to default
      атрибути = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
    case 1: // ФКолірТекстуЧервоний
      атрибути = FOREGROUND_RED | FOREGROUND_INTENSITY;
      break;
    case 2: // ФКолірТекстуЗелений
      атрибути = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
      break;
    case 3: // ФКолірТекстуСиній
      атрибути = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
      break;
    case 4: // ФКолірТекстуЖовтий
      атрибути = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
      break;
    default:
      атрибути = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
  }

  SetConsoleTextAttribute(консоль, атрибути);
}

extern void пристрій_мавки_вивести_сирі_дані(природне розмір, п8* дані) {
  out_utf8_data(дані, розмір);
}

extern void пристрій_мавки_вивести_кд(природне розмір, п8* дані) {
  природне розмір_ю8;
  п8* дані_ю8;
  природне позиція_помилки;

  if (пристрій_мавки_перекодувати_кд_в_ю8(розмір, дані, &розмір_ю8, &дані_ю8,
                                          &позиція_помилки)) {
    out_utf8_data(дані_ю8, розмір_ю8);
    пристрій_мавки_звільнити_сиру_памʼять(дані_ю8);
  } else {
    out_utf8_string("помилка виводу кд\n");
  }
}

extern void пристрій_мавки_надрукувати_кд(природне розмір, п8* дані) {
  природне розмір_ю8;
  п8* дані_ю8;
  природне позиція_помилки;

  if (пристрій_мавки_перекодувати_кд_в_ю8(розмір, дані, &розмір_ю8, &дані_ю8,
                                          &позиція_помилки)) {
    out_utf8_data(дані_ю8, розмір_ю8);
    out_utf8_string("\n");
    пристрій_мавки_звільнити_сиру_памʼять(дані_ю8);
  } else {
    out_utf8_string("помилка друку кд\n");
  }
}

extern void пристрій_мавки_вивести_шлях(природне розмір, п8* дані) {
  out_utf8_data(дані, розмір);
}

extern void пристрій_мавки_надрукувати_шлях(природне розмір, п8* дані) {
  out_utf8_data(дані, розмір);
  out_utf8_string("\n");
}

extern void пристрій_мавки_вивести_ю8(природне розмір, п8* дані) {
  out_utf8_data(дані, розмір);
}

extern void пристрій_мавки_надрукувати_ю8(природне розмір, п8* дані) {
  out_utf8_data(дані, розмір);
  out_utf8_string("\n");
}

extern п8* пристрій_мавки_виділити_сиру_памʼять(природне розмір) {
  HANDLE купа = GetProcessHeap();
  return (п8*)HeapAlloc(купа, 0, розмір);
}

extern п8* пристрій_мавки_перевиділити_сиру_памʼять(п8* значення,
                                                    природне новий_розмір) {
  HANDLE купа = GetProcessHeap();
  if (значення == NULL) {
    return (п8*)HeapAlloc(купа, 0, новий_розмір);
  }
  return (п8*)HeapReAlloc(купа, 0, значення, новий_розмір);
}

extern void пристрій_мавки_звільнити_сиру_памʼять(п8* значення) {
  if (значення != NULL) {
    HANDLE купа = GetProcessHeap();
    HeapFree(купа, 0, значення);
  }
}

extern void пристрій_мавки_вийти(ц32 код_виходу) {
  ExitProcess((UINT)код_виходу);
}

extern логічне пристрій_мавки_прочитати_файл(природне розмір_шляху,
                                             п8* дані_шляху,
                                             природне* вихід_розміру,
                                             п8** вихід_даних) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Open file using Windows API
  HANDLE файл = CreateFileW(широкий_шлях, GENERIC_READ, FILE_SHARE_READ, NULL,
                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  HeapFree(GetProcessHeap(), 0, широкий_шлях);

  if (файл == INVALID_HANDLE_VALUE) {
    return FALSE;
  }

  // Get file size
  LARGE_INTEGER розмір_файлу;
  if (!GetFileSizeEx(файл, &розмір_файлу)) {
    CloseHandle(файл);
    return FALSE;
  }

  *вихід_розміру = (природне)розмір_файлу.QuadPart;

  // Allocate buffer
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    CloseHandle(файл);
    return FALSE;
  }

  // Read file
  DWORD прочитано;
  if (!ReadFile(файл, *вихід_даних, *вихід_розміру, &прочитано, NULL)) {
    HeapFree(GetProcessHeap(), 0, *вихід_даних);
    CloseHandle(файл);
    return FALSE;
  }

  CloseHandle(файл);
  return TRUE;
}

логічне перетворити_п64_в_ю8(п64 значення,
                             природне* вихід_розміру,
                             п8** вихід_даних) {
  char буфер[32];
  int довжина = wsprintfA(буфер, "%I64u", значення);
  if (довжина <= 0) {
    return FALSE;
  }
  *вихід_розміру = (природне)довжина;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    return FALSE;
  }
  for (природне і = 0; і < *вихід_розміру; і++) {
    (*вихід_даних)[і] = (п8)буфер[і];
  }
  return TRUE;
}

логічне перетворити_ц64_в_ю8(ц64 значення,
                             природне* вихід_розміру,
                             п8** вихід_даних) {
  char буфер[32];
  int довжина = wsprintfA(буфер, "%I64d", значення);
  if (довжина <= 0) {
    return FALSE;
  }
  *вихід_розміру = (природне)довжина;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    return FALSE;
  }
  for (природне і = 0; і < *вихід_розміру; і++) {
    (*вихід_даних)[і] = (п8)буфер[і];
  }
  return TRUE;
}

логічне перетворити_д64_в_ю8(д64 значення,
                             природне* вихід_розміру,
                             п8** вихід_даних,
                             ціле* вихід_розміру_експоненти) {
  char буфер[64];
  int довжина;

  // Check for NaN
  if (значення != значення) { // NaN != NaN
    char nan_str[] = "невизначеність";
    *вихід_розміру = sizeof(nan_str) - 1;
    *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
    if (!*вихід_даних)
      return FALSE;
    for (природне і = 0; і < *вихід_розміру; і++) {
      (*вихід_даних)[і] = (п8)nan_str[і];
    }
    *вихід_розміру_експоненти = 0;
    return TRUE;
  }

  // Check for infinity
  if (значення > 1e308 || значення < -1e308) {
    char* inf_str = значення > 0 ? "нескінченність" : "-нескінченність";
    *вихід_розміру = значення > 0 ? sizeof("нескінченність") - 1
                                  : sizeof("-нескінченність") - 1;
    *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
    if (!*вихід_даних)
      return FALSE;
    for (природне і = 0; і < *вихід_розміру; і++) {
      (*вихід_даних)[і] = (п8)inf_str[і];
    }
    *вихід_розміру_експоненти = 0;
    return TRUE;
  }

  довжина = sprintf(буфер, "%.16g", значення);
  if (довжина < 0 || довжина >= (int)sizeof(буфер)) {
    return FALSE;
  }

  // Find 'e' for exponential notation
  char* e_pos = NULL;
  for (int і = 0; і < довжина; і++) {
    if (буфер[і] == 'e') {
      e_pos = &буфер[і];
      break;
    }
  }

  if (e_pos != NULL) {
    // Parse exponent
    *вихід_розміру_експоненти = 0;
    ціле знак_експоненти = 1;
    char* p = e_pos + 1;
    if (*p == '+') {
      p++;
    } else if (*p == '-') {
      знак_експоненти = -1;
      p++;
    }
    while (*p >= '0' && *p <= '9') {
      *вихід_розміру_експоненти = *вихід_розміру_експоненти * 10 + (*p - '0');
      p++;
    }
    *вихід_розміру_експоненти *= знак_експоненти;

    природне довжина_мантиси = (природне)(e_pos - буфер);

    *вихід_розміру = довжина_мантиси;
    *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
    if (!*вихід_даних)
      return FALSE;

    for (природне і = 0; і < довжина_мантиси; і++) {
      (*вихід_даних)[і] = (п8)буфер[і];
    }
  } else {
    *вихід_розміру_експоненти = 0;

    // Find decimal point
    char* dot_pos = NULL;
    for (int і = 0; і < довжина; і++) {
      if (буфер[і] == '.') {
        dot_pos = &буфер[і];
        break;
      }
    }

    if (dot_pos != NULL) {
      int end = довжина - 1;
      while (end > (dot_pos - буфер) && буфер[end] == '0') {
        end--;
      }
      if (буфер[end] == '.') {
        end--;
      }
      довжина = end + 1;
    }

    *вихід_розміру = (природне)довжина;
    *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
    if (!*вихід_даних)
      return FALSE;

    for (природне і = 0; і < *вихід_розміру; і++) {
      (*вихід_даних)[і] = (п8)буфер[і];
    }
  }

  return TRUE;
}

extern логічне пристрій_мавки_перетворити_п64_в_кд(п64 значення,
                                                   природне* вихід_розміру,
                                                   п8** вихід_даних) {
  природне розмір_ю8;
  п8* дані_ю8;
  природне позиція_помилки;

  if (перетворити_п64_в_ю8(значення, &розмір_ю8, &дані_ю8)) {
    if (пристрій_мавки_перекодувати_ю8_в_кд(розмір_ю8, дані_ю8, вихід_розміру,
                                            вихід_даних, &позиція_помилки)) {
      HeapFree(GetProcessHeap(), 0, дані_ю8);

      return TRUE;
    }

    HeapFree(GetProcessHeap(), 0, дані_ю8);
  }

  return FALSE;
}

extern логічне пристрій_мавки_перетворити_ц64_в_кд(ц64 значення,
                                                   природне* вихід_розміру,
                                                   п8** вихід_даних) {
  природне розмір_ю8;
  п8* дані_ю8;
  природне позиція_помилки;

  if (перетворити_ц64_в_ю8(значення, &розмір_ю8, &дані_ю8)) {
    if (пристрій_мавки_перекодувати_ю8_в_кд(розмір_ю8, дані_ю8, вихід_розміру,
                                            вихід_даних, &позиція_помилки)) {
      HeapFree(GetProcessHeap(), 0, дані_ю8);

      return TRUE;
    }

    HeapFree(GetProcessHeap(), 0, дані_ю8);
  }

  return FALSE;
}

extern логічне пристрій_мавки_перетворити_д64_в_кд(
    д64 значення,
    природне* вихід_розміру,
    п8** вихід_даних,
    ціле* вихід_розміру_експоненти) {
  природне розмір_ю8;
  п8* дані_ю8;
  природне позиція_помилки;

  if (перетворити_д64_в_ю8(значення, &розмір_ю8, &дані_ю8,
                           вихід_розміру_експоненти)) {
    if (пристрій_мавки_перекодувати_ю8_в_кд(розмір_ю8, дані_ю8, вихід_розміру,
                                            вихід_даних, &позиція_помилки)) {
      HeapFree(GetProcessHeap(), 0, дані_ю8);

      return TRUE;
    }

    HeapFree(GetProcessHeap(), 0, дані_ю8);
  }

  return FALSE;
}

extern п64 пристрій_мавки_піднести_до_степеня_п64(п64 значення, п64 степінь) {
  п64 результат = 1;
  for (п64 і = 0; і < степінь; і++) {
    результат *= значення;
  }
  return результат;
}

extern ц64 пристрій_мавки_піднести_до_степеня_ц64(ц64 значення, ц64 степінь) {
  ц64 результат = 1;
  for (ц64 і = 0; і < степінь; і++) {
    результат *= значення;
  }
  return результат;
}

extern д64 пристрій_мавки_піднести_до_степеня_д64(д64 значення, д64 степінь) {
  double результат = 1.0;
  for (double і = 0; і < степінь; і++) {
    результат *= значення;
  }
  return результат;
}

extern логічне пристрій_мавки_перевірити_чи_шлях_існує_і_є_файлом(
    природне розмір_шляху,
    п8* дані_шляху) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Get file attributes using Windows API
  DWORD атрибути = GetFileAttributesW(широкий_шлях);
  HeapFree(GetProcessHeap(), 0, широкий_шлях);

  if (атрибути == INVALID_FILE_ATTRIBUTES) {
    return FALSE;
  }

  // Check if it's a regular file (not a directory)
  return (атрибути & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

extern логічне пристрій_мавки_перевірити_чи_шлях_закінчується_як_модуль_мавки(
    природне розмір_шляху,
    п8* дані_шляху) {
  const char* суфікс = ".м";
  природне довжина_суфікса = 0;
  while (суфікс[довжина_суфікса] != '\0') {
    довжина_суфікса++;
  }

  if (розмір_шляху < довжина_суфікса) {
    return FALSE;
  }

  for (природне і = 0; і < довжина_суфікса; і++) {
    if (дані_шляху[розмір_шляху - довжина_суфікса + і] != (п8)суфікс[і]) {
      return FALSE;
    }
  }

  return TRUE;
}

extern логічне пристрій_мавки_отримати_абсолютний_шлях(природне розмір_шляху,
                                                       п8* дані_шляху,
                                                       природне* вихід_розміру,
                                                       п8** вихід_даних) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Get full path using Windows API
  DWORD потрібно = GetFullPathNameW(широкий_шлях, 0, NULL, NULL);
  if (потрібно == 0) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  WCHAR* абсолютний_широкий =
      (WCHAR*)HeapAlloc(GetProcessHeap(), 0, потрібно * sizeof(WCHAR));
  if (!абсолютний_широкий) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  if (GetFullPathNameW(широкий_шлях, потрібно, абсолютний_широкий, NULL) == 0) {
    HeapFree(GetProcessHeap(), 0, абсолютний_широкий);
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  HeapFree(GetProcessHeap(), 0, широкий_шлях);

  // Convert back to UTF-8
  int байтів_ю8 = WideCharToMultiByte(CP_UTF8, 0, абсолютний_широкий, -1, NULL,
                                      0, NULL, NULL);
  if (байтів_ю8 == 0) {
    HeapFree(GetProcessHeap(), 0, абсолютний_широкий);
    return FALSE;
  }

  *вихід_розміру = байтів_ю8 - 1; // Exclude null terminator
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    HeapFree(GetProcessHeap(), 0, абсолютний_широкий);
    return FALSE;
  }

  WideCharToMultiByte(CP_UTF8, 0, абсолютний_широкий, -1, (char*)*вихід_даних,
                      байтів_ю8, NULL, NULL);

  HeapFree(GetProcessHeap(), 0, абсолютний_широкий);
  return TRUE;
}

extern логічне пристрій_мавки_отримати_теку_шляху(природне розмір_шляху,
                                                  п8* дані_шляху,
                                                  природне* вихід_розміру,
                                                  п8** вихід_даних,
                                                  природне рівень) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Find parent directory 'рівень' times
  for (природне і = 0; і < рівень; і++) {
    // Find last backslash or forward slash
    WCHAR* остання_коса = NULL;
    for (int j = широких_символів - 1; j >= 0; j--) {
      if (широкий_шлях[j] == L'\\') {
        остання_коса = &широкий_шлях[j];
        широких_символів = j;
        break;
      }
    }

    if (остання_коса) {
      *остання_коса = L'\0';
    } else {
      // No more parent directories
      break;
    }
  }

  // Convert back to UTF-8
  int байтів_ю8 =
      WideCharToMultiByte(CP_UTF8, 0, широкий_шлях, -1, NULL, 0, NULL, NULL);
  if (байтів_ю8 == 0) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  *вихід_розміру = байтів_ю8 - 1; // Exclude null terminator
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  WideCharToMultiByte(CP_UTF8, 0, широкий_шлях, -1, (char*)*вихід_даних,
                      байтів_ю8 - 1, NULL, NULL);

  HeapFree(GetProcessHeap(), 0, широкий_шлях);
  return TRUE;
}

extern логічне пристрій_мавки_отримати_теку_до_паків(природне розмір_шляху,
                                                     п8* дані_шляху,
                                                     природне* вихід_розміру,
                                                     п8** вихід_даних) {
  const char* паки_суфікс = "\\паки";
  природне довжина_суфікса = 0;
  while (паки_суфікс[довжина_суфікса] != '\0') {
    довжина_суфікса++;
  }

  *вихід_розміру = розмір_шляху + довжина_суфікса;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    return FALSE;
  }

  for (природне і = 0; і < розмір_шляху; і++) {
    (*вихід_даних)[і] = дані_шляху[і];
  }
  for (природне і = 0; і < довжина_суфікса; і++) {
    (*вихід_даних)[розмір_шляху + і] = (п8)паки_суфікс[і];
  }

  return TRUE;
}

extern логічне пристрій_мавки_отримати_назву_модуля_з_шляху(
    природне розмір_шляху,
    п8* дані_шляху,
    природне* вихід_розміру,
    п8** вихід_даних) {
  // Find the last slash or backslash to get basename
  природне позиція_останньої_коси = 0;
  логічне знайдено_косу = FALSE;

  for (природне і = 0; і < розмір_шляху; і++) {
    if (дані_шляху[і] == '\\') {
      позиція_останньої_коси = і + 1;
      знайдено_косу = TRUE;
    }
  }

  // Extract basename
  природне початок_назви = знайдено_косу ? позиція_останньої_коси : 0;
  природне довжина_назви = розмір_шляху - початок_назви;

  // Check and remove ".м" suffix
  const char* суфікс = ".м";
  природне довжина_суфікса = 0;
  while (суфікс[довжина_суфікса] != '\0') {
    довжина_суфікса++;
  }

  if (довжина_назви >= довжина_суфікса) {
    логічне має_суфікс = TRUE;
    for (природне і = 0; і < довжина_суфікса; і++) {
      if (дані_шляху[початок_назви + довжина_назви - довжина_суфікса + і] !=
          (п8)суфікс[і]) {
        має_суфікс = FALSE;
        break;
      }
    }
    if (має_суфікс) {
      довжина_назви -= довжина_суфікса;
    }
  }

  // Create a copy of the name for conversion
  п8* назва_ю8 = (п8*)HeapAlloc(GetProcessHeap(), 0, довжина_назви);
  if (!назва_ю8) {
    return FALSE;
  }

  for (природне і = 0; і < довжина_назви; і++) {
    назва_ю8[і] = дані_шляху[початок_назви + і];
  }

  // Convert UTF-8 to КД encoding
  природне позиція_помилки;
  логічне результат = пристрій_мавки_перекодувати_ю8_в_кд(
      довжина_назви, назва_ю8, вихід_розміру, вихід_даних, &позиція_помилки);

  HeapFree(GetProcessHeap(), 0, назва_ю8);
  return результат;
}

extern логічне пристрій_мавки_збити_шлях_до_модуля(
    природне кількість_елементів,
    ЕлементШляхуПристроюМавки* елементи,
    природне* вихід_розміру,
    п8** вихід_даних) {
  const char* суфікс = ".м";
  природне довжина_суфікса = 0;
  while (суфікс[довжина_суфікса] != '\0') {
    довжина_суфікса++;
  }

  природне загальний_розмір = кількість_елементів - 1 + довжина_суфікса;

  for (природне і = 0; і < кількість_елементів; і++) {
    загальний_розмір += елементи[і].розмір;
  }

  *вихід_розміру = загальний_розмір;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, загальний_розмір);
  if (!*вихід_даних) {
    return FALSE;
  }

  природне позиція = 0;
  for (природне і = 0; і < кількість_елементів; і++) {
    for (природне j = 0; j < елементи[і].розмір; j++) {
      (*вихід_даних)[позиція++] = елементи[і].дані[j];
    }
    if (і < кількість_елементів - 1) {
      (*вихід_даних)[позиція++] = '\\';
    }
  }

  for (природне і = 0; і < довжина_суфікса; і++) {
    (*вихід_даних)[позиція++] = (п8)суфікс[і];
  }

  return TRUE;
}

extern логічне пристрій_мавки_отримати_відносний_шлях(природне розмір_шляху,
                                                      п8* дані_шляху,
                                                      природне* вихід_розміру,
                                                      п8** вихід_даних) {
  // Convert input path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)дані_шляху, розмір_шляху, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Get current working directory
  DWORD розмір_поточної = GetCurrentDirectoryW(0, NULL);
  if (розмір_поточної == 0) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  WCHAR* поточна_тека =
      (WCHAR*)HeapAlloc(GetProcessHeap(), 0, розмір_поточної * sizeof(WCHAR));
  if (!поточна_тека) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  if (GetCurrentDirectoryW(розмір_поточної, поточна_тека) == 0) {
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  // Get absolute path of the input
  DWORD розмір_абсолютного = GetFullPathNameW(широкий_шлях, 0, NULL, NULL);
  if (розмір_абсолютного == 0) {
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  WCHAR* абсолютний_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, розмір_абсолютного * sizeof(WCHAR));
  if (!абсолютний_шлях) {
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  if (GetFullPathNameW(широкий_шлях, розмір_абсолютного, абсолютний_шлях,
                       NULL) == 0) {
    HeapFree(GetProcessHeap(), 0, абсолютний_шлях);
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  HeapFree(GetProcessHeap(), 0, широкий_шлях);

  // Calculate string lengths
  природне довжина_поточної = 0;
  while (поточна_тека[довжина_поточної] != L'\0') {
    довжина_поточної++;
  }

  природне довжина_абсолютного = 0;
  while (абсолютний_шлях[довжина_абсолютного] != L'\0') {
    довжина_абсолютного++;
  }

  // Find common prefix (comparing case-insensitively for Windows)
  природне спільна_довжина = 0;
  for (природне і = 0; і < довжина_поточної && і < довжина_абсолютного; і++) {
    WCHAR с1 = поточна_тека[і];
    WCHAR с2 = абсолютний_шлях[і];

    // Convert to lowercase for comparison
    if (с1 >= L'A' && с1 <= L'Z')
      с1 += 32;
    if (с2 >= L'A' && с2 <= L'Z')
      с2 += 32;

    // Also treat both / and \ as equivalent
    if ((с1 == L'\\') && (с2 == L'\\')) {
      спільна_довжина = і + 1;
    } else if (с1 == с2) {
      if (с1 == L'\\') {
        спільна_довжина = і + 1;
      }
    } else {
      break;
    }
  }

  // Count how many directories we need to go up
  природне рівнів_вгору = 0;
  for (природне і = спільна_довжина; і < довжина_поточної; і++) {
    if (поточна_тека[і] == L'\\') {
      рівнів_вгору++;
    }
  }
  if (спільна_довжина < довжина_поточної &&
      поточна_тека[довжина_поточної - 1] != L'\\') {
    рівнів_вгору++;
  }

  // Build relative path
  природне розмір_відносного = рівнів_вгору * 3; // "../" for each level up
  if (довжина_абсолютного > спільна_довжина) {
    розмір_відносного += довжина_абсолютного - спільна_довжина;
  } else {
    розмір_відносного = 1; // Just "."
  }

  WCHAR* відносний_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (розмір_відносного + 1) * sizeof(WCHAR));
  if (!відносний_шлях) {
    HeapFree(GetProcessHeap(), 0, абсолютний_шлях);
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    return FALSE;
  }

  природне позиція = 0;

  // Add "..\" for each level up
  for (природне і = 0; і < рівнів_вгору; і++) {
    відносний_шлях[позиція++] = L'.';
    відносний_шлях[позиція++] = L'.';
    відносний_шлях[позиція++] = L'\\';
  }

  // Add remaining path
  if (довжина_абсолютного > спільна_довжина) {
    for (природне і = спільна_довжина; і < довжина_абсолютного; і++) {
      відносний_шлях[позиція++] = абсолютний_шлях[і];
    }
  } else if (позиція == 0) {
    відносний_шлях[позиція++] = L'.';
  } else if (позиція > 0 && відносний_шлях[позиція - 1] == L'\\') {
    позиція--; // Remove trailing slash
  }

  відносний_шлях[позиція] = L'\0';

  // Convert back to UTF-8
  int байтів_ю8 = WideCharToMultiByte(CP_UTF8, 0, відносний_шлях, позиція, NULL,
                                      0, NULL, NULL);
  if (байтів_ю8 == 0) {
    HeapFree(GetProcessHeap(), 0, відносний_шлях);
    HeapFree(GetProcessHeap(), 0, абсолютний_шлях);
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    return FALSE;
  }

  *вихід_розміру = байтів_ю8;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    HeapFree(GetProcessHeap(), 0, відносний_шлях);
    HeapFree(GetProcessHeap(), 0, абсолютний_шлях);
    HeapFree(GetProcessHeap(), 0, поточна_тека);
    return FALSE;
  }

  WideCharToMultiByte(CP_UTF8, 0, відносний_шлях, позиція, (char*)*вихід_даних,
                      байтів_ю8, NULL, NULL);

  HeapFree(GetProcessHeap(), 0, відносний_шлях);
  HeapFree(GetProcessHeap(), 0, абсолютний_шлях);
  HeapFree(GetProcessHeap(), 0, поточна_тека);
  return TRUE;
}

extern логічне пристрій_мавки_перевірити_чи_шлях_починається_на(
    природне розмір_шляху,
    п8* дані_шляху,
    природне розмір_початку,
    п8* дані_початку) {
  if (розмір_початку > розмір_шляху) {
    return FALSE;
  }

  for (природне і = 0; і < розмір_початку; і++) {
    if (дані_шляху[і] != дані_початку[і]) {
      return FALSE;
    }
  }

  return TRUE;
}

extern логічне пристрій_мавки_отримати_шлях_до_паку_з_шляху_теки_модулів(
    природне розмір_шляху,
    п8* дані_шляху,
    природне розмір_шляху_до_паків,
    п8* дані_шляху_до_паків,
    природне* вихід_розміру,
    п8** вихід_даних) {
  // Check if the module path starts with the packages path
  if (розмір_шляху <= розмір_шляху_до_паків) {
    return FALSE;
  }

  // Verify that the module path starts with the packages path
  for (природне і = 0; і < розмір_шляху_до_паків; і++) {
    if (дані_шляху[і] != дані_шляху_до_паків[і]) {
      return FALSE;
    }
  }

  // Find the next '\\' after the packages path to get the package directory
  природне позиція_наступного_слешу = 0;
  логічне знайдено = FALSE;

  // Skip the packages path and any immediate '\\'
  природне початок = розмір_шляху_до_паків;
  if (початок < розмір_шляху && дані_шляху[початок] == '\\') {
    початок++;
  }

  // Find the next '\\' which marks the end of the package name
  for (природне і = початок; і < розмір_шляху; і++) {
    if (дані_шляху[і] == '\\') {
      позиція_наступного_слешу = і; // Don't include the trailing slash
      знайдено = TRUE;
      break;
    }
  }

  if (!знайдено) {
    позиція_наступного_слешу = розмір_шляху;
  }

  // Return the path up to but not including the trailing slash
  *вихід_розміру = позиція_наступного_слешу;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    return FALSE;
  }

  for (природне і = 0; і < позиція_наступного_слешу; і++) {
    (*вихід_даних)[і] = дані_шляху[і];
  }

  return TRUE;
}

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

extern логічне пристрій_мавки_читати_кд(природне розмір_перед,
                                        п8* дані_перед,
                                        природне* вихід_розміру,
                                        п8** вихід_даних,
                                        природне дозволити_історію,
                                        природне* кінець_файлу) {
  пристрій_мавки_вивести_кд(розмір_перед, дані_перед);

  size_t len;
  char* data = read_line_no_newline(&len);

  if (!data) {
    *кінець_файлу = TRUE;

    return TRUE;
  }

  *кінець_файлу = FALSE;

  логічне успіх = пристрій_мавки_перекодувати_ю8_в_кд(
      (природне)len, (п8*)data, вихід_розміру, вихід_даних, NULL);

  return успіх;
}

extern логічне пристрій_мавки_отримати_поточний_шлях_процесу(
    природне* вихід_розміру,
    п8** вихід_даних) {
  // Get required buffer size for current directory (in wide chars)
  DWORD розмір = GetCurrentDirectoryW(0, NULL);
  if (розмір == 0) {
    return FALSE;
  }

  // Allocate buffer for wide char path
  WCHAR* широкий_шлях =
      (WCHAR*)HeapAlloc(GetProcessHeap(), 0, розмір * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  // Get current directory as wide char
  if (GetCurrentDirectoryW(розмір, широкий_шлях) == 0) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  // Convert UTF-16 to UTF-8
  int байтів_ю8 =
      WideCharToMultiByte(CP_UTF8, 0, широкий_шлях, -1, NULL, 0, NULL, NULL);
  if (байтів_ю8 == 0) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  // Allocate buffer for UTF-8 (excluding null terminator)
  *вихід_розміру = байтів_ю8 - 1;
  *вихід_даних = (п8*)HeapAlloc(GetProcessHeap(), 0, *вихід_розміру);
  if (!*вихід_даних) {
    HeapFree(GetProcessHeap(), 0, широкий_шлях);
    return FALSE;
  }

  // Convert to UTF-8
  WideCharToMultiByte(CP_UTF8, 0, широкий_шлях, -1, (char*)*вихід_даних,
                      байтів_ю8, NULL, NULL);

  HeapFree(GetProcessHeap(), 0, широкий_шлях);
  return TRUE;
}