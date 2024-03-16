#include "./mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

void do_something(Mavka* mavka) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavka->version << std::endl;
}

extern "C" MavkaValue мавка_розширити(Mavka* mavka) {
  do_something(mavka);
  const auto testDiia = mavka->createDiia(
      mavka, "вернути_так",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        return MavkaValue{MavkaValueTypeYes, {}};
      });
  return MavkaValue{MavkaValueTypeObject, {.object = testDiia}};
}