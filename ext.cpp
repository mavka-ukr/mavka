#include "include/mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

void do_something(MavkaOptions& mavkaOptions) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavkaOptions.version
            << std::endl;
}

extern "C" MavkaValue мавка_розширити(MavkaOptions mavkaOptions) {
  do_something(mavkaOptions);
  const auto testDiia = mavkaOptions.createDiia(
      mavkaOptions.mama, "тест",
      [mavkaOptions](MavkaPointer mama, MavkaPointer diiaObject,
                      MavkaPointer args, size_t li) {
        const auto dict = mavkaOptions.createDict(mama);
        mavkaOptions.setAt(mama, dict,
                           MavkaValue{MavkaValueTypeNumber, {.number = 0}},
                           MavkaValue{MavkaValueTypeNumber, {.number = 1}});
        return MavkaValue{MavkaValueTypeObject, {.object = dict}};
      });
  return MavkaValue{MavkaValueTypeObject, {.object = testDiia}};
}