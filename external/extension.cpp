#include <dlfcn.h>
#include <cmath>
#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <locale>

extern "C" unsigned char* mavka_read_file(unsigned char* шлях) {
  FILE* file = fopen((char*)шлях, "rb");
  if (file == nullptr) {
    return nullptr;
  }
  fseek(file, 0, SEEK_END);
  auto length = ftell(file);
  fseek(file, 0, SEEK_SET);
  auto buffer = (unsigned char*)malloc(length + 1);
  fread(buffer, 1, length, file);
  fclose(file);
  buffer[length] = 0;
  return buffer;
}

extern "C" void mavka_fix_path(unsigned char* шлях, unsigned char** вихід) {
  std::string path = (char*)шлях;
  std::filesystem::path p(path);
  *вихід =
      (unsigned char*)strdup(absolute(weakly_canonical(p)).string().c_str());
}

extern "C" unsigned char mavka_check_if_str_ends_with(unsigned char* value,
                                                      unsigned char* suffix) {
  std::string str = (char*)value;
  std::string suf = (char*)suffix;
  return str.ends_with(suf);
}

extern "C" void mavka_get_filename_without_extension(unsigned char* шлях,
                                                     unsigned char** вихід) {
  std::string path = (char*)шлях;
  std::filesystem::path p(path);
  *вихід = (unsigned char*)strdup(p.stem().string().c_str());
}

extern "C" int strcmp32(char32_t* a, char32_t* b) {
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;
  std::u32string ua = a;
  std::u32string ub = b;
  return strcmp(utf32conv.to_bytes(ua).c_str(), utf32conv.to_bytes(ub).c_str());
}

extern "C" int strlen32(char32_t* a) {
  int len = 0;
  while (a[len] != 0) {
    len++;
  }
  return len;
}

extern "C" uint64_t mavka_read_from_stdin(char* prefix, char** output) {
  std::cout << prefix;
  std::string line;
  if (std::cin.eof()) {
    return 0;
  }
  std::getline(std::cin, line);
  *output = strdup(line.c_str());
  return line.size();
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
  std::getline(std::cin, line);
  return strdup(line.c_str());
}
#endif

void _mavka_readline_init() {
  //
}

void mavka_dialog(void* data, void (*run)(void* data, unsigned char* value)) {
  _mavka_readline_init();
  unsigned char* input;
  char* prefix = strdup("- ");
  while ((input = (unsigned char*)_mavka_readline(prefix)) != nullptr) {
    run(data, input);
    free(input);
  }
  free(prefix);
}
}

extern "C" size_t mavka_get_path_directory(unsigned char* path,
                                           unsigned char** output) {
  std::string str = (char*)path;
  std::filesystem::path p(str);
  *output = (unsigned char*)strdup(p.parent_path().string().c_str());
  return strlen((char*)*output);
}

extern "C" void* mavka_load_shared_object_function_ptr_from_file(
    unsigned char* path,
    unsigned char* name) {
  void* dobject = dlopen((char*)path, RTLD_LAZY);
  if (dobject == nullptr) {
    if (auto err = dlerror()) {
      std::cout << err << std::endl;
    }
    return nullptr;
  }
  void* extfptr = dlsym(dobject, (char*)name);
  if (extfptr == nullptr) {
    if (auto err = dlerror()) {
      std::cout << err << std::endl;
    }
    return nullptr;
  }
  return extfptr;
}

extern "C" double mavka_sin(double value) {
  return sin(value);
}

extern "C" double mavka_cos(double value) {
  return cos(value);
}

extern "C" double mavka_tan(double value) {
  return tan(value);
}

extern "C" double mavka_asin(double value) {
  return asin(value);
}

extern "C" double mavka_acos(double value) {
  return acos(value);
}

extern "C" double mavka_atan(double value) {
  return atan(value);
}

extern "C" double mavka_atan2(double y, double x) {
  return atan2(y, x);
}

extern "C" double mavka_abs(double value) {
  return abs(value);
}

extern "C" double mavka_exp(double value) {
  return exp(value);
}

extern "C" double mavka_sqrt(double value) {
  return sqrt(value);
}

extern "C" double mavka_pow(double a, double b) {
  return pow(a, b);
}

extern "C" double mavka_ceil(double value) {
  return ceil(value);
}

extern "C" double mavka_floor(double value) {
  return floor(value);
}

extern "C" double mavka_round(double value) {
  return round(value);
}

extern "C" void* mavka_malloc(size_t size) {
  return malloc(size);
}

extern "C" void* mavka_realloc(void* ptr, size_t size) {
  return realloc(ptr, size);
}

extern "C" void mavka_free(void* ptr) {
  free(ptr);
}

extern double mavka_exit(int value) {
  exit(value);
}

extern "C" void mavka_get_version(unsigned char** output, size_t* length) {
  *output = (unsigned char*)strdup(MAVKA_VERSION);
  if (length != nullptr) {
    *length = strlen(MAVKA_VERSION);
  }
}