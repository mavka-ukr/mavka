#!/usr/bin/env bash
set -e
set -x

PLATFORM="l"

export CC="clang"
export CXX="clang++"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
export TSIL="ціль"
OUT="build-$PLATFORM/мавка"

READLINE_AVAILABLE=0
if [ -f /usr/include/readline/readline.h ]; then
  READLINE_AVAILABLE=1
fi

mkdir -p build-"$PLATFORM"/external
cd build-"$PLATFORM"/external
cmake ../../external -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always -DREADLINE_AVAILABLE="$READLINE_AVAILABLE"
ninja
cd -

$TSIL .плавлення/мавка/бібліотека/М.ll скомпілювати мавка/бібліотека/М.ц
$TSIL .плавлення/мавка/бібліотека/мавка.ll скомпілювати мавка/бібліотека/мавка.ц
$TSIL .плавлення/мавка/бібліотека/МаМа.ll скомпілювати мавка/бібліотека/МаМа.ц
$TSIL .плавлення/мавка/бібліотека/читати_юнікод.ll скомпілювати мавка/бібліотека/читати_юнікод.ц
$TSIL .плавлення/мавка/компілятор.ll скомпілювати мавка/компілятор.ц
$TSIL .плавлення/мавка/мавка.ll скомпілювати мавка/мавка.ц

cd МаМа
bash скрипти/збудувати.sh
cd -

$TSIL .плавлення/старт.ll скомпілювати старт.ц

CXX_OPTIONS=(
  "-O3"
)
if [ "$READLINE_AVAILABLE" -eq 1 ]; then
  CXX_OPTIONS+=("-lreadline")
fi

$CXX "${CXX_OPTIONS[@]}" -o "$OUT" \
  .плавлення/мавка/бібліотека/М.ll \
  .плавлення/мавка/бібліотека/мавка.ll \
  .плавлення/мавка/бібліотека/МаМа.ll \
  .плавлення/мавка/бібліотека/читати_юнікод.ll \
  .плавлення/мавка/компілятор.ll \
  .плавлення/мавка/мавка.ll \
  .плавлення/старт.ll \
  МаМа/build-l/МаМа.a \
  build-"$PLATFORM"/external/libmavka_external.a \
  build-"$PLATFORM"/external/mavka_parser/libmavka_parser.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/libmavka_syntax.a \
  build-"$PLATFORM"/external/mavka_parser/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a