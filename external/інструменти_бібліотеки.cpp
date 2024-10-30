#include <string.h>
#include <cmath>
#include <iostream>
#include <string>

extern "C" double математика_abs(double value) {
  return std::abs(value);
}
extern "C" double математика_acos(double value) {
  return std::acos(value);
}
extern "C" double математика_asin(double value) {
  return std::asin(value);
}
extern "C" double математика_atan(double value) {
  return std::atan(value);
}
extern "C" double математика_atan2(double a, double b) {
  return std::atan2(a, b);
}
extern "C" double математика_cos(double value) {
  return std::cos(value);
}
extern "C" double математика_sin(double value) {
  return std::sin(value);
}
extern "C" double математика_tan(double value) {
  return std::tan(value);
}
extern "C" double математика_cosh(double value) {
  return std::cosh(value);
}
extern "C" double математика_sinh(double value) {
  return std::sinh(value);
}
extern "C" double математика_tanh(double value) {
  return std::tanh(value);
}
extern "C" double математика_exp(double value) {
  return std::exp(value);
}
extern "C" double математика_ldexp(double a, double b) {
  return std::ldexp(a, b);
}
extern "C" double математика_log(double value) {
  return std::log(value);
}
extern "C" double математика_log10(double value) {
  return std::log10(value);
}
extern "C" double математика_pow(double a, double b) {
  return std::pow(a, b);
}
extern "C" double математика_sqrt(double value) {
  return std::sqrt(value);
}
extern "C" double математика_ceil(double value) {
  return std::ceil(value);
}
extern "C" double математика_fabs(double value) {
  return std::fabs(value);
}
extern "C" double математика_floor(double value) {
  return std::floor(value);
}
extern "C" double математика_round(double value) {
  return std::round(value);
}
extern "C" unsigned char* читати_зі_стандартного_вводу(unsigned char* prefix) {
  std::string input;
  if (prefix) {
    std::cout << prefix;
  }
  std::getline(std::cin, input);
  return (unsigned char*)strdup(input.c_str());
}