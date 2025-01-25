#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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