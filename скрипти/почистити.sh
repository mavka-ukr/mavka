#!/usr/bin/env sh
set -e
set -x

PLATFORM="l"

export CC="clang"
export CXX="clang++"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
export TSIL="ціль"
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

rm -rf .плавлення
rm -rf $OUT

cd МаМа
bash скрипти/почистити.sh
cd -