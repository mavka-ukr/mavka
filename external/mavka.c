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

#define п8 uint8_t
#define п16 uint16_t
#define п32 uint32_t
#define п64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define д32 float
#define д64 double
#define логічне uint8_t
#define позитивне п64
#define ціле ц64
#define дійсне д64
#define ніщо void
#define невідома_адреса void*
#define невідома_памʼять void*
#define памʼять_п8 п8*
#define адреса_памʼять_п8 п8**
#define памʼять_памʼять_п8 п8**
#define адреса_позитивне позитивне*
typedef struct т8 {
  позитивне розмір;
  памʼять_п8 дані;
} т8;
typedef struct ю8 {
  позитивне розмір;
  памʼять_п8 дані;
} ю8;
#define памʼять_т8 т8*
#define памʼять_ю8 ю8*

static char* перетворити_ю8_в_chars(ю8 value) {
  char* copy = (char*)malloc(value.розмір + 1);
  memcpy(copy, value.дані, value.розмір);
  copy[value.розмір] = 0;
  return copy;
}

extern памʼять_п8 мавка_система_виділити_сиру_памʼять(позитивне розмір);
extern памʼять_п8 мавка_система_перевиділити_сиру_памʼять(
    памʼять_п8 значення,
    позитивне новий_розмір);
extern ніщо мавка_система_звільнити_сиру_памʼять(памʼять_п8 значення);
extern ніщо мавка_система_вивести_ю8(позитивне розмір, памʼять_п8 дані);
extern ніщо мавка_система_вивести_позитивне(позитивне значення);
extern ніщо мавка_система_вивести_ціле(ціле значення);
extern ніщо print_long(long значення);
extern ніщо мавка_система_вивести_д64(д64 значення);
extern ніщо мавка_система_вийти(ц32 код);
extern ніщо мавка_система_перетворити_д64_в_ю8(д64 значення, ю8* вихід);
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
extern д64 мавка_система_остача_від_ділення_д64(д64 а, д64 б);
extern д64 мавка_система_неповна_частка_від_ділення_д64(д64 а, д64 б);
extern д64 мавка_система_піднести_до_степеня_д64(д64 а, д64 б);
невідома_адреса
мавка_система_відкрити_поширену_бібліотеку(ю8* шлях);
ніщо мавка_система_закрити_поширену_бібліотеку(
    невідома_адреса поширена_бібліотека);
невідома_адреса мавка_система_отримати_символ_поширеної_бібліотеки(
    невідома_адреса поширена_бібліотека,
    ю8* назва_символа);
extern long long_to_chars(long value, char** out);
extern ц32 запустити_мавку(ц32 кількість_аргументів, памʼять_ю8 аргументи);

extern памʼять_п8 мавка_система_виділити_сиру_памʼять(позитивне розмір) {
  return (памʼять_п8)malloc(розмір);
}

extern памʼять_п8 мавка_система_перевиділити_сиру_памʼять(
    памʼять_п8 значення,
    позитивне новий_розмір) {
  return (памʼять_п8)realloc(значення, новий_розмір);
}

extern ніщо мавка_система_звільнити_сиру_памʼять(памʼять_п8 значення) {
  free(значення);
}

extern ніщо мавка_система_вивести_ю8(позитивне розмір, памʼять_п8 дані) {
  printf("%.*s", (int)розмір, дані);
  fflush(stdout);
}

extern ніщо мавка_система_вивести_позитивне(позитивне значення) {
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

extern ніщо мавка_система_вивести_д64(д64 значення) {
  char* dv = doubleToString(значення);
  printf("%s", dv);
  fflush(stdout);
  free(dv);
}

extern ніщо мавка_система_вийти(ц32 код) {
  exit(код);
}

extern ніщо мавка_система_перетворити_д64_в_ю8(д64 значення, ю8* вихід) {
  char* str = doubleToString(значення);
  вихід->розмір = strlen(str);
  вихід->дані = (памʼять_п8)str;
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
  вихід->дані = (памʼять_п8)buffer;
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
    вихід->дані = (памʼять_п8)absolute_path;
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
    вихід->дані = (памʼять_п8)parent_path;
  }
  return true;
}

extern логічне мавка_система_отримати_поточну_папку_процесу(ю8* вихід) {
  const char* cwd = getcwd(NULL, 0);
  вихід->розмір = strlen(cwd);
  вихід->дані = (памʼять_п8)cwd;
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
  вихід->дані = (памʼять_п8)filename;
  return true;
}

extern логічне мавка_система_перевірити_чи_шлях_існує_і_є_файлом(ю8* шлях) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  FILE* file = fopen(path, "r");
  free((void*)path);
  if (file) {
    fclose(file);
    return true;
  }
  return false;
}

#ifndef MAVKA_VERSION
#define MAVKA_VERSION "0.0.0"
#endif

extern void мавка_отримати_версію_мавки_як_ю8(ю8* вихід) {
  вихід->розмір = strlen(MAVKA_VERSION);
  вихід->дані = (памʼять_п8)MAVKA_VERSION;
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
  вихід->дані = (памʼять_п8)value;
  return true;
}

extern д64 мавка_система_округлити_д64(д64 значення) {
  return round(значення);
}

extern д64 мавка_система_остача_від_ділення_д64(д64 а, д64 б) {
  return fmod(а, б);
}

extern д64 мавка_система_неповна_частка_від_ділення_д64(д64 а, д64 б) {
  return floor(а / б);
}

extern д64 мавка_система_піднести_до_степеня_д64(д64 а, д64 б) {
  return pow(а, б);
}

extern д64 мавка_система_синус_д64(д64 значення) {
  return sin(значення);
}

extern д64 мавка_система_косинус_д64(д64 значення) {
  return cos(значення);
}

extern д64 мавка_система_тангенс_д64(д64 значення) {
  return tan(значення);
}

extern д64 мавка_система_арксинус_д64(д64 значення) {
  return asin(значення);
}

extern д64 мавка_система_арккосинус_д64(д64 значення) {
  return acos(значення);
}

extern д64 мавка_система_арктангенс_д64(д64 значення) {
  return atan(значення);
}

extern д64 мавка_система_арктангенс2_д64(д64 а, д64 б) {
  return atan2(а, б);
}

extern д64 мавка_система_абсолютне_д64(д64 значення) {
  return fabs(значення);
}

extern д64 мавка_система_експонента_д64(д64 значення) {
  return exp(значення);
}

extern д64 мавка_система_корінь_д64(д64 значення) {
  return sqrt(значення);
}

extern д64 мавка_система_степінь_д64(д64 а, д64 б) {
  return pow(а, б);
}

extern д64 мавка_система_стеля_д64(д64 значення) {
  return ceil(значення);
}

extern д64 мавка_система_підлога_д64(д64 значення) {
  return floor(значення);
}

extern невідома_адреса мавка_система_відкрити_поширену_бібліотеку(ю8* шлях) {
  const char* path = перетворити_ю8_в_chars(*шлях);
  void* dobject = dlopen(path, RTLD_LAZY);
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

extern long long_to_chars(long value, char** out) {
  int length = snprintf(NULL, 0, "%ld", value);
  char* str = (char*)malloc(length + 1);
  snprintf(str, length + 1, "%ld", value);
  *out = str;
  return strlen(str);
}

extern логічне мавка_система_перетворити_ц64_на_ю8(ц64 значення, ю8* вихід) {
  int length = snprintf(NULL, 0, "%ld", значення);
  if (length < 0) {
    return false;
  }

  char* str = (char*)malloc(length + 1);
  if (!str) {
    return false;
  }

  snprintf(str, length + 1, "%ld", значення);

  вихід->розмір = strlen(str);
  вихід->дані = (памʼять_п8)str;
  return true;
}

extern логічне мавка_система_перетворити_н64_на_ю8(п64 значення, ю8* вихід) {
  int length = snprintf(NULL, 0, "%" PRIu64, значення);
  if (length < 0) {
    return false;
  }

  char* str = (char*)malloc(length + 1);
  if (!str) {
    return false;
  }

  snprintf(str, length + 1, "%" PRIu64, значення);

  вихід->розмір = strlen(str);
  вихід->дані = (памʼять_п8)str;
  return true;
}

extern логічне мавка_система_перетворити_д64_на_ю8(д64 значення, ю8* вихід) {
  int length = snprintf(NULL, 0, "%.9g", значення);
  if (length < 0) {
    return false;
  }

  char* buffer = malloc(length + 1);
  if (!buffer) {
    return false;
  }

  snprintf(buffer, length + 1, "%.9g", значення);

  вихід->розмір = strlen(buffer);
  вихід->дані = (памʼять_п8)buffer;
  return true;
}

extern логічне мавка_система_перетворити_ю8_на_ц64(
    ю8* значення,
    ц64* вихід,
    позитивне* вихід_позиції_помилки) {
  return false;
}

extern логічне мавка_система_перетворити_ю8_на_н64(
    ю8* значення,
    п64* вихід,
    позитивне* вихід_позиції_помилки) {
  return false;
}

extern логічне мавка_система_перетворити_ю8_на_д64(
    ю8* значення,
    д64* вихід,
    позитивне* вихід_позиції_помилки) {
  return false;
}

int main(int argc, char** argv) {
  ю8 аргументи[argc];
  for (int i = 0; i < argc; ++i) {
    аргументи[i].розмір = strlen(argv[i]);
    аргументи[i].дані = (памʼять_п8)argv[i];
  }
  return запустити_мавку(argc, аргументи);
}