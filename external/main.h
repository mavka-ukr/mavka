#include <stddef.h>
#include <stdint.h>

typedef uint8_t п8;
typedef int32_t ц32;
typedef size_t природне;

typedef struct ю8 ю8;

struct ю8 {
  природне розмір;
  п8* дані;
};

extern ц32 старт(природне кількість_аргументів, ю8* аргументи);