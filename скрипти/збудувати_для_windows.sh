#!/usr/bin/env bash
set -e
set -x

PLATFORM="w"

export CC="zig cc -target x86_64-windows"
export CXX="zig c++ -target x86_64-windows"
export AR="zig ar"
export RANLIB="zig ranlib"
export USE_JEMALLOC=no
export USE_SYSTEMD=no
export TSIL="ціль"
OUT="build-$PLATFORM/mavka.exe"

READLINE_AVAILABLE=0

mkdir -p build-"$PLATFORM"/external
cd build-"$PLATFORM"/external
cmake ../../external -G Ninja -DREADLINE_AVAILABLE="$READLINE_AVAILABLE"
ninja
cd -

CXX_OPTIONS=(
  "-O3"
  "-municode"
)

$CXX "${CXX_OPTIONS[@]}" -o "$OUT" \
  .плавлення/мавка/бібліотека/М.ll \
  .плавлення/мавка/бібліотека/мавка.ll \
  .плавлення/мавка/бібліотека/МаМа.ll \
  .плавлення/мавка/бібліотека/читати_юнікод.ll \
  .плавлення/мавка/компілятор.ll \
  .плавлення/мавка/мавка.ll \
  .плавлення/старт.ll \
  .плавлення/МаМа/КД/КД.ll \
  .плавлення/МаМа/біб.ll \
  .плавлення/МаМа/Код.ll \
  .плавлення/МаМа/Машина.ll \
  .плавлення/МаМа/Назва.ll \
  .плавлення/МаМа/Обʼєкт.ll \
  .плавлення/МаМа/ОбʼєктБайтів.ll \
  .плавлення/МаМа/ОбʼєктДії.ll \
  .плавлення/МаМа/ОбʼєктЛогічного.ll \
  .плавлення/МаМа/ОбʼєктМодуля.ll \
  .плавлення/МаМа/ОбʼєктНативноїДії.ll \
  .плавлення/МаМа/ОбʼєктСловника.ll \
  .плавлення/МаМа/ОбʼєктСписку.ll \
  .плавлення/МаМа/ОбʼєктСтруктури.ll \
  .плавлення/МаМа/ОбʼєктТексту.ll \
  .плавлення/МаМа/ОбʼєктЮнікоду.ll \
  .плавлення/МаМа/ОбʼєктЧисла.ll \
  .плавлення/МаМа/Помилка.ll \
  .плавлення/МаМа/Середовище.ll \
  .плавлення/МаМа/СкладенийОбʼєкт.ll \
  .плавлення/МаМа/Утилізатор.ll \
  build-"$PLATFORM"/external/libmavka_external.a \
  build-"$PLATFORM"/external/mavka_parser/libmavka_parser.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/libmavka_syntax.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a \
  external/main.cpp