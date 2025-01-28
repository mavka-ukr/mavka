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

extern "C" char* mavka_read_file(char* шлях,
                                 size_t розмір_шляху,
                                 size_t* buffer_size) {
  char* path = (char*)malloc(розмір_шляху + 1);
  memcpy(path, шлях, розмір_шляху);
  path[розмір_шляху] = 0;
  FILE* file = fopen(path, "rb");
  free(path);
  if (file == nullptr) {
    return nullptr;
  }
  fseek(file, 0, SEEK_END);
  auto length = ftell(file);
  fseek(file, 0, SEEK_SET);
  auto buffer = (char*)malloc(length + 1);
  fread(buffer, 1, length, file);
  fclose(file);
  buffer[length] = 0;
  *buffer_size = length;
  return buffer;
}

extern "C" char* mavka_fix_path(char* шлях,
                                size_t розмір_шляху,
                                size_t* buffer_size) {
  std::string path = (char*)шлях;
  std::filesystem::path p(path);
  char* fixed_path = strdup(absolute(weakly_canonical(p)).string().c_str());
  *buffer_size = strlen(fixed_path);
  return fixed_path;
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

void mavka_dialog(void* data,
                  void (*run)(void* data, char* value, size_t value_size)) {
  _mavka_readline_init();
  char* input;
  char* prefix = strdup("- ");
  while ((input = _mavka_readline(prefix)) != nullptr) {
    run(data, input, strlen(input));
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
#if defined(__linux__)
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
#else
  return nullptr;
#endif
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

extern "C" void mavka_exit(int value) {
  exit(value);
}

extern "C" void mavka_print_utf8(char* value, size_t length) {
  printf("%.*s", (int)length, value);
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

extern "C" double mavka_bitnot(double value) {
  long int_value = static_cast<long>(value);
  return static_cast<double>(~int_value);
}

extern "C" double mavka_negate(double value) {
  return -value;
}
