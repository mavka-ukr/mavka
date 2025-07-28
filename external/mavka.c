#include <dlfcn.h>
#include <inttypes.h>
#include <libgen.h>
#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define н8 uint8_t
#define н16 uint16_t
#define н32 uint32_t
#define н64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define р32 float
#define р64 double
#define логічне uint8_t
#define натуральне н64
#define ціле ц64
#define дійсне р64
#define ніщо void
#define невідома_адреса void*
#define невідома_памʼять void*
#define памʼять_н8 н8*
#define адреса_памʼять_н8 н8**
#define памʼять_памʼять_н8 н8**
#define адреса_натуральне натуральне*
typedef struct т8 {
  натуральне розмір;
  памʼять_н8 дані;
} т8;
typedef struct ю8 {
  натуральне розмір;
  памʼять_н8 дані;
} ю8;
#define памʼять_т8 т8*
#define памʼять_ю8 ю8*

static char* перетворити_ю8_в_chars(ю8 value) {
  char* copy = (char*)malloc(value.розмір + 1);
  memcpy(copy, value.дані, value.розмір);
  copy[value.розмір] = 0;
  return copy;
}

extern памʼять_н8 мавка_система_виділити_сиру_памʼять(натуральне розмір);
extern памʼять_н8 мавка_система_перевиділити_сиру_памʼять(
    памʼять_н8 значення,
    натуральне новий_розмір);
extern ніщо мавка_система_звільнити_сиру_памʼять(памʼять_н8 значення);
extern ніщо мавка_система_вивести_ю8(натуральне розмір, памʼять_н8 дані);
extern ніщо мавка_система_вивести_натуральне(натуральне значення);
extern ніщо мавка_система_вивести_ціле(ціле значення);
extern ніщо print_long(long значення);
extern ніщо мавка_система_вивести_р64(р64 значення);
extern ніщо мавка_система_вийти(ц32 код);
extern ніщо мавка_система_перетворити_р64_в_ю8(р64 значення, ю8* вихід);
extern логічне мавка_система_прочитати_файл(ю8* шлях, ю8* вихід);
extern логічне мавка_система_отримати_абсолютний_шлях(ю8* шлях, ю8* вихід);
extern логічне мавка_система_отримати_абсолютний_зовнішній_шлях(ю8* шлях,
                                                                ю8* вихід);
extern логічне мавка_система_отримати_поточну_папку_процесу(ю8* вихід);
extern логічне мавка_система_отримати_назву_файлу_без_розширення(ю8* шлях,
                                                                 ю8* вихід);
extern логічне мавка_система_перевірити_чи_шлях_існує_і_є_файлом(ю8* шлях);
extern логічне мавка_система_прочитати_ю8_зі_стандартного_вводу(
    ю8* префікс,
    ю8* вихід,
    логічне додати_в_історію);
extern р64 мавка_система_остача_від_ділення_р64(р64 а, р64 б);
extern р64 мавка_система_неповна_частка_від_ділення_р64(р64 а, р64 б);
extern р64 мавка_система_піднести_до_степеня_р64(р64 а, р64 б);
невідома_адреса
мавка_система_відкрити_поширену_бібліотеку(ю8* шлях);
ніщо мавка_система_закрити_поширену_бібліотеку(
    невідома_адреса поширена_бібліотека);
невідома_адреса мавка_система_отримати_символ_поширеної_бібліотеки(
    невідома_адреса поширена_бібліотека,
    ю8* назва_символа);
extern long long_to_chars(long value, char** out);
extern ц32 запустити_мавку(ц32 кількість_аргументів, памʼять_ю8 аргументи);

extern памʼять_н8 мавка_система_виділити_сиру_памʼять(натуральне розмір) {
  return (памʼять_н8)malloc(розмір);
}

extern памʼять_н8 мавка_система_перевиділити_сиру_памʼять(
    памʼять_н8 значення,
    натуральне новий_розмір) {
  return (памʼять_н8)realloc(значення, новий_розмір);
}

extern ніщо мавка_система_звільнити_сиру_памʼять(памʼять_н8 значення) {
  free(значення);
}

extern ніщо мавка_система_вивести_ю8(натуральне розмір, памʼять_н8 дані) {
  printf("%.*s", (int)розмір, дані);
  fflush(stdout);
}

extern ніщо мавка_система_вивести_натуральне(натуральне значення) {
  printf("%lu", значення);
  fflush(stdout);
}

extern ніщо мавка_система_вивести_ціле(ціле значення) {
  printf("%ld", значення);
  fflush(stdout);
}

extern ніщо print_long(long значення) {
  printf("%ld", значення);
  fflush(stdout);
}

char* doubleToString(double value) {
  long decimal = (long)value;
  if ((double)decimal == value) {
    char* res = (char*)malloc(128);
    sprintf(res, "%ld", decimal);
    return res;
  }
  char* res = (char*)malloc(128);
  sprintf(res, "%.15f", value);
  return res;
}

extern ніщо мавка_система_вивести_р64(р64 значення) {
  char* dv = doubleToString(значення);
  printf("%s", dv);
  fflush(stdout);
  free(dv);
}

extern ніщо мавка_система_вийти(ц32 код) {
  exit(код);
}

extern ніщо мавка_система_перетворити_р64_в_ю8(р64 значення, ю8* вихід) {
  char* str = doubleToString(значення);
  вихід->розмір = strlen(str);
  вихід->дані = (памʼять_н8)str;
}

extern логічне мавка_система_прочитати_файл(ю8* шлях, ю8* вихід) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  FILE* f = fopen(path, "rb");
  free((void*)path);
  if (f == NULL) {
    return false;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  char* buffer = malloc(fsize);
  fread(buffer, fsize, 1, f);
  fclose(f);
  вихід->розмір = fsize;
  вихід->дані = (памʼять_н8)buffer;
  return true;
}

extern логічне мавка_система_отримати_абсолютний_шлях(ю8* шлях, ю8* вихід) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  const char* absolute_path = realpath((char*)path, NULL);
  free((void*)path);
  if (absolute_path == NULL) {
    return false;
  } else {
    вихід->розмір = strlen(absolute_path);
    вихід->дані = (памʼять_н8)absolute_path;
    return true;
  }
}

extern логічне мавка_система_отримати_абсолютний_зовнішній_шлях(ю8* шлях,
                                                                ю8* вихід) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  const char* absolute_path = strdup(realpath((char*)path, NULL));
  free((void*)path);
  if (absolute_path == NULL) {
    return false;
  }
  const char* parent_path = dirname((char*)absolute_path);
  free((void*)absolute_path);
  if (parent_path == NULL) {
    return false;
  } else {
    вихід->розмір = strlen(parent_path);
    вихід->дані = (памʼять_н8)parent_path;
  }
  return true;
}

extern логічне мавка_система_отримати_поточну_папку_процесу(ю8* вихід) {
  const char* cwd = getcwd(NULL, 0);
  вихід->розмір = strlen(cwd);
  вихід->дані = (памʼять_н8)cwd;
  return true;
}

extern логічне мавка_система_отримати_назву_файлу_без_розширення(ю8* шлях,
                                                                 ю8* вихід) {
  char* path = перетворити_ю8_в_chars(*шлях);
  char* bn = strdup(basename((char*)path));
  free((void*)path);
  if (bn == NULL) {
    вихід->розмір = 0;
    вихід->дані = NULL;
    return false;
  }
  char* filename = strdup(bn);
  free((void*)bn);
  size_t len = 0;
  while (filename[len] != 0 && filename[len] != '.') {
    len++;
  }
  вихід->розмір = len;
  вихід->дані = (памʼять_н8)filename;
  return true;
}

bool is_regular_file(const char* path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0)
        return false;
    return S_ISREG(path_stat.st_mode);
}

extern логічне мавка_система_перевірити_чи_шлях_існує_і_є_файлом(ю8* шлях) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  bool res = is_regular_file(path);
  free((void*)path);
  return res;
}

#ifndef MAVKA_VERSION
#define MAVKA_VERSION "0.0.0"
#endif

extern void мавка_отримати_версію_мавки_як_ю8(ю8* вихід) {
  вихід->розмір = strlen(MAVKA_VERSION);
  вихід->дані = (памʼять_н8)MAVKA_VERSION;
}

#include <readline/history.h>
#include <readline/readline.h>

const char* mavka_readline(const char* prefix) {
  return readline(prefix);
}

void mavka_readline_add_history(const char* value) {
  add_history(value);
}

extern логічне мавка_система_прочитати_ю8_зі_стандартного_вводу(
    ю8* префікс,
    ю8* вихід,
    логічне додати_в_історію) {
  const char* prefix = перетворити_ю8_в_chars(*префікс);
  const char* value = mavka_readline(prefix);
  free((void*)prefix);
  if (value == NULL) {
    return false;
  }
  size_t len = strlen(value);
  if (додати_в_історію && len != 0) {
    mavka_readline_add_history(value);
  }
  вихід->розмір = len;
  вихід->дані = (памʼять_н8)value;
  return true;
}

extern р64 мавка_система_округлити_р64(р64 значення) {
  return round(значення);
}

extern р64 мавка_система_остача_від_ділення_р64(р64 а, р64 б) {
  return fmod(а, б);
}

extern р64 мавка_система_неповна_частка_від_ділення_р64(р64 а, р64 б) {
  return floor(а / б);
}

extern р64 мавка_система_піднести_до_степеня_р64(р64 а, р64 б) {
  return pow(а, б);
}

extern р64 мавка_система_синус_р64(р64 значення) {
  return sin(значення);
}

extern р64 мавка_система_косинус_р64(р64 значення) {
  return cos(значення);
}

extern р64 мавка_система_тангенс_р64(р64 значення) {
  return tan(значення);
}

extern р64 мавка_система_арксинус_р64(р64 значення) {
  return asin(значення);
}

extern р64 мавка_система_арккосинус_р64(р64 значення) {
  return acos(значення);
}

extern р64 мавка_система_арктангенс_р64(р64 значення) {
  return atan(значення);
}

extern р64 мавка_система_арктангенс2_р64(р64 а, р64 б) {
  return atan2(а, б);
}

extern р64 мавка_система_абсолютне_р64(р64 значення) {
  return fabs(значення);
}

extern р64 мавка_система_експонента_р64(р64 значення) {
  return exp(значення);
}

extern р64 мавка_система_корінь_р64(р64 значення) {
  return sqrt(значення);
}

extern р64 мавка_система_степінь_р64(р64 а, р64 б) {
  return pow(а, б);
}

extern р64 мавка_система_стеля_р64(р64 значення) {
  return ceil(значення);
}

extern р64 мавка_система_підлога_р64(р64 значення) {
  return floor(значення);
}

extern невідома_адреса мавка_система_відкрити_поширену_бібліотеку(ю8* шлях) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  void* dobject = dlopen(path, RTLD_NOW | RTLD_LOCAL);
  free((void*)path);
  return dobject;
}

extern ніщо мавка_система_закрити_поширену_бібліотеку(
    невідома_адреса поширена_бібліотека) {
  dlclose(поширена_бібліотека);
}

extern невідома_адреса мавка_система_отримати_символ_поширеної_бібліотеки(
    невідома_адреса поширена_бібліотека,
    ю8* назва_символа) {
  const char* name = перетворити_ю8_в_chars(*назва_символа);
  void* sym = dlsym(поширена_бібліотека, name);
  free((void*)name);
  return sym;
}

void trim_trailing_zeros(char *str) {
    char *dot = strchr(str, '.');
    if (!dot) return;

    char *end = str + strlen(str) - 1;
    while (end > dot && *end == '0') {
        *end-- = '\0';
    }
    if (end == dot) {
        *end = '\0';
    }
}

extern long long_to_chars(long value, char** out) {
  int length = snprintf(NULL, 0, "%ld", value);
  char* buffer = (char*)malloc(length + 1);
  snprintf(buffer, length + 1, "%ld", value);
  trim_trailing_zeros(buffer);
  *out = buffer;
  return strlen(buffer);
}

extern логічне мавка_система_перетворити_ц64_на_ю8(ц64 значення, ю8* вихід) {
  int length = snprintf(NULL, 0, "%ld", значення);
  if (length < 0) {
    return false;
  }

  char* buffer = (char*)malloc(length + 1);
  if (!buffer) {
    return false;
  }

  snprintf(buffer, length + 1, "%ld", значення);

  trim_trailing_zeros(buffer);

  вихід->розмір = strlen(buffer);
  вихід->дані = (памʼять_н8)buffer;
  return true;
}

extern логічне мавка_система_перетворити_н64_на_ю8(н64 значення, ю8* вихід) {
  int length = snprintf(NULL, 0, "%" PRIu64, значення);
  if (length < 0) {
    return false;
  }

  char* buffer = (char*)malloc(length + 1);
  if (!buffer) {
    return false;
  }

  snprintf(buffer, length + 1, "%" PRIu64, значення);

  trim_trailing_zeros(buffer);

  вихід->розмір = strlen(buffer);
  вихід->дані = (памʼять_н8)buffer;
  return true;
}

void replace_scientific_notation(char *str) {
  char *e = strpbrk(str, "eE");
  if (e) {
    size_t tail_len = strlen(e + 1);
    memmove(e + 2, e + 1, tail_len + 1); // make room for 2-byte UTF-8 char
    e[0] = (char)0xD0;
    e[1] = (char)0xB5;
  }
}


extern логічне мавка_система_перетворити_р64_на_ю8(р64 значення, ю8* вихід) {
  int length = snprintf(NULL, 0, "%.21g", значення);
  if (length < 0) {
    return false;
  }

  char *buffer = malloc(length + 3);
  if (!buffer) {
    return false;
  }

  snprintf(buffer, length + 1, "%.21g", значення);
  
  replace_scientific_notation(buffer);
  
  trim_trailing_zeros(buffer);

  вихід->розмір = strlen(buffer);
  вихід->дані = (памʼять_н8)buffer;

  return true;
}

extern логічне мавка_система_перевірити_чи_р64_нескінченність(р64 значення) {
  return isinf(значення);
}

extern логічне мавка_система_перевірити_чи_р64_невизначеність(р64 значення) {
  return isnan(значення);
}

extern логічне мавка_система_перетворити_ю8_на_ц64(
    ю8* значення,
    ц64* вихід,
    натуральне* вихід_позиції_помилки) {
  return false;
}

extern логічне мавка_система_перетворити_ю8_на_н64(
    ю8* значення,
    н64* вихід,
    натуральне* вихід_позиції_помилки) {
  return false;
}

extern логічне мавка_система_перетворити_ю8_на_р64(
    ю8* значення,
    р64* вихід,
    натуральне* вихід_позиції_помилки) {
  return false;
}

int main(int argc, char** argv) {
  ю8 аргументи[argc];
  for (int i = 0; i < argc; ++i) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (памʼять_н8)argv[i];
  }
  return запустити_мавку(argc, аргументи);
}