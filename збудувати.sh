#!/usr/bin/env sh
set -e
set -x

mkdir -p build/external
cd build/external
cmake ../../external -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always
ninja
cd -

ціль .плавлення/мавка.o скомпілювати мавка.ц
clang++ -o мавка \
  .плавлення/мавка.o \
  external/extension.cpp \
  external/main.cpp \
  build/external/libmavka_external.a \
  build/external/mavka_parser/libmavka_parser.a \
  build/external/mavka_parser/syntax/libmavka_syntax.a \
  build/external/mavka_parser/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a