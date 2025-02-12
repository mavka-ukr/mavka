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
  .плавлення/МаМа/Предмет.ll \
  .плавлення/МаМа/ПредметАдреси.ll \
  .плавлення/МаМа/ПредметБайтів.ll \
  .плавлення/МаМа/ПредметДії.ll \
  .плавлення/МаМа/ПредметЛогічного.ll \
  .плавлення/МаМа/ПредметМодуля.ll \
  .плавлення/МаМа/ПредметНативноїДії.ll \
  .плавлення/МаМа/ПредметСловника.ll \
  .плавлення/МаМа/ПредметСписку.ll \
  .плавлення/МаМа/ПредметСтруктури.ll \
  .плавлення/МаМа/ПредметТексту.ll \
  .плавлення/МаМа/ПредметЮнікоду.ll \
  .плавлення/МаМа/ПредметЧисла.ll \
  .плавлення/МаМа/Помилка.ll \
  .плавлення/МаМа/Середовище.ll \
  .плавлення/МаМа/СкладенийПредмет.ll \
  .плавлення/МаМа/Утилізатор.ll \
  build-"$PLATFORM"/external/libmavka_external.a \
  build-"$PLATFORM"/external/mavka_parser/libmavka_parser.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/libmavka_syntax.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a \
  external/main.cpp