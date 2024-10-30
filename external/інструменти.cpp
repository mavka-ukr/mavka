#include <math.h>
#include <string.h>
#include <codecvt>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

unsigned char* strdup(const wchar_t* value) {
  std::wstring str = value;
  return (unsigned char*)strdup(std::string(str.begin(), str.end()).c_str());
}

void replace_all(std::string& str,
                 const std::string& from,
                 const std::string& to) {
  if (from.empty())
    return;
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // In case 'to' contains 'from', like replacing
        // 'x' with 'yx'
  }
}

extern "C" double перетворити_ю8_в_дійсне(unsigned char* value) {
  std::string vs = (char*)value;
  replace_all(vs, "д", "b");
  replace_all(vs, "Д", "b");
  replace_all(vs, "ш", "x");
  replace_all(vs, "Ш", "x");
  replace_all(vs, "А", "А");
  replace_all(vs, "а", "a");
  replace_all(vs, "Б", "B");
  replace_all(vs, "б", "b");
  replace_all(vs, "В", "C");
  replace_all(vs, "в", "c");
  replace_all(vs, "Г", "D");
  replace_all(vs, "г", "d");
  replace_all(vs, "Ґ", "E");
  replace_all(vs, "ґ", "e");
  replace_all(vs, "Д", "F");
  replace_all(vs, "д", "f");
  if (vs.find("x") != std::string::npos) {
    return std::stol(vs, 0, 16);
  }
  if (vs.find("b") != std::string::npos) {
    return std::stol(vs, 0, 2);
  }
  return std::stod(vs);
}

std::wstring utf8_to_utf16(const std::string& utf8) {
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.from_bytes(utf8);
}

extern "C" unsigned char* прочитати_файл(unsigned char* value) {
#ifdef _WIN32
  FILE* file = _wfopen(utf8_to_utf16((char*)value).c_str(), L"r");
#else
  FILE* file = fopen((char*)value, "r");
#endif
  if (file == NULL) {
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);
  unsigned char* buffer = (unsigned char*)malloc(length + 1);
  buffer[length] = '\0';
  fread(buffer, 1, length, file);
  fclose(file);
  return buffer;
}

std::vector<std::string> explode(const std::string& s,
                                 const std::string& delim) {
  std::vector<std::string> ret;
  size_t last = 0;
  size_t next = 0;
  while ((next = s.find(delim, last)) != std::string::npos) {
    ret.push_back(s.substr(last, next - last));
    last = next + 1;
  }
  ret.push_back(s.substr(last));
  return ret;
}

extern "C" size_t довжина_ю8(unsigned char* value) {
  return strlen((char*)value);
}

extern "C" unsigned char* перетворити_позитивне_в_ю8(size_t value) {
  std::string str = std::to_string(value);
  return (unsigned char*)strdup(str.c_str());
}

extern "C" unsigned char* перетворити_дійсне_в_ю8(double value) {
  std::string result;
  double integer;
  double fraction = modf(value, &integer);
  if (fraction == 0) {
    result = std::to_string((long)integer);
  } else {
    result = std::to_string(value);
  }
  return (unsigned char*)strdup(result.c_str());
}

struct ВитнутийРядокДляПомилки {
  unsigned long новий_стовпець;
  unsigned char* значення;
};

std::string unsigned_chars_to_string(unsigned char* value) {
  std::string str;
  size_t i = 0;
  while (value[i] != '\0') {
    str += (char)value[i];
    i++;
  }
  return str;
}

extern "C" unsigned char* повторити_ю8(unsigned char* value,
                                       size_t times,
                                       unsigned char* after) {
  std::string str = (char*)value;
  std::string ret = "";
  for (size_t i = 0; i < times; i++) {
    ret += str;
  }
  ret += (char*)after;
  return (unsigned char*)strdup(ret.c_str());
}

extern "C" unsigned char* зʼєднати_ю8(unsigned char* value,
                                      unsigned char* value2) {
  std::string str = (char*)value;
  std::string str2 = (char*)value2;
  return (unsigned char*)strdup((str + str2).c_str());
}

extern "C" unsigned char* нормалізувати_шлях(unsigned char* path) {
  std::filesystem::path p = (char*)path;
  return (unsigned char*)strdup(
      std::filesystem::weakly_canonical(p).string().c_str());
}

extern "C" unsigned char* отримати_папку_шляху(unsigned char* path) {
  std::filesystem::path p = (char*)path;
  return (unsigned char*)strdup(
      std::filesystem::weakly_canonical(p).parent_path().string().c_str());
}

extern "C" unsigned char* зʼєднати_шлях(unsigned char* path,
                                        unsigned char* path2) {
  std::filesystem::path p =
      std::string((char*)path) +
      std::string(1, std::filesystem::path::preferred_separator) +
      std::string((char*)path2);
  return (unsigned char*)strdup(
      std::filesystem::weakly_canonical(p).string().c_str());
}

extern "C" unsigned char* отримати_назву_файлу(unsigned char* path) {
  std::filesystem::path p = (char*)path;
  return (unsigned char*)strdup(
      std::filesystem::weakly_canonical(p).filename().c_str());
}

extern "C" unsigned char* отримати_назву_файлу_без_розширення(
    unsigned char* path) {
  std::filesystem::path p = (char*)path;
  return (unsigned char*)strdup(
      std::filesystem::weakly_canonical(p).stem().c_str());
}

extern "C" unsigned char* отримати_відносний_шлях(unsigned char* path) {
  std::filesystem::path p = (char*)path;
  return (unsigned char*)strdup(
      std::filesystem::relative(std::filesystem::weakly_canonical(p))
          .string()
          .c_str());
}

extern "C" unsigned char* отримати_шлях_до_папки_запуску() {
  return (unsigned char*)strdup(
      std::filesystem::current_path().string().c_str());
}

extern "C" uint8_t перевірити_чи_файл_існує(unsigned char* path) {
  std::filesystem::path p = (char*)path;
  return std::filesystem::exists(p) && std::filesystem::is_regular_file(p);
}

extern "C" unsigned char* читати_з_входу(unsigned char* prefix) {
  std::cout << prefix;
  std::string str;
  std::getline(std::cin, str);
  if (std::cin.eof()) {
    return nullptr;
  }
  return (unsigned char*)strdup(str.c_str());
}

#ifdef __linux__
#include <dlfcn.h>

extern "C" void* завантажити_динамічну_бібліотеку(unsigned char* path) {
  void* dobject = dlopen((char*)path, RTLD_LAZY);
  if (dobject == nullptr) {
    return nullptr;
  }
  dlerror();
  return dobject;
}

extern "C" void* отримати_символ_з_динамічної_бібліотеки(void* dobject,
                                                         unsigned char* name) {
  void* extfptr = dlsym(dobject, (char*)name);
  if (extfptr == nullptr) {
    return nullptr;
  }
  dlerror();
  return extfptr;
}

extern "C" void* завантажити_динамічну_бібліотеку_як_розширення_мавки(
    unsigned char* path) {
  void* dobject = dlopen((char*)path, RTLD_LAZY);
  if (dobject == nullptr) {
    return nullptr;
  }
  dlerror();
  void* extfptr = dlsym(dobject, "завантажити_розширення_мавки");
  if (extfptr == nullptr) {
    return nullptr;
  }
  dlerror();
  return extfptr;
}
#endif

#ifdef _WIN32
extern "C" void* завантажити_динамічну_бібліотеку(unsigned char* path) {
  return nullptr;
}

extern "C" void* отримати_символ_з_динамічної_бібліотеки(void* dobject,
                                                         unsigned char* name) {
  return nullptr;
}

extern "C" void* завантажити_динамічну_бібліотеку_як_розширення_мавки(
    unsigned char* path) {
  return nullptr;
}
#endif

#ifdef __APPLE__
extern "C" void* завантажити_динамічну_бібліотеку(unsigned char* path) {
  return nullptr;
}

extern "C" void* отримати_символ_з_динамічної_бібліотеки(void* dobject,
                                                         unsigned char* name) {
  return nullptr;
}

extern "C" void* завантажити_динамічну_бібліотеку_як_розширення_мавки(
    unsigned char* path) {
  return nullptr;
}
#endif

extern "C" long двійкове_ні(long value) {
  return ~value;
}