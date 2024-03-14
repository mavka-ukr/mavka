#include "include/mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

void do_something(MavkaOptions& mavkaOptions) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavkaOptions.version
            << std::endl;
}

extern "C" MavkaValue мавка_розширити(MavkaOptions mavkaOptions) {
  do_something(mavkaOptions);
  return MavkaValue{1, {.number = 2.0}};
}