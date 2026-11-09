#include <math.h>
#include <stdio.h>
#include <windows.h>

#include "../include/mavka/prystriy.h"

static void out_utf8_data(char* дані, size_t розмір);
static void out_utf8_string(char* дані);
static void print_color(PristriyMavkyWriteToStdoutColor значення);
static char* do_readline(char* prefix, size_t prefix_size, size_t* out_len);

// ----------------------------

void* pristriy_mavky_malloc(size_t size) {
  return (void*)HeapAlloc(GetProcessHeap(), 0, size);
}

void* pristriy_mavky_realloc(void* value, size_t new_size) {
  if (value == NULL) {
    return (void*)HeapAlloc(GetProcessHeap(), 0, new_size);
  }
  return (void*)HeapReAlloc(GetProcessHeap(), 0, value, new_size);
}

void pristriy_mavky_free(void* value) {
  if (value != NULL) {
    HeapFree(GetProcessHeap(), 0, value);
  }
}

void pristriy_mavky_write_to_stdout(char* data, size_t size) {
  HANDLE консоль = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD записано;

  WriteFile(консоль, data, (DWORD)size, &записано, NULL);
}

void pristriy_mavky_write_utf8_to_stdout(PristriyMavkyWriteToStdoutColor color,
                                         char* data,
                                         size_t size) {
  print_color(color);

  out_utf8_data(data, size);

  print_color(PristriyMavkyColorReset);
}

double pristriy_mavky_double_pow(double value, double exp) {
  return pow(value, exp);
}
double pristriy_mavky_double_sin(double value) {
  return sin(value);
}
double pristriy_mavky_double_cos(double value) {
  return cos(value);
}
double pristriy_mavky_double_tan(double value) {
  return tan(value);
}
double pristriy_mavky_double_asin(double value) {
  return asin(value);
}
double pristriy_mavky_double_acos(double value) {
  return acos(value);
}
double pristriy_mavky_double_atan(double value) {
  return atan(value);
}
double pristriy_mavky_double_abs(double value) {
  return fabs(value);
}
double pristriy_mavky_double_exp(double value) {
  return exp(value);
}
double pristriy_mavky_double_sqrt2(double value) {
  return sqrt(value);
}
double pristriy_mavky_double_ceil(double value) {
  return ceil(value);
}
double pristriy_mavky_double_floor(double value) {
  return floor(value);
}
double pristriy_mavky_double_round(double value) {
  return round(value);
}

bool pristriy_mavky_uint64_to_str(size_t value,
                                  char** data_out,
                                  size_t* size_out) {
  char buf[32];
  int len = wsprintfA(buf, "%I64u", value);
  if (len <= 0) {
    return FALSE;
  }
  *size_out = (size_t)len;
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    return FALSE;
  }
  for (size_t і = 0; і < *size_out; і++) {
    (*data_out)[і] = buf[і];
  }
  return TRUE;
}

bool pristriy_mavky_int64_to_str(ssize_t value,
                                 char** data_out,
                                 size_t* size_out) {
  char buf[32];
  int len = wsprintfA(buf, "%I64d", value);
  if (len <= 0) {
    return FALSE;
  }
  *size_out = (size_t)len;
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    return FALSE;
  }
  for (size_t і = 0; і < *size_out; і++) {
    (*data_out)[і] = buf[і];
  }
  return TRUE;
}

bool pristriy_mavky_double_to_str(double value,
                                  char** data_out,
                                  size_t* size_out,
                                  ssize_t* exp_size_out) {
  char buf[64];
  int len;

  // Check for NaN
  if (value != value) { // NaN != NaN
    char nan_str[] = "невизначеність";
    *size_out = sizeof(nan_str) - 1;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return FALSE;
    for (size_t і = 0; і < *size_out; і++) {
      (*data_out)[і] = nan_str[і];
    }
    *exp_size_out = 0;
    return TRUE;
  }

  // Check for infinity
  if (value > 1e308 || value < -1e308) {
    char* inf_str = value > 0 ? "нескінченність" : "-нескінченність";
    *size_out = value > 0 ? sizeof("нескінченність") - 1
                          : sizeof("-нескінченність") - 1;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return FALSE;
    for (size_t і = 0; і < *size_out; і++) {
      (*data_out)[і] = inf_str[і];
    }
    *exp_size_out = 0;
    return TRUE;
  }

  len = sprintf(buf, "%.17g", value);
  if (len < 0 || len >= (int)sizeof(buf)) {
    return FALSE;
  }

  // Знаходимо найкоротше представлення, яке round-trips
  // Пробуємо від 15 до 17 цифр точності
  for (int precision = 15; precision <= 17; precision++) {
    len = sprintf(buf, "%.*g", precision, value);
    if (len < 0 || len >= (int)sizeof(buf)) {
      continue;
    }

    // Перевіряємо чи round-trip працює
    double parsed = strtod(buf, NULL);
    if (parsed == value) {
      break;
    }
  }

  if (len < 0 || len >= (int)sizeof(buf)) {
    return FALSE;
  }

  // Find 'e' for exponential notation
  char* e_pos = NULL;
  for (int і = 0; і < len; і++) {
    if (buf[і] == 'e') {
      e_pos = &buf[і];
      break;
    }
  }

  if (e_pos != NULL) {
    // Parse exponent
    *exp_size_out = 0;
    ssize_t знак_експоненти = 1;
    char* p = e_pos + 1;
    if (*p == '+') {
      p++;
    } else if (*p == '-') {
      знак_експоненти = -1;
      p++;
    }
    while (*p >= '0' && *p <= '9') {
      *exp_size_out = *exp_size_out * 10 + (*p - '0');
      p++;
    }
    *exp_size_out *= знак_експоненти;

    size_t довжина_мантиси = (size_t)(e_pos - buf);

    *size_out = довжина_мантиси;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return FALSE;

    for (size_t і = 0; і < довжина_мантиси; і++) {
      (*data_out)[і] = buf[і];
    }
  } else {
    *exp_size_out = 0;

    *size_out = (size_t)len;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return FALSE;

    for (size_t і = 0; і < *size_out; і++) {
      (*data_out)[і] = buf[і];
    }
  }

  return TRUE;
}

bool pristriy_mavky_str_to_double(char* data, size_t size, double* out) {
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)data, size, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_рядок =
      (WCHAR*)pristriy_mavky_malloc((широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_рядок) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)data, size, широкий_рядок,
                      широких_символів);
  широкий_рядок[широких_символів] = L'\0';

  for (int i = 0; i < широких_символів; i++) {
    if (широкий_рядок[i] == L'е') {
      широкий_рядок[i] = L'e';
    } else if (широкий_рядок[i] == L'Е') {
      широкий_рядок[i] = L'E';
    }
  }

  WCHAR* endptr;
  *out = wcstod(широкий_рядок, &endptr);

  if (широкий_рядок == endptr) {
    pristriy_mavky_free(широкий_рядок);
    return FALSE;
  } else if (errno == ERANGE) {
    pristriy_mavky_free(широкий_рядок);
    return FALSE;
  } else if (*endptr != L'\0') {
    pristriy_mavky_free(широкий_рядок);
    return FALSE;
  }

  pristriy_mavky_free(широкий_рядок);
  return TRUE;
}

bool pristriy_mavky_get_cwd(char** data_out, size_t* size_out) {
  DWORD розмір = GetCurrentDirectoryW(0, NULL);
  if (розмір == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)pristriy_mavky_malloc(розмір * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  if (GetCurrentDirectoryW(розмір, широкий_шлях) == 0) {
    pristriy_mavky_free(широкий_шлях);
    return FALSE;
  }

  int довжина_шляху = wcslen(широкий_шлях);
  int байтів_ю8 = WideCharToMultiByte(CP_UTF8, 0, широкий_шлях, довжина_шляху,
                                      NULL, 0, NULL, NULL);
  if (байтів_ю8 == 0) {
    pristriy_mavky_free(широкий_шлях);
    return FALSE;
  }

  *size_out = байтів_ю8;
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    pristriy_mavky_free(широкий_шлях);
    return FALSE;
  }

  WideCharToMultiByte(CP_UTF8, 0, широкий_шлях, довжина_шляху, (char*)*data_out,
                      байтів_ю8, NULL, NULL);

  pristriy_mavky_free(широкий_шлях);
  return TRUE;
}

bool pristriy_mavky_get_absolute_path(char* path_data,
                                      size_t path_size,
                                      char** data_out,
                                      size_t* size_out) {
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)path_data, path_size, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)path_data, path_size, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  DWORD потрібно = GetFullPathNameW(широкий_шлях, 0, NULL, NULL);
  if (потрібно == 0) {
    pristriy_mavky_free(широкий_шлях);
    return FALSE;
  }

  WCHAR* абсолютний_широкий =
      (WCHAR*)pristriy_mavky_malloc(потрібно * sizeof(WCHAR));
  if (!абсолютний_широкий) {
    pristriy_mavky_free(широкий_шлях);
    return FALSE;
  }

  if (GetFullPathNameW(широкий_шлях, потрібно, абсолютний_широкий, NULL) == 0) {
    pristriy_mavky_free(абсолютний_широкий);
    pristriy_mavky_free(широкий_шлях);
    return FALSE;
  }

  pristriy_mavky_free(широкий_шлях);

  // Get exact size of string excluding null terminator by passing explicit length
  int довжина_абсолютного = wcslen(абсолютний_широкий);
  int байтів_ю8 = WideCharToMultiByte(CP_UTF8, 0, абсолютний_широкий,
                                      довжина_абсолютного, NULL, 0, NULL, NULL);
  if (байтів_ю8 == 0) {
    pristriy_mavky_free(абсолютний_широкий);
    return FALSE;
  }

  *size_out = байтів_ю8;
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    pristriy_mavky_free(абсолютний_широкий);
    return FALSE;
  }

  // Pass exact size, no null-terminator is written to the allocated buffer
  WideCharToMultiByte(CP_UTF8, 0, абсолютний_широкий, довжина_абсолютного,
                      (char*)*data_out, байтів_ю8, NULL, NULL);

  pristriy_mavky_free(абсолютний_широкий);
  return TRUE;
}

bool pristriy_mavky_check_if_file_exists(char* path_data, size_t path_size) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)path_data, path_size, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)path_data, path_size, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Get file attributes using Windows API
  DWORD атрибути = GetFileAttributesW(широкий_шлях);
  pristriy_mavky_free(широкий_шлях);

  if (атрибути == INVALID_FILE_ATTRIBUTES) {
    return FALSE;
  }

  // Check if it's a regular file (not a directory)
  return (атрибути & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

bool pristriy_mavky_read_file(char* path_data,
                              size_t path_size,
                              char** data_out,
                              size_t* size_out) {
  // Convert UTF-8 path to wide char
  int широких_символів =
      MultiByteToWideChar(CP_UTF8, 0, (char*)path_data, path_size, NULL, 0);
  if (широких_символів == 0) {
    return FALSE;
  }

  WCHAR* широкий_шлях = (WCHAR*)HeapAlloc(
      GetProcessHeap(), 0, (широких_символів + 1) * sizeof(WCHAR));
  if (!широкий_шлях) {
    return FALSE;
  }

  MultiByteToWideChar(CP_UTF8, 0, (char*)path_data, path_size, широкий_шлях,
                      широких_символів);
  широкий_шлях[широких_символів] = L'\0';

  // Open file using Windows API
  HANDLE файл = CreateFileW(широкий_шлях, GENERIC_READ, FILE_SHARE_READ, NULL,
                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  pristriy_mavky_free(широкий_шлях);

  if (файл == INVALID_HANDLE_VALUE) {
    return FALSE;
  }

  // Get file size
  LARGE_INTEGER розмір_файлу;
  if (!GetFileSizeEx(файл, &розмір_файлу)) {
    CloseHandle(файл);
    return FALSE;
  }

  *size_out = (size_t)розмір_файлу.QuadPart;

  // Allocate buffer
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    CloseHandle(файл);
    return FALSE;
  }

  // Read file
  DWORD прочитано;
  if (!ReadFile(файл, *data_out, *size_out, &прочитано, NULL)) {
    pristriy_mavky_free(*data_out);
    CloseHandle(файл);
    return FALSE;
  }

  CloseHandle(файл);
  return TRUE;
}

bool pristriy_mavky_read_input_async(
    char* prefix_data,
    size_t prefix_size,
    void (*callback)(char* data, size_t data_size, bool eof, void* arg),
    void* arg,
    bool allow_history) {
  size_t len;
  char* data = do_readline(prefix_data, prefix_size, &len);

  if (!data) {
    callback(data, len, TRUE, arg);

    return TRUE;
  }

  callback(data, len, FALSE, arg);

  return TRUE;
}

void* pristriy_mavky_dlopen(char* path_data, size_t path_size, int* err_out) {
  *err_out = 0;

  if (!path_data || path_size == 0) {
    *err_out = -1;
    return NULL;
  }

  /* path_data may or may not be NUL-terminated within path_size bytes. */
  size_t len = strnlen(path_data, path_size);

  /* UTF-8 -> UTF-16, two-step (measure, then convert). */
  int wlen = MultiByteToWideChar(CP_UTF8, 0, path_data, (int)len, NULL, 0);
  if (wlen <= 0) {
    *err_out = -1;
    return NULL;
  }

  wchar_t* wpath =
      (wchar_t*)malloc((size_t)wlen * sizeof(wchar_t) + sizeof(wchar_t));
  if (!wpath) {
    *err_out = -1;
    return NULL;
  }

  int written =
      MultiByteToWideChar(CP_UTF8, 0, path_data, (int)len, wpath, wlen);
  if (written <= 0) {
    free(wpath);
    *err_out = -1;
    return NULL;
  }
  wpath[written] = L'\0';

  HMODULE dl = LoadLibraryW(wpath);
  free(wpath);

  if (!dl) {
    *err_out = -1;
    return NULL;
  }

  return (void*)dl;
}

void* pristriy_mavky_dlsym(void* dl,
                           char* name_data,
                           size_t name_size,
                           int* err_out) {
  *err_out = 0;

  if (!dl || !name_data || name_size == 0) {
    *err_out = -1;
    return NULL;
  }

  /* PE export names are ASCII by spec, so valid UTF-8 (i.e. pure ASCII)
     names work directly with GetProcAddress (LPCSTR). We only need to
     guarantee NUL-termination, since name_size implies the buffer may
     not be NUL-terminated. */
  size_t len = strnlen(name_data, name_size);

  FARPROC dls;
  if (len < name_size && name_data[len] == '\0') {
    /* Already NUL-terminated. */
    dls = GetProcAddress((HMODULE)dl, name_data);
  } else {
    char* tmp = (char*)malloc(len + 1);
    if (!tmp) {
      *err_out = -1;
      return NULL;
    }
    memcpy(tmp, name_data, len);
    tmp[len] = '\0';
    dls = GetProcAddress((HMODULE)dl, tmp);
    free(tmp);
  }

  if (!dls) {
    *err_out = -1;
    return NULL;
  }

  return (void*)dls;
}

int pristriy_mavky_dlclose(void* dl) {
  BOOL result = FreeLibrary((HMODULE)dl);
  return result ? 0 : -1;
}

void pristriy_mavky_exit(int code) {
  ExitProcess((UINT)code);
}

// ----------------------------

static void out_utf8_data(char* дані, size_t розмір) {
  if (розмір == 0) {
    return;
  }

  HANDLE консоль = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD режим;
  DWORD записано;

  // Check if the output is a real console
  if (GetConsoleMode(консоль, &режим)) {
    // It's a console. Convert to UTF-16 and use WriteConsoleW
    int широких_символів =
        MultiByteToWideChar(CP_UTF8, 0, (char*)дані, розмір, NULL, 0);
    if (широких_символів == 0) {
      return;
    }

    WCHAR* широкий_буфер =
        (WCHAR*)pristriy_mavky_malloc(широких_символів * sizeof(WCHAR));
    if (!широкий_буфер) {
      return;
    }

    MultiByteToWideChar(CP_UTF8, 0, (char*)дані, розмір, широкий_буфер,
                        широких_символів);

    WriteConsoleW(консоль, широкий_буфер, широких_символів, &записано, NULL);

    pristriy_mavky_free(широкий_буфер);
  } else {
    // It's a pipe or file (e.g. CI pipeline). Write the original UTF-8 bytes directly.
    WriteFile(консоль, дані, (DWORD)розмір, &записано, NULL);
  }
}

static void out_utf8_string(char* дані) {
  if (!дані) {
    return;
  }

  // Calculate string length
  size_t довжина = 0;
  while (дані[довжина] != '\0') {
    довжина++;
  }

  out_utf8_data((char*)дані, довжина);
}

static void print_color(PristriyMavkyWriteToStdoutColor значення) {
  HANDLE консоль = GetStdHandle(STD_OUTPUT_HANDLE);

  // Enable virtual terminal processing for ANSI color support
  DWORD режим;
  if (GetConsoleMode(консоль, &режим)) {
    SetConsoleMode(консоль, режим | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  }

  WORD атрибути;
  switch (значення) {
    case PristriyMavkyColorReset:
      атрибути = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
    case PristriyMavkyColorRed:
      атрибути = FOREGROUND_RED | FOREGROUND_INTENSITY;
      break;
    case PristriyMavkyColorGreen:
      атрибути = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
      break;
    case PristriyMavkyColorBlue:
      атрибути = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
      break;
    case PristriyMavkyColorYellow:
      атрибути = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
      break;
    default:
      атрибути = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
  }

  SetConsoleTextAttribute(консоль, атрибути);
}

static char* do_readline(char* prefix, size_t prefix_size, size_t* out_len) {
  pristriy_mavky_write_utf8_to_stdout(PristriyMavkyColorReset, prefix,
                                      prefix_size);

  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
  if (hStdin == INVALID_HANDLE_VALUE) {
    return NULL;
  }

  DWORD режим;
  int is_console = GetConsoleMode(hStdin, &режим);

  size_t wide_cap = 128;
  size_t wide_len = 0;
  WCHAR* wide_buf = (WCHAR*)pristriy_mavky_malloc(wide_cap * sizeof(WCHAR));
  if (!wide_buf)
    return NULL;

  if (is_console) {
    // Real console: read UTF-16
    WCHAR wc;
    DWORD charsRead;

    while (ReadConsoleW(hStdin, &wc, 1, &charsRead, NULL) && charsRead == 1) {
      if (wc == L'\n')
        break;
      if (wc == L'\r')
        continue;

      if (wide_len + 1 >= wide_cap) {
        wide_cap *= 2;
        WCHAR* tmp =
            (WCHAR*)pristriy_mavky_realloc(wide_buf, wide_cap * sizeof(WCHAR));
        if (!tmp) {
          pristriy_mavky_free(wide_buf);
          return NULL;
        }
        wide_buf = tmp;
      }

      wide_buf[wide_len++] = wc;
    }
  } else {
    // Pipe or file: read UTF-8 bytes, then convert to UTF-16
    char c;
    DWORD charsRead;
    size_t utf8_cap = 128;
    size_t utf8_len = 0;
    char* utf8_buf = (char*)pristriy_mavky_malloc(utf8_cap);
    if (!utf8_buf) {
      pristriy_mavky_free(wide_buf);
      return NULL;
    }

    while (ReadFile(hStdin, &c, 1, &charsRead, NULL) && charsRead == 1) {
      if (c == '\n')
        break;
      if (c == '\r')
        continue;

      if (utf8_len + 1 >= utf8_cap) {
        utf8_cap *= 2;
        char* tmp = (char*)pristriy_mavky_realloc(utf8_buf, utf8_cap);
        if (!tmp) {
          pristriy_mavky_free(utf8_buf);
          pristriy_mavky_free(wide_buf);
          return NULL;
        }
        utf8_buf = tmp;
      }
      utf8_buf[utf8_len++] = c;
    }

    if (utf8_len > 0) {
      int w_len = MultiByteToWideChar(CP_UTF8, 0, utf8_buf, utf8_len, NULL, 0);
      if (w_len > 0) {
        if ((size_t)w_len >= wide_cap) {
          wide_cap = w_len + 1;
          WCHAR* tmp = (WCHAR*)pristriy_mavky_realloc(wide_buf,
                                                      wide_cap * sizeof(WCHAR));
          if (!tmp) {
            pristriy_mavky_free(utf8_buf);
            pristriy_mavky_free(wide_buf);
            return NULL;
          }
          wide_buf = tmp;
        }
        MultiByteToWideChar(CP_UTF8, 0, utf8_buf, utf8_len, wide_buf, w_len);
        wide_len = w_len;
      }
    }
    pristriy_mavky_free(utf8_buf);
  }

  // If nothing read, return NULL
  if (wide_len == 0) {
    pristriy_mavky_free(wide_buf);
    return NULL;
  }

  // Convert UTF-16 back to UTF-8 for Mavka
  int utf8_size =
      WideCharToMultiByte(CP_UTF8, 0, wide_buf, wide_len, NULL, 0, NULL, NULL);
  if (utf8_size == 0) {
    pristriy_mavky_free(wide_buf);
    return NULL;
  }

  char* buf = (char*)pristriy_mavky_malloc(utf8_size + 1);
  if (!buf) {
    pristriy_mavky_free(wide_buf);
    return NULL;
  }

  WideCharToMultiByte(CP_UTF8, 0, wide_buf, wide_len, buf, utf8_size, NULL,
                      NULL);
  buf[utf8_size] = '\0';

  pristriy_mavky_free(wide_buf);

  if (out_len)
    *out_len = utf8_size;

  return buf;
}
