#ifndef PRYSTRIY_H
#define PRYSTRIY_H

#include "./numbertypes.h"

#ifndef MAVKA_VERSION
#define MAVKA_VERSION "0.0.0"
#endif

typedef enum PristriyMavkyWriteToStdoutColor {
  PristriyMavkyColorReset = 0,
  PristriyMavkyColorRed = 1,
  PristriyMavkyColorGreen = 2,
  PristriyMavkyColorBlue = 3,
  PristriyMavkyColorYellow = 4,
} PristriyMavkyWriteToStdoutColor;

void* pristriy_mavky_malloc(size_t size);

void* pristriy_mavky_realloc(void* value, size_t new_size);

void pristriy_mavky_free(void* value);

void pristriy_mavky_write_to_stdout(char* data, size_t size);

void pristriy_mavky_write_utf8_to_stdout(PristriyMavkyWriteToStdoutColor color,
                                         char* data,
                                         size_t size);

double pristriy_mavky_double_pow(double value, double exp);

bool pristriy_mavky_uint64_to_str(size_t value,
                                  char** data_out,
                                  size_t* size_out);

bool pristriy_mavky_int64_to_str(ssize_t value,
                                 char** data_out,
                                 size_t* size_out);

bool pristriy_mavky_double_to_str(double value,
                                  char** data_out,
                                  size_t* size_out,
                                  ssize_t* exp_size_out);

bool pristriy_mavky_str_to_double(char* data, size_t size, double* out);

bool pristriy_mavky_get_cwd(char** data_out, size_t* size_out);

bool pristriy_mavky_get_absolute_path(char* path_data,
                                      size_t path_size,
                                      char** data_out,
                                      size_t* size_out);

bool pristriy_mavky_check_if_file_exists(char* path_data, size_t path_size);

bool pristriy_mavky_read_file(char* path_data,
                              size_t path_size,
                              char** data_out,
                              size_t* size_out);

bool pristriy_mavky_read_input_async(
    char* prefix_data,
    size_t prefix_size,
    void (*callback)(char* data, size_t data_size, bool eof, void* arg),
    void* arg,
    bool allow_history);

void pristriy_mavky_exit(int code);

#endif // PRYSTRIY_H