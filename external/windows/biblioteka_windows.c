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

логічне бібліотека_мавки_видалити(п8* дані_шляху, природне розмір_шляху) {
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
          if (!бібліотека_мавки_видалити((п8*)утф8_шлях, strlen(утф8_шлях))) {
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

логічне бібліотека_мавки_прочитати_файл(п8* дані_шляху,
                                        природне розмір_шляху,
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

логічне бібліотека_мавки_створити_папку(п8* дані_шляху, природне розмір_шляху) {
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
    if (атрибути_фіналь == INVALID_FILE_ATTRIBUTES ||
        !(атрибути_фіналь & FILE_ATTRIBUTE_DIRECTORY)) {
      free(копія_шляху);
      free(широкий_шлях);
      return FALSE;
    }
  }

  free(копія_шляху);
  free(широкий_шлях);
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

  WCHAR* wide = (WCHAR*)malloc(count * sizeof(WCHAR));
  if (!wide) {
    return NULL;
  }

  if (MultiByteToWideChar(CP_UTF8, 0, (const char*)utf8, -1, wide, count) ==
      0) {
    free(wide);
    return NULL;
  }

  return wide;
}

static WCHAR* utf8_to_wide_sized(const п8* utf8, природне size) {
  if (!utf8 || size == 0) {
    return NULL;
  }

  int count =
      MultiByteToWideChar(CP_UTF8, 0, (const char*)utf8, (int)size, NULL, 0);
  if (count == 0) {
    return NULL;
  }

  WCHAR* wide = (WCHAR*)malloc((count + 1) * sizeof(WCHAR));
  if (!wide) {
    return NULL;
  }

  if (MultiByteToWideChar(CP_UTF8, 0, (const char*)utf8, (int)size, wide,
                          count + 1) == 0) {
    free(wide);
    return NULL;
  }

  wide[count] = L'\0';
  return wide;
}

static логічне append_to_data(Дані* output, const void* data, size_t size) {
  if (size == 0) {
    return TRUE;
  }

  п8* next = (п8*)realloc(output->дані, output->розмір + size);
  if (!next) {
    return FALSE;
  }

  memcpy(next + output->розмір, data, size);
  output->дані = next;
  output->розмір += size;
  return TRUE;
}

static BOOL read_pipe(HANDLE handle, Дані* output) {
  BYTE buffer[4096];

  while (TRUE) {
    DWORD bytes_read = 0;
    if (!ReadFile(handle, buffer, sizeof(buffer), &bytes_read, NULL)) {
      DWORD error = GetLastError();
      if (error == ERROR_BROKEN_PIPE) {
        return TRUE;
      }
      return FALSE;
    }
    if (bytes_read == 0) {
      return TRUE;
    }
    if (!append_to_data(output, buffer, (size_t)bytes_read)) {
      return FALSE;
    }
  }
}

static size_t quote_cmd_argument_length(const WCHAR* arg) {
  const WCHAR* p = arg;
  size_t length = 0;
  логічне needs_quotes = FALSE;

  while (*p) {
    if (*p == L' ' || *p == L'\t' || *p == L'"') {
      needs_quotes = TRUE;
    }
    if (*p == L'"') {
      length += 2;
    } else {
      length += 1;
    }
    p++;
  }

  if (needs_quotes) {
    length += 2;
  }

  return length;
}

static void append_quoted_cmd_argument(WCHAR** dest, const WCHAR* arg) {
  const WCHAR* p = arg;
  логічне needs_quotes = FALSE;

  while (*p) {
    if (*p == L' ' || *p == L'\t' || *p == L'"') {
      needs_quotes = TRUE;
      break;
    }
    p++;
  }

  if (needs_quotes) {
    **dest = L'"';
    *dest += 1;
  }

  p = arg;
  while (*p) {
    if (*p == L'"') {
      **dest = L'\\';
      *dest += 1;
      **dest = L'"';
      *dest += 1;
    } else {
      **dest = *p;
      *dest += 1;
    }
    p++;
  }

  if (needs_quotes) {
    **dest = L'"';
    *dest += 1;
  }
}

void бібліотека_мавки_виконати(п8* дані,
                               природне розмір,
                               РезультатВиконання* результат_виконання) {
  if (!результат_виконання) {
    return;
  }

  результат_виконання->стдвив.розмір = 0;
  результат_виконання->стдвив.дані = NULL;
  результат_виконання->стдпом.розмір = 0;
  результат_виконання->стдпом.дані = NULL;
  результат_виконання->код = -1;

  if (розмір == 0 || !дані) {
    return;
  }

  WCHAR* wide_command = utf8_to_wide_sized(дані, розмір);
  if (!wide_command) {
    return;
  }

  size_t prefix_len = wcslen(L"cmd.exe /c ");
  size_t command_len = wcslen(wide_command);
  WCHAR* command_line =
      (WCHAR*)malloc((prefix_len + command_len + 1) * sizeof(WCHAR));
  if (!command_line) {
    free(wide_command);
    return;
  }

  wcscpy_s(command_line, prefix_len + command_len + 1, L"cmd.exe /c ");
  wcscat_s(command_line, prefix_len + command_len + 1, wide_command);

  SECURITY_ATTRIBUTES sa = {sizeof(sa), NULL, TRUE};
  HANDLE stdout_read = NULL;
  HANDLE stdout_write = NULL;
  HANDLE stderr_read = NULL;
  HANDLE stderr_write = NULL;

  if (!CreatePipe(&stdout_read, &stdout_write, &sa, 0) ||
      !CreatePipe(&stderr_read, &stderr_write, &sa, 0)) {
    free(command_line);
    free(wide_command);
    return;
  }

  SetHandleInformation(stdout_read, HANDLE_FLAG_INHERIT, 0);
  SetHandleInformation(stderr_read, HANDLE_FLAG_INHERIT, 0);

  STARTUPINFOW si = {0};
  si.cb = sizeof(si);
  si.dwFlags = STARTF_USESTDHANDLES;
  si.hStdOutput = stdout_write;
  si.hStdError = stderr_write;
  si.hStdInput = CreateFileW(L"NUL", GENERIC_READ, FILE_SHARE_READ, &sa,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  PROCESS_INFORMATION pi = {0};

  if (!CreateProcessW(NULL, command_line, NULL, NULL, TRUE, CREATE_NO_WINDOW,
                      NULL, NULL, &si, &pi)) {
    if (si.hStdInput != INVALID_HANDLE_VALUE) {
      CloseHandle(si.hStdInput);
    }
    if (stdout_read) {
      CloseHandle(stdout_read);
    }
    if (stdout_write) {
      CloseHandle(stdout_write);
    }
    if (stderr_read) {
      CloseHandle(stderr_read);
    }
    if (stderr_write) {
      CloseHandle(stderr_write);
    }
    free(command_line);
    free(wide_command);
    return;
  }

  CloseHandle(stdout_write);
  stdout_write = NULL;
  CloseHandle(stderr_write);
  stderr_write = NULL;
  if (si.hStdInput != INVALID_HANDLE_VALUE) {
    CloseHandle(si.hStdInput);
  }

  read_pipe(stdout_read, &результат_виконання->стдвив);
  read_pipe(stderr_read, &результат_виконання->стдпом);

  WaitForSingleObject(pi.hProcess, INFINITE);
  DWORD exit_code = 0;
  if (GetExitCodeProcess(pi.hProcess, &exit_code)) {
    результат_виконання->код = (ц32)exit_code;
  }

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  if (stdout_read) {
    CloseHandle(stdout_read);
  }
  if (stderr_read) {
    CloseHandle(stderr_read);
  }

  free(command_line);
  free(wide_command);
}

void бібліотека_мавки_виконати_аргументи(
    природне кількість_аргументів,
    ю8* аргументи,
    РезультатВиконання* результат_виконання) {
  if (!результат_виконання) {
    return;
  }

  результат_виконання->стдвив.розмір = 0;
  результат_виконання->стдвив.дані = NULL;
  результат_виконання->стдпом.розмір = 0;
  результат_виконання->стдпом.дані = NULL;
  результат_виконання->код = -1;

  if (кількість_аргументів == 0 || !аргументи) {
    return;
  }

  // Convert all args to wide
  WCHAR** wide_args = (WCHAR**)malloc(кількість_аргументів * sizeof(WCHAR*));
  if (!wide_args) {
    return;
  }

  for (природне i = 0; i < кількість_аргументів; ++i) {
    wide_args[i] = utf8_to_wide_sized(аргументи[i].дані, аргументи[i].розмір);
    if (!wide_args[i]) {
      for (природне j = 0; j < i; ++j) {
        free(wide_args[j]);
      }
      free(wide_args);
      return;
    }
  }

  // Always use cmd.exe /c for maximum compatibility
  size_t cmd_prefix_len = wcslen(L"cmd.exe /c ");
  size_t total_len = cmd_prefix_len;

  for (природне i = 0; i < кількість_аргументів; ++i) {
    total_len += quote_cmd_argument_length(wide_args[i]);
    if (i + 1 < кількість_аргументів) {
      total_len += 1; // space
    }
  }
  total_len += 1; // null terminator

  WCHAR* command_line = (WCHAR*)malloc(total_len * sizeof(WCHAR));
  if (!command_line) {
    for (природне i = 0; i < кількість_аргументів; ++i) {
      free(wide_args[i]);
    }
    free(wide_args);
    return;
  }

  wcscpy_s(command_line, total_len, L"cmd.exe /c ");
  WCHAR* dest = command_line + cmd_prefix_len;
  for (природне i = 0; i < кількість_аргументів; ++i) {
    append_quoted_cmd_argument(&dest, wide_args[i]);
    if (i + 1 < кількість_аргументів) {
      *dest++ = L' ';
    }
  }
  *dest = L'\0';

  // Create pipes with security attributes for inheritance
  SECURITY_ATTRIBUTES sa = {sizeof(sa), NULL, TRUE};
  HANDLE stdout_read = NULL;
  HANDLE stdout_write = NULL;
  HANDLE stderr_read = NULL;
  HANDLE stderr_write = NULL;

  if (!CreatePipe(&stdout_read, &stdout_write, &sa, 0) ||
      !CreatePipe(&stderr_read, &stderr_write, &sa, 0)) {
    goto cleanup_command;
  }

  // Make read ends non-inheritable
  SetHandleInformation(stdout_read, HANDLE_FLAG_INHERIT, 0);
  SetHandleInformation(stderr_read, HANDLE_FLAG_INHERIT, 0);

  // Setup process
  STARTUPINFOW si = {0};
  si.cb = sizeof(si);
  si.dwFlags = STARTF_USESTDHANDLES;
  si.hStdOutput = stdout_write;
  si.hStdError = stderr_write;
  si.hStdInput = CreateFileW(L"NUL", GENERIC_READ, FILE_SHARE_READ, &sa,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  PROCESS_INFORMATION pi = {0};

  if (!CreateProcessW(NULL, command_line, NULL, NULL, TRUE, CREATE_NO_WINDOW,
                      NULL, NULL, &si, &pi)) {
    if (si.hStdInput != INVALID_HANDLE_VALUE) {
      CloseHandle(si.hStdInput);
    }
    goto cleanup_pipes;
  }

  // Close write ends in parent
  CloseHandle(stdout_write);
  stdout_write = NULL;
  CloseHandle(stderr_write);
  stderr_write = NULL;
  if (si.hStdInput != INVALID_HANDLE_VALUE) {
    CloseHandle(si.hStdInput);
  }

  // Read from child's output
  read_pipe(stdout_read, &результат_виконання->стдвив);
  read_pipe(stderr_read, &результат_виконання->стдпом);

  // Wait and get exit code
  WaitForSingleObject(pi.hProcess, INFINITE);
  DWORD exit_code = 0;
  if (GetExitCodeProcess(pi.hProcess, &exit_code)) {
    результат_виконання->код = (ц32)exit_code;
  }

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

cleanup_pipes:
  if (stdout_read) {
    CloseHandle(stdout_read);
  }
  if (stdout_write) {
    CloseHandle(stdout_write);
  }
  if (stderr_read) {
    CloseHandle(stderr_read);
  }
  if (stderr_write) {
    CloseHandle(stderr_write);
  }

cleanup_command:
  free(command_line);
  for (природне i = 0; i < кількість_аргументів; ++i) {
    free(wide_args[i]);
  }
  free(wide_args);
}
