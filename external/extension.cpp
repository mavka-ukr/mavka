#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

extern "C" unsigned char* перетворити_ю32_в_ю8(char32_t* значення) {
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;
  std::u32string utf32 = значення;
  return reinterpret_cast<unsigned char*>(
      strdup(utf32conv.to_bytes(utf32).c_str()));
}
