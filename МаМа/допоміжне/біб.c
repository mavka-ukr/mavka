#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern unsigned char *mama_convert_utf32_to_utf8(unsigned int *utf32) {
  unsigned long len = 0;
  while (utf32[len] != 0) {
    len++;
  }
  unsigned char *utf8 = (unsigned char *)malloc(len * 4 + 1);
  unsigned char *utf8_start = utf8;
  for (int i = 0; i < len; i++) {
    unsigned int c = utf32[i];
    if (c < 0x80) {
      *utf8++ = c;
    } else if (c < 0x800) {
      *utf8++ = 0xC0 | c >> 6;
      *utf8++ = 0x80 | (c & 0x3F);
    } else if (c < 0x10000) {
      *utf8++ = 0xE0 | c >> 12;
      *utf8++ = 0x80 | (c >> 6 & 0x3F);
      *utf8++ = 0x80 | (c & 0x3F);
    } else {
      *utf8++ = 0xF0 | c >> 18;
      *utf8++ = 0x80 | (c >> 12 & 0x3F);
      *utf8++ = 0x80 | (c >> 6 & 0x3F);
      *utf8++ = 0x80 | (c & 0x3F);
    }
  }
  *utf8 = 0;
  return utf8_start;
}

extern void mama_print_utf8(unsigned char *value) {
  printf("%s", (char *)value);
}

extern void mama_println_utf8(unsigned char *value) {
  printf("%s\n", (char *)value);
}

extern unsigned long mama_bitnot(long value) { return ~value; }

extern double mama_negate(double value) { return -value; }

extern double mama_pow(double base, double exponent) {
  return pow(base, exponent);
}

extern double mama_floor(double value) { return floor(value); }

extern size_t mama_double_to_string(double value, unsigned char **buffer) {
  long decimal = (long)value;
  if (decimal == value) {
    *buffer = (unsigned char *)malloc(32);
    return sprintf((char *)*buffer, "%ld", decimal);
  }
  *buffer = (unsigned char *)malloc(32);
  return sprintf((char *)*buffer, "%.14f", value);
}