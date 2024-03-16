#include "include/mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

void do_something(Mavka* mavkaOptions) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavkaOptions->version
            << std::endl;
}

extern "C" MavkaValue мавка_розширити(Mavka* mavka) {
  do_something(mavka);
  const auto testDiia = mavka->createDiia(
      mavka->mama, "тест",
      [mavka](MavkaPointer mama, MavkaPointer diiaObject, MavkaPointer args,
              size_t li) {
        const auto dict = mavka->createDict(mama);
        mavka->setAt(mama, dict,
                     MavkaValue{MavkaValueTypeNumber, {.number = 0}},
                     MavkaValue{MavkaValueTypeNumber, {.number = 1}});
        return MavkaValue{MavkaValueTypeObject, {.object = dict}};
      });
  return MavkaValue{MavkaValueTypeObject, {.object = testDiia}};
}