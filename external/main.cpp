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