#include <errno.h>
#include <libgen.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "mavka/prystriy.h"

логічне пристрій_мавки_отримати_версію_як_ю8(п8** вихід_даних,
                                             природне* вихід_розміру) {
  *вихід_розміру = strlen(MAVKA_VERSION);
  *вихід_даних = (п8*)strdup(MAVKA_VERSION);

  return true;
}

адреса пристрій_мавки_виділити(природне розмір) {
  return (адреса)malloc(розмір);
}

адреса пристрій_мавки_перевиділити(адреса значення, природне новий_розмір) {
  return (адреса)realloc(значення, новий_розмір);
}

void пристрій_мавки_звільнити(адреса значення) {
  free(значення);
}

static void пристрій_мавки_вивести_колір(природне значення) {
  if (значення == КолірВиводуСтандартний) {
    printf("\033[0m");
  }

  if (значення == КолірВиводуЧервоний) {
    printf("\033[0;31m");
  }

  if (значення == КолірВиводуЗелений) {
    printf("\033[0;32m");
  }

  if (значення == КолірВиводуСиній) {
    printf("\033[0;34m");
  }

  if (значення == КолірВиводуЖовтий) {
    printf("\033[0;33m");
  }
}

extern void пристрій_мавки_вивести_сирі_дані(п8* дані, природне розмір) {
  fwrite(дані, 1, розмір, stdout);
}

extern void пристрій_мавки_вивести_шлях(природне колір,
                                        п8* дані,
                                        природне розмір) {
  пристрій_мавки_вивести_колір(колір);

  fwrite(дані, 1, розмір, stdout);

  пристрій_мавки_вивести_колір(КолірВиводуСтандартний);
}

extern void пристрій_мавки_вивести_ю8(природне колір,
                                      п8* дані,
                                      природне розмір) {
  пристрій_мавки_вивести_колір(колір);

  fwrite(дані, 1, розмір, stdout);

  пристрій_мавки_вивести_колір(КолірВиводуСтандартний);
}

extern void пристрій_мавки_вийти(ц32 код_виходу) {
  exit(код_виходу);
}

bool pristriy_mavky_read_file(char* path_data,
                              size_t path_size,
                              char** data_out,
                              size_t* size_out) {
  char* pathstr = (char*)пристрій_мавки_виділити(path_size + 1);
  for (size_t і = 0; і < path_size; і++) {
    pathstr[і] = (char)path_data[і];
  }
  pathstr[path_size] = '\0';

  FILE* f = fopen(pathstr, "rb");
  пристрій_мавки_звільнити(pathstr);
  if (!f) {
    return false;
  }

  fseek(f, 0, SEEK_END);
  *size_out = ftell(f);
  fseek(f, 0, SEEK_SET);

  *data_out = (char*)пристрій_мавки_виділити(*size_out);
  if (!*data_out) {
    fclose(f);
    return false;
  }

  fread(*data_out, 1, *size_out, f);
  fclose(f);
  return true;
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
  *data_out = (char*)пристрій_мавки_виділити(*size_out);
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
  *data_out = (char*)пристрій_мавки_виділити(*size_out);
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
    *data_out = (char*)пристрій_мавки_виділити(*size_out);
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
    *data_out = (char*)пристрій_мавки_виділити(*size_out);
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
    р64 parsed = strtod(buf, NULL);
    if (parsed == value) {
      break;
    }
  }

  if (len < 0 || len >= (int)sizeof(buf)) {
    return false;
  }

  char* e_pos = strchr(buf, 'e');
  if (e_pos != NULL) {
    *exp_size_out = (ціле)strtol(e_pos + 1, NULL, 10);

    size_t mantissa_len = (size_t)(e_pos - buf);

    *size_out = mantissa_len;
    *data_out = (char*)пристрій_мавки_виділити(*size_out);
    if (!*data_out)
      return false;

    for (size_t і = 0; і < mantissa_len; і++) {
      (*data_out)[і] = buf[і];
    }
  } else {
    *exp_size_out = 0;

    *size_out = (size_t)len;
    *data_out = (char*)пристрій_мавки_виділити(*size_out);
    if (!*data_out)
      return false;

    for (size_t і = 0; і < *size_out; і++) {
      (*data_out)[і] = buf[і];
    }
  }

  return true;
}

bool pristriy_mavky_str_to_double(char* data, size_t size, double* out) {
  char* str = (char*)пристрій_мавки_виділити(size + 1);
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
    пристрій_мавки_звільнити(str);
    return false;
  } else if (errno == ERANGE) {
    пристрій_мавки_звільнити(str);
    return false;
  } else if (*endptr != '\0') {
    пристрій_мавки_звільнити(str);
    return false;
  }

  пристрій_мавки_звільнити(str);
  return true;
}

double pristriy_mavky_double_pow(double value, double exp) {
  return pow(value, exp);
}

bool pristriy_mavky_check_if_file_exists(char* path_data, size_t path_size) {
  char* pathstr = (char*)пристрій_мавки_виділити(path_size + 1);
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

  пристрій_мавки_звільнити(pathstr);
  return res;
}

bool pristriy_mavky_get_absolute_path(char* path_data,
                                      size_t path_size,
                                      char** data_out,
                                      size_t* size_out) {
  char* pathstr = (char*)пристрій_мавки_виділити(path_size + 1);
  for (size_t і = 0; і < path_size; і++) {
    pathstr[і] = (char)path_data[і];
  }
  pathstr[path_size] = '\0';

  char* abspath = realpath(pathstr, NULL);
  пристрій_мавки_звільнити(pathstr);

  if (abspath == NULL) {
    return false;
  }

  size_t len = strlen(abspath);
  *size_out = len;
  *data_out = (char*)пристрій_мавки_виділити(len);
  if (!*data_out) {
    пристрій_мавки_звільнити(abspath);
    return false;
  }

  for (size_t і = 0; і < len; і++) {
    (*data_out)[і] = abspath[і];
  }

  пристрій_мавки_звільнити(abspath);
  return true;
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
  пристрій_мавки_вивести_ю8(КолірВиводуСтандартний, (п8*)prefix,
                            (природне)prefix_size);

  size_t cap = 128;
  size_t len = 0;
  char* buf = пристрій_мавки_виділити(cap);
  if (!buf)
    return NULL;

  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      break; // stop, but DON'T store '\n'

    if (len + 1 >= cap) {
      cap *= 2;
      char* tmp = пристрій_мавки_перевиділити(buf, cap);
      if (!tmp) {
        пристрій_мавки_звільнити(buf);
        return NULL;
      }
      buf = tmp;
    }

    buf[len++] = c;
  }

  // If nothing read and EOF, return NULL
  if (len == 0 && c == EOF) {
    пристрій_мавки_звільнити(buf);
    return NULL;
  }

  buf[len] = '\0';

  if (out_len)
    *out_len = len;

  return buf;
}
#endif

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

bool pristriy_mavky_get_cwd(char** data_out, size_t* size_out) {
  char* cwd = getcwd(NULL, 0);
  if (cwd == NULL) {
    return false;
  }

  *size_out = strlen(cwd);
  *data_out = (char*)пристрій_мавки_виділити(*size_out);
  if (!*data_out) {
    пристрій_мавки_звільнити(cwd);
    return false;
  }

  memcpy(*data_out, cwd, *size_out);
  пристрій_мавки_звільнити(cwd);
  return true;
}
