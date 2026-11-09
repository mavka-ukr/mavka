#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/mavka/prystriy.h"

#ifndef MAVKA_MALLOC_FN
#define MAVKA_MALLOC_FN malloc
#endif
#ifndef MAVKA_REALLOC_FN
#define MAVKA_REALLOC_FN realloc
#endif
#ifndef MAVKA_FREE_FN
#define MAVKA_FREE_FN free
#endif

static void print_color(PristriyMavkyWriteToStdoutColor color);
static char* do_readline(char* prefix, size_t prefix_size, size_t* out_len);

// ----------------------------

void* pristriy_mavky_malloc(size_t size) {
  return MAVKA_MALLOC_FN(size);
}

void* pristriy_mavky_realloc(void* value, size_t new_size) {
  return MAVKA_REALLOC_FN(value, new_size);
}

void pristriy_mavky_free(void* value) {
  MAVKA_FREE_FN(value);
}

void pristriy_mavky_write_to_stdout(char* data, size_t size) {
  fwrite(data, 1, size, stdout);
}

void pristriy_mavky_write_utf8_to_stdout(PristriyMavkyWriteToStdoutColor color,
                                         char* data,
                                         size_t size) {
  print_color(color);

  fwrite(data, 1, size, stdout);

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
  int len = snprintf(buf, sizeof(buf), "%llu", (unsigned long long)value);
  if (len < 0) {
    return false;
  }
  *size_out = (size_t)len;
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    return false;
  }
  for (size_t і = 0; і < *size_out; і++) {
    (*data_out)[і] = buf[і];
  }
  return true;
}

bool pristriy_mavky_int64_to_str(ssize_t value,
                                 char** data_out,
                                 size_t* size_out) {
  char buf[32];
  int len = snprintf(buf, sizeof(buf), "%lld", (long long)value);
  if (len < 0) {
    return false;
  }
  *size_out = (size_t)len;
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    return false;
  }
  for (size_t і = 0; і < *size_out; і++) {
    (*data_out)[і] = buf[і];
  }
  return true;
}

// 123.0 => "123"
// 123.456 => "123.456"
// -0.00123 => "-0.00123"
// 1.2e+30 => "1.2" 30
// 1.2e-30 => "1.2" -30
bool pristriy_mavky_double_to_str(double value,
                                  char** data_out,
                                  size_t* size_out,
                                  ssize_t* exp_size_out) {
  char buf[64];
  int len;

  if (isnan(value)) {
    char nan_str[] = "невизначеність";
    *size_out = sizeof(nan_str) - 1;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return false;
    memcpy(*data_out, nan_str, *size_out);
    *exp_size_out = 0;
    return true;
  }

  if (isinf(value)) {
    char* inf_str = value > 0 ? "нескінченність" : "-нескінченність";
    *size_out = value > 0 ? sizeof("нескінченність") - 1
                          : sizeof("-нескінченність") - 1;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return false;
    memcpy(*data_out, inf_str, *size_out);
    *exp_size_out = 0;
    return true;
  }

  // Знаходимо найкоротше представлення, яке round-trips
  // Пробуємо від 15 до 17 цифр точності
  for (int precision = 15; precision <= 17; precision++) {
    len = snprintf(buf, sizeof(buf), "%.*g", precision, value);
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
    return false;
  }

  char* e_pos = strchr(buf, 'e');
  if (e_pos != NULL) {
    *exp_size_out = (ssize_t)strtol(e_pos + 1, NULL, 10);

    size_t mantissa_len = (size_t)(e_pos - buf);

    *size_out = mantissa_len;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return false;

    for (size_t і = 0; і < mantissa_len; і++) {
      (*data_out)[і] = buf[і];
    }
  } else {
    *exp_size_out = 0;

    *size_out = (size_t)len;
    *data_out = (char*)pristriy_mavky_malloc(*size_out);
    if (!*data_out)
      return false;

    for (size_t і = 0; і < *size_out; і++) {
      (*data_out)[і] = buf[і];
    }
  }

  return true;
}

bool pristriy_mavky_str_to_double(char* data, size_t size, double* out) {
  char* str = (char*)pristriy_mavky_malloc(size + 1);
  size_t len = 0;
  for (size_t і = 0; і < size; і++) {
    unsigned char c = (unsigned char)data[і];
    if (c == 0xD0 || c == 0xD1) {
      if (і + 1 < size) {
        unsigned char c2 = (unsigned char)data[і + 1];
        if (c == 0xD0 && c2 == 0xB5) {
          str[len++] = 'e';
          і++;
          continue;
        }
        if (c == 0xD0 && c2 == 0x95) {
          str[len++] = 'E';
          і++;
          continue;
        }
      }
    }

    str[len++] = (char)c;
  }
  str[len] = '\0';

  char* endptr;

  *out = strtod(str, &endptr);

  if (str == endptr) {
    pristriy_mavky_free(str);
    return false;
  } else if (errno == ERANGE) {
    pristriy_mavky_free(str);
    return false;
  } else if (*endptr != '\0') {
    pristriy_mavky_free(str);
    return false;
  }

  pristriy_mavky_free(str);
  return true;
}

bool pristriy_mavky_get_cwd(char** data_out, size_t* size_out) {
  char* cwd = getcwd(NULL, 0);
  if (cwd == NULL) {
    return false;
  }

  *size_out = strlen(cwd);
  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    pristriy_mavky_free(cwd);
    return false;
  }

  memcpy(*data_out, cwd, *size_out);
  pristriy_mavky_free(cwd);
  return true;
}

bool pristriy_mavky_get_absolute_path(char* path_data,
                                      size_t path_size,
                                      char** data_out,
                                      size_t* size_out) {
  char* pathstr = (char*)pristriy_mavky_malloc(path_size + 1);
  for (size_t і = 0; і < path_size; і++) {
    pathstr[і] = (char)path_data[і];
  }
  pathstr[path_size] = '\0';

  char* abspath = realpath(pathstr, NULL);
  pristriy_mavky_free(pathstr);

  if (abspath == NULL) {
    return false;
  }

  size_t len = strlen(abspath);
  *size_out = len;
  *data_out = (char*)pristriy_mavky_malloc(len);
  if (!*data_out) {
    pristriy_mavky_free(abspath);
    return false;
  }

  for (size_t і = 0; і < len; і++) {
    (*data_out)[і] = abspath[і];
  }

  pristriy_mavky_free(abspath);
  return true;
}

bool pristriy_mavky_check_if_file_exists(char* path_data, size_t path_size) {
  char* pathstr = (char*)pristriy_mavky_malloc(path_size + 1);
  for (size_t і = 0; і < path_size; і++) {
    pathstr[і] = (char)path_data[і];
  }
  pathstr[path_size] = '\0';

  struct stat statbuf;
  bool res = false;
  if (stat(pathstr, &statbuf) == 0) {
    if (S_ISREG(statbuf.st_mode)) {
      res = true;
    }
  }

  pristriy_mavky_free(pathstr);
  return res;
}

bool pristriy_mavky_read_file(char* path_data,
                              size_t path_size,
                              char** data_out,
                              size_t* size_out) {
  char* pathstr = (char*)pristriy_mavky_malloc(path_size + 1);
  for (size_t і = 0; і < path_size; і++) {
    pathstr[і] = (char)path_data[і];
  }
  pathstr[path_size] = '\0';

  FILE* f = fopen(pathstr, "rb");
  pristriy_mavky_free(pathstr);
  if (!f) {
    return false;
  }

  fseek(f, 0, SEEK_END);
  *size_out = ftell(f);
  fseek(f, 0, SEEK_SET);

  *data_out = (char*)pristriy_mavky_malloc(*size_out);
  if (!*data_out) {
    fclose(f);
    return false;
  }

  fread(*data_out, 1, *size_out, f);
  fclose(f);
  return true;
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
    callback(data, len, true, arg);

    return true;
  }

  callback(data, len, false, arg);

  return true;
}

void pristriy_mavky_exit(int code) {
  exit(code);
}

// ----------------------------

static void print_color(PristriyMavkyWriteToStdoutColor color) {
  if (color == PristriyMavkyColorReset) {
    printf("\033[0m");
  }

  if (color == PristriyMavkyColorRed) {
    printf("\033[0;31m");
  }

  if (color == PristriyMavkyColorGreen) {
    printf("\033[0;32m");
  }

  if (color == PristriyMavkyColorBlue) {
    printf("\033[0;34m");
  }

  if (color == PristriyMavkyColorYellow) {
    printf("\033[0;33m");
  }
}

#ifdef PROGRAM_USE_READLINE
#include <readline/readline.h>

static char* do_readline(char* prefix, size_t prefix_size, size_t* out_len) {
  char* data = readline(prefix);
  if (!data) {
    return NULL;
  }

  *out_len = strlen(data);
  return data;
}
#else
static char* do_readline(char* prefix, size_t prefix_size, size_t* out_len) {
  pristriy_mavky_write_utf8_to_stdout(PristriyMavkyColorReset, prefix,
                                      prefix_size);

  size_t cap = 128;
  size_t len = 0;
  char* buf = (char*)pristriy_mavky_malloc(cap);
  if (!buf)
    return NULL;

  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      break; // stop, but DON'T store '\n'

    if (len + 1 >= cap) {
      cap *= 2;
      char* tmp = pristriy_mavky_realloc(buf, cap);
      if (!tmp) {
        pristriy_mavky_free(buf);
        return NULL;
      }
      buf = tmp;
    }

    buf[len++] = c;
  }

  // If nothing read and EOF, return NULL
  if (len == 0 && c == EOF) {
    pristriy_mavky_free(buf);
    return NULL;
  }

  buf[len] = '\0';

  if (out_len)
    *out_len = len;

  return buf;
}
#endif
