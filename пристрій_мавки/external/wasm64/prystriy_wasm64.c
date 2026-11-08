#include "../include/mavka/prystriy.h"
#include "./galloc.c"

void* pristriy_mavky_malloc(size_t size) {
  return malloc(size);
}

void* pristriy_mavky_realloc(void* value, size_t new_size) {
  return realloc(value, new_size);
}

void pristriy_mavky_free(void* value) {
  free(value);
}