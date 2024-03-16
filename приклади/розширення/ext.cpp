#include "./mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

void do_something(Mavka* mavka) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavka->version << std::endl;
}

extern "C" MavkaValue мавка_розширити(Mavka* mavka) {
  do_something(mavka);
  const auto testStructure = mavka->createStructure(mavka, "Вектор2Д");
  mavka->addParamToStructure(mavka, testStructure, "х");
  mavka->addParamToStructure(mavka, testStructure, "у");
  return MavkaValue{MavkaValueTypeObject, {.object = testStructure}};
}