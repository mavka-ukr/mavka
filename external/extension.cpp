#include <codecvt>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#endif

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
#ifdef _WIN32
  auto len = strlen((char*)value);
  auto value16 = (unsigned short int*)malloc((len + 1) * 2);
  // encode to utf16
  auto outlen = MultiByteToWideChar(CP_UTF8, 0, (char*)value, len,
                                    (wchar_t*)value16, len);
  value16[outlen] = 0;
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), value16,
                wcslen((wchar_t*)value16), NULL, NULL);
#else
  printf("%s", (char*)value);
#endif
}

extern "C" void mama_println_utf8(unsigned char* value) {
#ifdef _WIN32
  auto len = strlen((char*)value);
  auto value16 = (unsigned short int*)malloc((len + 1) * 2);
  // encode to utf16
  auto outlen = MultiByteToWideChar(CP_UTF8, 0, (char*)value, len,
                                    (wchar_t*)value16, len);
  value16[outlen] = 0;
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), value16,
                wcslen((wchar_t*)value16), NULL, NULL);
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"\n", 1, NULL, NULL);
#else
  printf("%s\n", (char*)value);
#endif
}