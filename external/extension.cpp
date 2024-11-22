#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <locale>

extern "C" unsigned char* прочитати_файл(unsigned char* шлях) {
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

extern "C" unsigned char* mama_convert_utf32_to_utf8(char32_t* value) {
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;
  std::u32string utf32 = value;
  return reinterpret_cast<unsigned char*>(
      strdup(utf32conv.to_bytes(utf32).c_str()));
}

extern "C" void mama_print_utf8(unsigned char* value) {
  printf("%s", (char*)value);
}

extern "C" void mama_println_utf8(unsigned char* value) {
  printf("%s\n", (char*)value);
}

extern "C" void виправити_шлях(unsigned char* шлях, unsigned char** вихід) {
  std::string path = (char*)шлях;
  std::filesystem::path p(path);
  *вихід =
      (unsigned char*)strdup(absolute(weakly_canonical(p)).string().c_str());
}

extern "C" unsigned char перевірити_чи_ю8_закінчується_на(
    unsigned char* value,
    unsigned char* suffix) {
  std::string str = (char*)value;
  std::string suf = (char*)suffix;
  return str.ends_with(suf);
}

extern "C" void отримати_назву_файлу_без_розширення(unsigned char* шлях,
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

extern "C" char* mavka_read_from_stdin(char* prefix) {
  std::cout << prefix;
  std::string line;
  if (std::cin.eof()) {
    return nullptr;
  }
  std::getline(std::cin, line);
  return strdup(line.c_str());
}

extern "C" unsigned long mama_bitnot(unsigned long value) {
  return ~value;
}

extern "C" double mama_negate(double value) {
  return -value;
}