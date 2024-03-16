#include "./mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

void do_something(Mavka* mavka) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavka->version << std::endl;
}

extern "C" MavkaValue мавка_розширити(Mavka* mavka) {
  do_something(mavka);
  const auto testDiia = mavka->createDiia(
      mavka, "ехо",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        const auto arg1 = mavka->getArg(mavka, args, "0", "значення");
        if (arg1.type == MavkaValueTypeObject) {
          if (mavka->isObjectText(mavka, arg1.data.object)) {
            const auto textData = mavka->getTextData(mavka, arg1.data.object);
            const auto textObject = mavka->createText(mavka, textData);
            return MavkaValue{MavkaValueTypeObject, {.object = textObject}};
          }
        }
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  return MavkaValue{MavkaValueTypeObject, {.object = testDiia}};
}