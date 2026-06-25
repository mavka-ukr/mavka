#include "./walloc.c"
#include "mavka/prystriy.h"

size_t strlen(const char* str);
char* dirname(char* path);
char* strrchr(const char* s, int c);
char* strdup(const char* s);
void* memcpy(void* restrict dest, const void* restrict src, size_t n);
char* basename(char* path);

size_t strlen(const char* str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char* dirname(char* path) {
  static char dot[] = ".";
  size_t len;

  // Return "." if path is NULL or an empty string
  if (path == NULL || *path == '\0') {
    return dot;
  }

  len = strlen(path);

  // Strip trailing slashes, but don't strip the leading slash if it's the only one
  while (len > 1 && path[len - 1] == '/') {
    path[--len] = '\0';
  }

  // If the path was just slashes (e.g., "///"), it's now "/"
  if (len == 1 && path[0] == '/') {
    return path;
  }

  // Find the last remaining slash
  char* last_slash = strrchr(path, '/');

  if (last_slash != NULL) {
    if (last_slash == path) {
      // Path is something like "/usr", dirname is "/"
      path[1] = '\0';
    } else {
      // Path is something like "/usr/bin", dirname is "/usr"
      *last_slash = '\0';
    }
    return path;
  }

  // No slashes remaining, so it's a relative file in the current directory
  return dot;
}

char* strrchr(const char* s, int c) {
  char* last = NULL;
  // The C standard specifies that 'c' is converted to 'unsigned char'
  unsigned char ch = (unsigned char)c;

  // Loop including the null terminator to handle searching for '\0' natively
  for (;;) {
    if ((unsigned char)*s == ch) {
      last = (char*)s;
    }
    if (*s == '\0') {
      break;
    }
    s++;
  }

  return last;
}

char* strdup(const char* s) {
  if (s == NULL) {
    return NULL;
  }

  // 1. Calculate the length of the string
  size_t len = strlen(s);

  // 2. Allocate memory ( +1 byte for the null terminator '\0' )
  char* dup = (char*)malloc(len + 1);

  // 3. Check if malloc failed (out of memory)
  if (dup == NULL) {
    return NULL;
  }

  // 4. Copy the string contents into the new memory block
  memcpy(dup, s, len + 1);

  return dup;
}

void* memcpy(void* restrict dest, const void* restrict src, size_t n) {
  // Cast the void pointers to unsigned char pointers so we can operate byte-by-byte
  unsigned char* d = (unsigned char*)dest;
  const unsigned char* s = (const unsigned char*)src;

  // Loop through and copy each byte
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  // The standard specifies that memcpy always returns the original dest pointer
  return dest;
}

char* basename(char* path) {
  static char dot[] = ".";
  size_t len;

  // 1. If path is NULL or an empty string, return "."
  if (path == NULL || *path == '\0') {
    return dot;
  }

  len = strlen(path);

  // 2. Strip trailing slashes, but keep the first slash if it's the only one
  while (len > 1 && path[len - 1] == '/') {
    path[--len] = '\0';
  }

  // 3. If the path was entirely slashes (e.g., "///"), it's now "/"
  if (len == 1 && path[0] == '/') {
    return path;
  }

  // 4. Find the last remaining slash
  char* last_slash = strrchr(path, '/');

  // 5. If a slash is found, the component is everything after it
  if (last_slash != NULL) {
    return last_slash + 1;
  }

  // 6. If no slash is found, the entire string is the basename
  return path;
}

КористувацькийПристрійМавкиЧитатиЮ8 користувацький_пристрій_мавки_читати_ю8;

extern void змінити_користувацький_пристрій_мавки_читати_ю8(
    КористувацькийПристрійМавкиЧитатиЮ8 нова_функція) {
  користувацький_пристрій_мавки_читати_ю8 = нова_функція;
}

extern логічне пристрій_мавки_отримати_версію_як_ю8(природне* вихід_розміру,
                                                    п8** вихід_даних) {
  *вихід_розміру = strlen(MAVKA_VERSION);
  *вихід_даних = (п8*)strdup(MAVKA_VERSION);

  return true;
}

extern адреса пристрій_мавки_виділити_сиру_памʼять(природне розмір) {
  return malloc(розмір);
}

extern адреса пристрій_мавки_перевиділити_сиру_памʼять(адреса значення,
                                                       природне новий_розмір) {
  return realloc(значення, новий_розмір);
}

extern void пристрій_мавки_звільнити_сиру_памʼять(адреса значення) {
  free(значення);
}

extern логічне пристрій_мавки_перевірити_чи_шлях_закінчується_як_модуль_мавки(
    природне розмір_шляху,
    п8* дані_шляху) {
  const char* суфікс = ".м";
  природне довжина_суфікса = strlen(суфікс);

  if (розмір_шляху < довжина_суфікса) {
    return false;
  }

  for (природне і = 0; і < довжина_суфікса; і++) {
    if (дані_шляху[розмір_шляху - довжина_суфікса + і] != (п8)суфікс[і]) {
      return false;
    }
  }

  return true;
}

extern логічне пристрій_мавки_отримати_теку_шляху(природне розмір_шляху,
                                                  п8* дані_шляху,
                                                  природне* вихід_розміру,
                                                  п8** вихід_даних,
                                                  природне рівень) {
  char* шлях_рядок =
      (char*)пристрій_мавки_виділити_сиру_памʼять(розмір_шляху + 1);
  for (природне і = 0; і < розмір_шляху; і++) {
    шлях_рядок[і] = (char)дані_шляху[і];
  }
  шлях_рядок[розмір_шляху] = '\0';

  char* шлях_копія = strdup(шлях_рядок);
  char* тека = dirname(шлях_копія);

  for (природне і = 1; і < рівень; і++) {
    char* нова_копія = strdup(тека);
    пристрій_мавки_звільнити_сиру_памʼять(шлях_копія);
    шлях_копія = нова_копія;
    тека = dirname(шлях_копія);
  }

  природне довжина = strlen(тека);
  *вихід_розміру = довжина;
  *вихід_даних = (п8*)пристрій_мавки_виділити_сиру_памʼять(довжина);
  if (!*вихід_даних) {
    пристрій_мавки_звільнити_сиру_памʼять(шлях_рядок);
    пристрій_мавки_звільнити_сиру_памʼять(шлях_копія);
    return false;
  }

  for (природне і = 0; і < довжина; і++) {
    (*вихід_даних)[і] = (п8)тека[і];
  }

  пристрій_мавки_звільнити_сиру_памʼять(шлях_рядок);
  пристрій_мавки_звільнити_сиру_памʼять(шлях_копія);
  return true;
}

extern логічне пристрій_мавки_отримати_теку_до_паків(природне розмір_шляху,
                                                     п8* дані_шляху,
                                                     природне* вихід_розміру,
                                                     п8** вихід_даних) {
  const char* паки_суфікс = "/паки";
  природне довжина_суфікса = strlen(паки_суфікс);

  *вихід_розміру = розмір_шляху + довжина_суфікса;
  *вихід_даних = (п8*)пристрій_мавки_виділити_сиру_памʼять(*вихід_розміру);
  if (!*вихід_даних) {
    return false;
  }

  for (природне і = 0; і < розмір_шляху; і++) {
    (*вихід_даних)[і] = дані_шляху[і];
  }
  for (природне і = 0; і < довжина_суфікса; і++) {
    (*вихід_даних)[розмір_шляху + і] = (п8)паки_суфікс[і];
  }

  return true;
}

extern логічне пристрій_мавки_отримати_назву_модуля_з_шляху_ю8(
    природне розмір_шляху,
    п8* дані_шляху,
    природне* вихід_розміру,
    п8** вихід_даних) {
  char* шлях_рядок =
      (char*)пристрій_мавки_виділити_сиру_памʼять(розмір_шляху + 1);
  for (природне і = 0; і < розмір_шляху; і++) {
    шлях_рядок[і] = (char)дані_шляху[і];
  }
  шлях_рядок[розмір_шляху] = '\0';

  char* шлях_копія = strdup(шлях_рядок);
  char* назва = basename(шлях_копія);

  const char* суфікс = ".м";
  природне довжина_суфікса = strlen(суфікс);
  природне довжина = strlen(назва);

  if (довжина >= довжина_суфікса) {
    логічне має_суфікс = true;
    for (природне і = 0; і < довжина_суфікса; і++) {
      if (назва[довжина - довжина_суфікса + і] != суфікс[і]) {
        має_суфікс = false;
        break;
      }
    }
    if (має_суфікс) {
      довжина -= довжина_суфікса;
    }
  }

  п8* назва_ю8 = (п8*)пристрій_мавки_виділити_сиру_памʼять(довжина);
  for (природне і = 0; і < довжина; і++) {
    назва_ю8[і] = (п8)назва[і];
  }

  *вихід_розміру = довжина;
  *вихід_даних = назва_ю8;

  пристрій_мавки_звільнити_сиру_памʼять(шлях_рядок);
  пристрій_мавки_звільнити_сиру_памʼять(шлях_копія);
  return true;
}

extern логічне пристрій_мавки_збити_шлях_до_модуля(
    природне кількість_елементів,
    ЕлементШляхуПристроюМавки* елементи,
    природне* вихід_розміру,
    п8** вихід_даних) {
  const char* суфікс = ".м";

  природне загальний_розмір = кількість_елементів - 1 + strlen(суфікс);

  for (природне і = 0; і < кількість_елементів; і++) {
    загальний_розмір += елементи[і].розмір;
  }

  *вихід_розміру = загальний_розмір;
  *вихід_даних = (п8*)пристрій_мавки_виділити_сиру_памʼять(загальний_розмір);
  if (!*вихід_даних) {
    return false;
  }

  природне позиція = 0;
  for (природне і = 0; і < кількість_елементів; і++) {
    memcpy(*вихід_даних + позиція, елементи[і].дані, елементи[і].розмір);
    позиція += елементи[і].розмір;
    if (і < кількість_елементів - 1) {
      (*вихід_даних)[позиція++] = '/';
    }
  }

  for (природне і = 0; і < strlen(суфікс); і++) {
    (*вихід_даних)[позиція++] = (п8)суфікс[і];
  }

  return true;
}

extern логічне пристрій_мавки_перевірити_чи_шлях_починається_на(
    природне розмір_шляху,
    п8* дані_шляху,
    природне розмір_початку,
    п8* дані_початку) {
  if (розмір_початку > розмір_шляху) {
    return false;
  }

  for (природне і = 0; і < розмір_початку; і++) {
    if (дані_шляху[і] != дані_початку[і]) {
      return false;
    }
  }

  return true;
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
    return false;
  }

  // Verify that the module path starts with the packages path
  for (природне і = 0; і < розмір_шляху_до_паків; і++) {
    if (дані_шляху[і] != дані_шляху_до_паків[і]) {
      return false;
    }
  }

  // Find the next '/' after the packages path to get the package directory
  природне позиція_наступного_слешу = 0;
  логічне знайдено = false;

  // Skip the packages path and any immediate '/'
  природне початок = розмір_шляху_до_паків;
  if (початок < розмір_шляху && дані_шляху[початок] == '/') {
    початок++;
  }

  // Find the next '/' which marks the end of the package name
  for (природне і = початок; і < розмір_шляху; і++) {
    if (дані_шляху[і] == '/') {
      позиція_наступного_слешу = і; // Don't include the trailing slash
      знайдено = true;
      break;
    }
  }

  if (!знайдено) {
    позиція_наступного_слешу = розмір_шляху;
  }

  // Return the path up to but not including the trailing slash
  *вихід_розміру = позиція_наступного_слешу;
  *вихід_даних = (п8*)пристрій_мавки_виділити_сиру_памʼять(*вихід_розміру);
  if (!*вихід_даних) {
    return false;
  }

  for (природне і = 0; і < позиція_наступного_слешу; і++) {
    (*вихід_даних)[і] = дані_шляху[і];
  }

  return true;
}