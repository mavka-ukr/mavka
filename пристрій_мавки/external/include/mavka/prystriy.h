#ifndef PRYSTRIY_H
#define PRYSTRIY_H

#include "mavka/tsil.h"

#define КолірВиводуСтандартний 0
#define КолірВиводуЧервоний 1
#define КолірВиводуЗелений 2
#define КолірВиводуСиній 3
#define КолірВиводуЖовтий 4

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

// ---

логічне пристрій_мавки_отримати_версію_як_ю8(п8** вихід_даних,
                                             природне* вихід_розміру);

void пристрій_мавки_вивести_сирі_дані(п8* дані, природне розмір);

void пристрій_мавки_вивести_шлях(природне колір, п8* дані, природне розмір);

void пристрій_мавки_вивести_ю8(природне колір, п8* дані, природне розмір);

адреса пристрій_мавки_виділити(природне розмір);

адреса пристрій_мавки_перевиділити(адреса значення, природне новий_розмір);

void пристрій_мавки_звільнити(адреса значення);

void пристрій_мавки_вийти(ц32 код_виходу);

логічне пристрій_мавки_перекодувати_ю8_в_кд(природне розмір,
                                            п8* дані,
                                            природне* вихід_розміру,
                                            п8** вихід_даних,
                                            природне* вихід_позиції_помилки);

логічне пристрій_мавки_перекодувати_кд_в_ю8(природне розмір,
                                            п8* дані,
                                            природне* вихід_розміру,
                                            п8** вихід_даних,
                                            природне* вихід_позиції_помилки);

#endif // PRYSTRIY_H