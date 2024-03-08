#include "include/mavka_api_v0.h"
#include "iostream"

using namespace mavka::api::v0;

extern "C" void мавка_розширити_модуль(MavkaOptions mavkaOptions,
                                       MavkaPointer moduleObject) {
  std::cout << "Вітання з C++! Версія Мавки: " << mavkaOptions.version
            << std::endl;
}