#if defined(__linux__)
#include <dlfcn.h>
#endif
#include <cmath>
#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <locale>

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
#define адреса_позитивне позитивне*
#define так true
#define ні false
#define пусто nullptr

extern "C" логічне мавка_система_фс_прочитати_файл(
    памʼять_п8 шлях,
    позитивне розмір_шляху,
    адреса_памʼять_п8 вихід,
    адреса_позитивне вихід_розміру) {
  char* path =
      strdup(std::string(reinterpret_cast<char*>(шлях), розмір_шляху).c_str());
  FILE* file = fopen(path, "rb");
  free(path);
  if (file == nullptr) {
    return false;
  }
  fseek(file, 0, SEEK_END);
  auto length = ftell(file);
  fseek(file, 0, SEEK_SET);
  auto buffer = (char*)malloc(length);
  fread(buffer, 1, length, file);
  fclose(file);
  *вихід = reinterpret_cast<памʼять_п8>(buffer);
  *вихід_розміру = length;
  return true;
}

extern "C" логічне мавка_система_фс_виправити_шлях_та_зробити_абсолютним(
    памʼять_п8 шлях,
    позитивне розмір_шляху,
    адреса_памʼять_п8 вихід,
    адреса_позитивне вихід_розміру) {
  std::string path(reinterpret_cast<char*>(шлях), розмір_шляху);
  std::filesystem::path p(path);
  std::string fp = absolute(weakly_canonical(p)).string();
  *вихід = reinterpret_cast<памʼять_п8>(strdup(fp.c_str()));
  *вихід_розміру = fp.size();
  return true;
}

extern "C" логічне мавка_система_фс_виправити_шлях_та_отримати_батьківський(
    памʼять_п8 шлях,
    позитивне розмір_шляху,
    адреса_памʼять_п8 вихід,
    адреса_позитивне вихід_розміру) {
  std::string path(reinterpret_cast<char*>(шлях), розмір_шляху);
  std::filesystem::path p(path);
  std::string fp = absolute(weakly_canonical(p.parent_path())).string();
  *вихід = reinterpret_cast<памʼять_п8>(strdup(fp.c_str()));
  *вихід_розміру = fp.size();
  return true;
}

extern "C" логічне мавка_система_фс_отримати_назву_файла_без_розширення(
    памʼять_п8 шлях,
    позитивне розмір_шляху,
    адреса_памʼять_п8 вихід,
    адреса_позитивне вихід_розміру) {
  std::string path(reinterpret_cast<char*>(шлях), розмір_шляху);
  std::filesystem::path p(path);
  std::string value = p.filename().stem().string();
  *вихід = reinterpret_cast<памʼять_п8>(strdup(value.c_str()));
  *вихід_розміру = value.size();
  return true;
}

extern "C" {
#include <stdlib.h>
#if MAVKA_READLINE == 1
#include <readline/readline.h>

char* _mavka_readline(char* prefix) {
  return readline(prefix);
}
#else
char* _mavka_readline(char* prefix) {
  std::cout << prefix;
  std::string line;
  if (std::cin.eof()) {
    return nullptr;
  }
  std::getline(std::cin, line);
  return strdup(line.c_str());
}
#endif
}

extern "C" логічне мавка_система_прочитати_зі_стандартного_вводу(
    памʼять_п8 префікс,
    позитивне розмір_префіксу,
    адреса_памʼять_п8 вихід,
    адреса_позитивне вихід_розміру) {
  char* prefix = strdup(
      std::string(reinterpret_cast<char*>(префікс), розмір_префіксу).c_str());
  char* value = _mavka_readline(prefix);
  if (value == nullptr) {
    return false;
  }
  *вихід = reinterpret_cast<памʼять_п8>(value);
  *вихід_розміру = strlen(value);
  return true;
}

extern "C" невідома_адреса мавка_система_відкрити_поширену_бібліотеку(
    памʼять_п8 шлях,
    позитивне розмір_шляху) {
#if defined(__linux__)
  char* path =
      strdup(std::string(reinterpret_cast<char*>(шлях), розмір_шляху).c_str());
  void* dobject = dlopen(path, RTLD_LAZY);
  free(path);
  return dobject;
#else
  return nullptr;
#endif
}

extern "C" ніщо мавка_система_закрити_поширену_бібліотеку(
    невідома_адреса поширена_бібліотека) {
#if defined(__linux__)
  dlclose(поширена_бібліотека);
#endif
}

extern "C" невідома_адреса мавка_система_отримати_символ_поширеної_бібліотеки(
    невідома_адреса поширена_бібліотека,
    памʼять_п8 назва_символа,
    позитивне розмір_назви_символа) {
#if defined(__linux__)
  char* name = strdup(
      std::string(reinterpret_cast<char*>(назва_символа), розмір_назви_символа)
          .c_str());
  void* sym = dlsym(поширена_бібліотека, name);
  free(name);
  return sym;
#else
  return nullptr;
#endif
}

extern "C" д64 мавка_математика_синус_д64(д64 значення) {
  return sin(значення);
}

extern "C" д64 мавка_математика_косинус_д64(д64 значення) {
  return cos(значення);
}

extern "C" д64 мавка_математика_тангенс_д64(д64 значення) {
  return tan(значення);
}

extern "C" д64 мавка_математика_арксинус_д64(д64 значення) {
  return asin(значення);
}

extern "C" д64 мавка_математика_арккосинус_д64(д64 значення) {
  return acos(значення);
}

extern "C" д64 мавка_математика_арктангенс_д64(д64 значення) {
  return atan(значення);
}

extern "C" д64 мавка_математика_арктангенс2_д64(д64 а, д64 б) {
  return atan2(а, б);
}

extern "C" д64 мавка_математика_абсолютне_д64(д64 значення) {
  return abs(значення);
}

extern "C" д64 мавка_математика_експонента_д64(д64 значення) {
  return exp(значення);
}

extern "C" д64 мавка_математика_корінь_д64(д64 значення) {
  return sqrt(значення);
}

extern "C" д64 мавка_математика_степінь_д64(д64 а, д64 б) {
  return pow(а, б);
}

extern "C" д64 мавка_математика_стеля_д64(д64 значення) {
  return ceil(значення);
}

extern "C" д64 мавка_математика_підлога_д64(д64 значення) {
  return floor(значення);
}

extern "C" size_t mavka_double_to_string(double value, char** buffer) {
  long decimal = (long)value;
  if (decimal == value) {
    *buffer = (char*)malloc(32);
    return sprintf((char*)*buffer, "%ld", decimal);
  }
  *buffer = (char*)malloc(32);
  return sprintf((char*)*buffer, "%.14f", value);
}

extern "C" д64 мавка_математика_округлити_д64(д64 значення) {
  return round(значення);
}

extern "C" памʼять_п8 мавка_система_виділити_сиру_памʼять(позитивне розмір) {
  return reinterpret_cast<памʼять_п8>(malloc(розмір));
}

extern "C" памʼять_п8 мавка_система_певиділити_сиру_памʼять(
    памʼять_п8 значення,
    позитивне новий_розмір) {
  return reinterpret_cast<памʼять_п8>(realloc(значення, новий_розмір));
}

extern "C" ніщо мавка_система_звільнити_сиру_памʼять(памʼять_п8 значення) {
  free(значення);
}

extern "C" void мавка_система_процес_вийти(ц32 код) {
  exit(код);
}

extern "C" void мавка_система_вв_вивести_в_стандартний_вивід(
    памʼять_п8 значення,
    позитивне розмір_значення) {
  printf("%.*s", static_cast<int>(розмір_значення), значення);
}

extern "C" int стартувати_мавку(int argc, unsigned char** argv);

#if defined(__linux__) || defined(__APPLE__)
int main(int argc, char** argv) {
  return стартувати_мавку(argc, reinterpret_cast<unsigned char**>(argv));
}
#endif

#ifdef _WIN32
#include <windows.h>

int wmain(int argc, wchar_t** argv) {
  int argc8 = 0;
  unsigned char** argv8 = new unsigned char*[argc];
  for (int i = 0; i < argc; i++) {
    int len = WideCharToMultiByte(CP_UTF8, 0, argv[i], -1, NULL, 0, NULL, NULL);
    argv8[i] = new unsigned char[len];
    WideCharToMultiByte(CP_UTF8, 0, argv[i], -1, (char*)argv8[i], len, NULL,
                        NULL);
    argc8++;
  }
  int ret = стартувати_мавку(argc8, argv8);
  for (int i = 0; i < argc; i++) {
    delete[] argv8[i];
  }
  delete[] argv8;
  return ret;
}
#endif