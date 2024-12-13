extern "C" int стартувати_мавку(int argc, unsigned char** argv);

int main(int argc, char** argv) {
  return стартувати_мавку(argc, reinterpret_cast<unsigned char**>(argv));
}