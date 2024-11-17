// наразі змушені використовувати точку входу з C++
// так як Ціль ще не дуже може зробити те що треба на Windows

extern "C" int стартувати_мавку(int argc, unsigned char** argv);

int main(int argc, char** argv) {
  return стартувати_мавку(argc, reinterpret_cast<unsigned char**>(argv));
}