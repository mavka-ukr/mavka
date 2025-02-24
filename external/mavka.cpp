#if defined(__linux__)
#include <dlfcn.h>
#endif
#include <cmath>
#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#include <cwchar>
#endif

#ifdef _WIN32
std::wstring UTF8StringToWString(const std::string& utf8Str) {
  int sizeNeeded =
      MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, nullptr, 0);
  std::wstring utf16Str(sizeNeeded, 0);
  MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, &utf16Str[0],
                      sizeNeeded);
  return utf16Str;
}
#endif

extern "C" {
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

логічне мавка_система_фс_прочитати_файл(памʼять_п8 шлях,
                                        позитивне розмір_шляху,
                                        адреса_памʼять_п8 вихід,
                                        адреса_позитивне вихід_розміру) {
  auto p = std::filesystem::u8path(
      std::string(reinterpret_cast<char*>(шлях), розмір_шляху));
  if (!std::filesystem::exists(p)) {
    return false;
  }
  std::ifstream ifs(p, std::ios::binary);
  if (!ifs) {
    return false;
  }
  ifs.seekg(0, std::ios::end);
  auto size = ifs.tellg();
  ifs.seekg(0, std::ios::beg);
  auto data = new п8[size];
  ifs.read(reinterpret_cast<char*>(data), size);
  *вихід = data;
  *вихід_розміру = size;
  return true;
}

логічне мавка_система_фс_виправити_шлях_та_зробити_абсолютним(
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

логічне мавка_система_фс_виправити_шлях_та_отримати_батьківський(
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

логічне мавка_система_фс_отримати_назву_файла_без_розширення(
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

невідома_адреса мавка_система_відкрити_поширену_бібліотеку(
    памʼять_п8 шлях,
    позитивне розмір_шляху) {
#if defined(__linux__)
  char* path =
      strdup(std::string(reinterpret_cast<char*>(шлях), розмір_шляху).c_str());
  void* dobject = dlopen(path, RTLD_LAZY);
  free(path);
  return dobject;
#elif defined(_WIN32)
  wchar_t* path = new wchar_t[розмір_шляху];
  mbstowcs(path, reinterpret_cast<char*>(шлях), розмір_шляху);
  HMODULE dobject = LoadLibraryW(path);
  delete[] path;
  return dobject;
#else
  return nullptr;
#endif
}

ніщо мавка_система_закрити_поширену_бібліотеку(
    невідома_адреса поширена_бібліотека) {
#if defined(__linux__)
  dlclose(поширена_бібліотека);
#elif defined(_WIN32)
  FreeLibrary(reinterpret_cast<HMODULE>(поширена_бібліотека));
#endif
}

невідома_адреса мавка_система_отримати_символ_поширеної_бібліотеки(
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
#elif defined(_WIN32)
  char* name = strdup(
      std::string(reinterpret_cast<char*>(назва_символа), розмір_назви_символа)
          .c_str());
  auto sym = (void*)GetProcAddress(
      reinterpret_cast<HMODULE>(поширена_бібліотека), name);
  free(name);
  return sym;
#else
  return nullptr;
#endif
}

д64 мавка_математика_синус_д64(д64 значення) {
  return sin(значення);
}

д64 мавка_математика_косинус_д64(д64 значення) {
  return cos(значення);
}

д64 мавка_математика_тангенс_д64(д64 значення) {
  return tan(значення);
}

д64 мавка_математика_арксинус_д64(д64 значення) {
  return asin(значення);
}

д64 мавка_математика_арккосинус_д64(д64 значення) {
  return acos(значення);
}

д64 мавка_математика_арктангенс_д64(д64 значення) {
  return atan(значення);
}

д64 мавка_математика_арктангенс2_д64(д64 а, д64 б) {
  return atan2(а, б);
}

д64 мавка_математика_абсолютне_д64(д64 значення) {
  return fabs(значення);
}

д64 мавка_математика_експонента_д64(д64 значення) {
  return exp(значення);
}

д64 мавка_математика_корінь_д64(д64 значення) {
  return sqrt(значення);
}

д64 мавка_математика_степінь_д64(д64 а, д64 б) {
  return pow(а, б);
}

д64 мавка_математика_стеля_д64(д64 значення) {
  return ceil(значення);
}

д64 мавка_математика_підлога_д64(д64 значення) {
  return floor(значення);
}

д64 мавка_математика_остача_від_ділення_д64(д64 а, д64 б) {
  return fmod(а, б);
}

логічне мавка_допоміжне_перетворити_д64_в_ю8(д64 значення,
                                             адреса_памʼять_п8 вихід,
                                             адреса_позитивне вихід_розміру) {
  long decimal = (long)значення;
  if (decimal == значення) {
    auto value = (char*)malloc(32);
    auto valueSize = sprintf(value, "%ld", decimal);
    *вихід = reinterpret_cast<памʼять_п8>(value);
    *вихід_розміру = valueSize;
    return true;
  }
  auto value = (char*)malloc(32);
  auto valueSize = sprintf(value, "%.14f", значення);
  *вихід = reinterpret_cast<памʼять_п8>(value);
  *вихід_розміру = valueSize;
  return true;
}

д64 мавка_математика_округлити_д64(д64 значення) {
  return round(значення);
}

памʼять_п8 мавка_система_виділити_сиру_памʼять(позитивне розмір) {
  return reinterpret_cast<памʼять_п8>(malloc(розмір));
}

памʼять_п8 мавка_система_певиділити_сиру_памʼять(памʼять_п8 значення,
                                                 позитивне новий_розмір) {
  return reinterpret_cast<памʼять_п8>(realloc(значення, новий_розмір));
}

ніщо мавка_система_звільнити_сиру_памʼять(памʼять_п8 значення) {
  free(значення);
}

void мавка_система_процес_вийти(ц32 код) {
  exit(код);
}

void мавка_система_вв_вивести_в_стандартний_вивід(памʼять_п8 значення,
                                                  позитивне розмір_значення) {
  printf("%.*s", static_cast<int>(розмір_значення), значення);
}

void мавка_система_вв_вивести_ю8_в_стандартний_вивід(
    памʼять_п8 значення,
    позитивне розмір_значення) {
#ifdef _WIN32
  std::string value(reinterpret_cast<char*>(значення), розмір_значення);
  std::wstring value16 = UTF8StringToWString(value);
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), value16.c_str(),
                lstrlenW(value16.c_str()), 0, NULL);
#else
  printf("%.*s", static_cast<int>(розмір_значення), значення);
#endif
}

#if MAVKA_READLINE == 1
#include <readline/readline.h>

char* _mavka_readline(char* prefix) {
  return readline(prefix);
}
#else
char* _mavka_readline(char* prefix) {
  мавка_система_вв_вивести_ю8_в_стандартний_вивід(
      reinterpret_cast<памʼять_п8>(prefix), strlen(prefix));
  std::string line;
  if (std::cin.eof()) {
    return nullptr;
  }
  std::getline(std::cin, line);
  return strdup(line.c_str());
}
#endif

логічне мавка_система_прочитати_зі_стандартного_вводу(
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

int стартувати_мавку(int argc, unsigned char** argv);
}

#if defined(__linux__) || defined(__APPLE__)
int main(int argc, char** argv) {
  return стартувати_мавку(argc, reinterpret_cast<unsigned char**>(argv));
}
#endif

#ifdef _WIN32
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