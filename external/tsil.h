#ifdef _WIN32

#include <windows.h>

typedef BOOL логічне;
typedef UINT8 п8;
typedef UINT16 п16;
typedef UINT32 п32;
typedef UINT64 п64;
typedef INT32 ц32;
typedef INT64 ц64;
typedef double д64;
typedef SIZE_T природне;

#else

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef bool логічне;
typedef uint8_t п8;
typedef uint16_t п16;
typedef uint32_t п32;
typedef uint64_t п64;
typedef int32_t ц32;
typedef int64_t ц64;
typedef double д64;
typedef size_t природне;

#endif

typedef struct ю8 ю8;

struct ю8 {
  природне розмір;
  п8* дані;
};

extern ц32 старт(природне кількість_аргументів, ю8* аргументи);