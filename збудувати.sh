#!/usr/bin/env sh
set -e
set -x

mkdir -p build/external
cd build/external
cmake ../../external -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always
ninja
cd -

ціль .плавлення/МаМа/Код.ll скомпілювати МаМа/Код.ц
ціль .плавлення/МаМа/Компілятор.ll скомпілювати МаМа/Компілятор.ц
ціль .плавлення/МаМа/Машина.ll скомпілювати МаМа/Машина.ц
ціль .плавлення/мавка.ll скомпілювати мавка.ц
clang++ -o мавка \
  .плавлення/МаМа/Код.ll \
  .плавлення/МаМа/Компілятор.ll \
  .плавлення/МаМа/Машина.ll \
  .плавлення/мавка.ll \
  external/extension.cpp \
  external/main.cpp \
  build/external/libmavka_external.a \
  build/external/mavka_parser/libmavka_parser.a \
  build/external/mavka_parser/syntax/libmavka_syntax.a \
  build/external/mavka_parser/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a