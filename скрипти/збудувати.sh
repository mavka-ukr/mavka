#!/usr/bin/env sh
set -e
set -x

PLATFORM="l"

export CC="clang"
export CXX="clang++"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
OUT="build-$PLATFORM/мавка"

mkdir -p build-"$PLATFORM"/external
cd build-"$PLATFORM"/external
cmake ../../external -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always
ninja
cd -

mkdir -p "build-$PLATFORM/external/isocline"
cd "build-$PLATFORM/external/isocline"
cmake "../../../external/isocline" -G Ninja
ninja
cd -

ціль .плавлення/мавка/бібліотека/М.ll скомпілювати мавка/бібліотека/М.ц
ціль .плавлення/мавка/бібліотека/мавка.ll скомпілювати мавка/бібліотека/мавка.ц
ціль .плавлення/мавка/бібліотека/МаМа.ll скомпілювати мавка/бібліотека/МаМа.ц
ціль .плавлення/мавка/компілятор.ll скомпілювати мавка/компілятор.ц
ціль .плавлення/мавка/мавка.ll скомпілювати мавка/мавка.ц

cd МаМа
bash скрипти/збудувати.sh
cd -

ціль .плавлення/старт.ll скомпілювати старт.ц

$CXX -static -O3 -o "$OUT" \
  .плавлення/мавка/бібліотека/М.ll \
  .плавлення/мавка/бібліотека/мавка.ll \
  .плавлення/мавка/бібліотека/МаМа.ll \
  .плавлення/мавка/компілятор.ll \
  .плавлення/мавка/мавка.ll \
  .плавлення/старт.ll \
  МаМа/build-l/МаМа.a \
  build-"$PLATFORM"/external/libmavka_external.a \
  build-"$PLATFORM"/external/mavka_parser/libmavka_parser.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/libmavka_syntax.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a \
  build-"$PLATFORM"/external/isocline/libisocline.a