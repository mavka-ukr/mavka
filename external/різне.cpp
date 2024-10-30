#include <stdint.h>
#include <string.h>
#include <codecvt>
#include <filesystem>
#include <string>
#include <vector>

extern "C" unsigned char* ю32_в_ю8(char32_t* u32) {
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;
  std::u32string utf32 = u32;
  return (unsigned char*)strdup(utf32conv.to_bytes(utf32).c_str());
}

extern "C" size_t довжина_ю32(char32_t* u32) {
  size_t i = 0;
  while (u32[i] != 0) {
    i++;
  }
  return i;
}

extern "C" uint8_t ю32_містить(char32_t* u32, char32_t* u322) {
  std::u32string u32s = u32;
  std::u32string u322s = u322;
  return u32s.find(u322s) != std::u32string::npos;
}

extern "C" char32_t** ю32_розбити(char32_t* u32, char32_t* u322) {
  std::u32string u32s = u32;
  std::u32string u322s = u322;
  if (u322s.empty()) {
    char32_t** retc = new char32_t*[u32s.size() + 1];
    for (size_t i = 0; i < u32s.size(); i++) {
      retc[i] = new char32_t[2];
      retc[i][0] = u32s[i];
      retc[i][1] = 0;
    }
    retc[u32s.size()] = 0;
    return retc;
  }
  std::vector<std::u32string> ret;
  size_t last = 0;
  size_t next = 0;
  while ((next = u32s.find(u322s, last)) != std::u32string::npos) {
    ret.push_back(u32s.substr(last, next - last));
    last = next + 1;
  }
  ret.push_back(u32s.substr(last));
  char32_t** retc = new char32_t*[ret.size() + 1];
  for (size_t i = 0; i < ret.size(); i++) {
    retc[i] = new char32_t[ret[i].size() + 1];
    for (size_t j = 0; j < ret[i].size(); j++) {
      retc[i][j] = ret[i][j];
    }
    retc[i][ret[i].size()] = 0;
  }
  retc[ret.size()] = 0;
  return retc;
}

extern "C" char32_t* ю32_клонувати(char32_t* u32) {
  std::u32string u32s = u32;
  char32_t* u32c = new char32_t[u32s.size() + 1];
  for (size_t i = 0; i < u32s.size(); i++) {
    u32c[i] = u32s[i];
  }
  u32c[u32s.size()] = 0;
  return u32c;
}

extern "C" char32_t* ю32_замінити(char32_t* u32,
                                  char32_t* u322,
                                  char32_t* u323) {
  std::u32string u32s = u32;
  std::u32string u322s = u322;
  std::u32string u323s = u323;
  if (u322s.empty()) {
    return ю32_клонувати(u32);
  }
  std::u32string ret;
  size_t last = 0;
  size_t next = 0;
  while ((next = u32s.find(u322s, last)) != std::u32string::npos) {
    ret += u32s.substr(last, next - last);
    ret += u323s;
    last = next + u322s.size();
  }
  ret += u32s.substr(last);
  return ю32_клонувати((char32_t*)ret.c_str());
}

extern "C" uint8_t ю32_починається_з(char32_t* u32, char32_t* u322) {
  std::u32string u32s = u32;
  std::u32string u322s = u322;
  return u32s.find(u322s) == 0;
}

extern "C" uint8_t ю32_закінчується_на(char32_t* u32, char32_t* u322) {
  std::u32string u32s = u32;
  std::u32string u322s = u322;
  return u32s.rfind(u322s) == u32s.size() - u322s.size();
}

extern "C" char32_t* ю32_обтяти(char32_t* u32) {
  std::u32string u32s = u32;
  if (u32s.empty()) {
    return ю32_клонувати(u32);
  }
  while (!u32s.empty() &&
         (u32s[0] == ' ' || u32s[0] == '\n' || u32s[0] == '\t')) {
    u32s = u32s.substr(1);
  }
  while (!u32s.empty() &&
         (u32s[u32s.size() - 1] == ' ' || u32s[u32s.size() - 1] == '\n' ||
          u32s[u32s.size() - 1] == '\t')) {
    u32s = u32s.substr(0, u32s.size() - 1);
  }
  return ю32_клонувати((char32_t*)u32s.c_str());
}

extern "C" char32_t* ю32_зʼєднати(char32_t* u32, char32_t* u322) {
  std::u32string u32s = u32;
  std::u32string u322s = u322;
  return ю32_клонувати((char32_t*)(u32s + u322s).c_str());
}

extern "C" uint8_t ю8_починається_з(unsigned char* u8, unsigned char* u82) {
  std::string u8s = (char*)u8;
  std::string u82s = (char*)u82;
  return u8s.find(u82s) == 0;
}

extern "C" uint8_t ю8_закінчується_на(unsigned char* u8, unsigned char* u82) {
  std::string u8s = (char*)u8;
  std::string u82s = (char*)u82;
  return u8s.rfind(u82s) == u8s.size() - u82s.size();
}

extern "C" unsigned char* ю8_зріз(unsigned char* u8, size_t from, size_t size) {
  std::string u8s = (char*)u8;
  if (size == 0) {
    return (unsigned char*)strdup(u8s.substr(from).c_str());
  }
  return (unsigned char*)strdup(u8s.substr(from, size).c_str());
}

extern "C" size_t ю8_розмір(unsigned char* u8) {
  std::string u8s = (char*)u8;
  return u8s.size();
}

extern "C" unsigned char* ю8_клонувати(unsigned char* value) {
  std::string str = (char*)value;
  return (unsigned char*)strdup(str.c_str());
}