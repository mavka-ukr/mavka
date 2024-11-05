#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>

extern "C" void* mavka_sysext_malloc(int size) {
  return malloc(size);
}

extern "C" void mavka_sysext_free(void* ptr) {
  free(ptr);
}

extern "C" void* mavka_sysext_realloc(void* ptr, int size) {
  return realloc(ptr, size);
}

extern "C" int mavka_sysext_putchar(unsigned char c) {
  return putchar(c);
}

extern "C" unsigned char* прочитати_файл(unsigned char* шлях) {
  FILE* файл = fopen((char*)шлях, "rb");
  if (файл == NULL) {
    return NULL;
  }
  fseek(файл, 0, SEEK_END);
  long довжина = ftell(файл);
  fseek(файл, 0, SEEK_SET);
  unsigned char* буфер = (unsigned char*)malloc(довжина + 1);
  fread(буфер, 1, довжина, файл);
  fclose(файл);
  буфер[довжина] = 0;
  return буфер;
}

extern "C" char* перетворити_ю32_в_ю8(char32_t* u32) {
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;
  std::u32string utf32 = u32;
  return strdup(utf32conv.to_bytes(utf32).c_str());
}
