#!/bin/bash
set -e

BUILD_MODE="$1"
BUILD_PLATFORM="$2"
BUILD_ARCH=""
BUILD_SYSTEM=""
COMMON_SYSTEM=""
TARGET_TRIPLE=""
TSIL_ARCH=""
TSIL_SYSTEM=""
OUTFILENAME=""

TSIL="ціль"
CLANG="clang"
CLANG_OPTIONS=""
LLIRFILES=""

print_usage() {
  echo "Usage: $0 <debug|release> <platform>"
  echo "Supported platforms: x86_64-linux, aarch64-linux, x86_64-windows, aarch64-windows, x86-windows, x86_64-macos, aarch64-macos"
}

if [ -z "$BUILD_MODE" ]; then
  print_usage
  exit 1
fi

if [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

if [[ "$BUILD_MODE" == "debug" ]]; then
  CLANG_OPTIONS+=" -g -O0"
elif [[ "$BUILD_MODE" == "release" ]]; then
  CLANG_OPTIONS+=" -O3"
else
  echo "Unsupported build mode: $BUILD_MODE"
  print_usage
  exit 1
fi

if [[ "$BUILD_PLATFORM" == "x86_64-linux" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="linux"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="x86_64-pc-linux-gnu"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="лінукс"
  OUTFILENAME="мавка"
  CLANG_OPTIONS+=" -lm"
elif [[ "$BUILD_PLATFORM" == "aarch64-linux" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="linux"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="aarch64-linux-gnu"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="лінукс"
  CLANG="zig cc"
  OUTFILENAME="мавка"
  CLANG_OPTIONS+=" -lm"
elif [[ "$BUILD_PLATFORM" == "x86_64-windows" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="windows"
  COMMON_SYSTEM="windows"
  TARGET_TRIPLE="x86_64-windows-gnu"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="віндовс"
  CLANG="zig cc"
  OUTFILENAME="мавка.exe"
elif [[ "$BUILD_PLATFORM" == "aarch64-windows" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="windows"
  COMMON_SYSTEM="windows"
  TARGET_TRIPLE="aarch64-windows-gnu"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="віндовс"
  CLANG="zig cc"
  OUTFILENAME="мавка.exe"
elif [[ "$BUILD_PLATFORM" == "x86-windows" ]]; then
  BUILD_ARCH="x86"
  BUILD_SYSTEM="windows"
  COMMON_SYSTEM="windows"
  TARGET_TRIPLE="x86-windows-gnu"
  TSIL_ARCH="ікс86"
  TSIL_SYSTEM="віндовс"
  CLANG="zig cc"
  OUTFILENAME="мавка.exe"
elif [[ "$BUILD_PLATFORM" == "x86_64-macos" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="macos"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="x86_64-macos"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="макос"
  CLANG="zig cc"
  OUTFILENAME="мавка"
  CLANG_OPTIONS+=" -lm"
elif [[ "$BUILD_PLATFORM" == "aarch64-macos" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="macos"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="aarch64-macos"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="макос"
  CLANG="zig cc"
  OUTFILENAME="мавка"
  CLANG_OPTIONS+=" -lm"
else
  echo "Unsupported build platform: $BUILD_PLATFORM"
  exit 1
fi

SEMIREADY_DIR="будування/$TSIL_ARCH-$TSIL_SYSTEM/напівготове"
READY_DIR="будування/$TSIL_ARCH-$TSIL_SYSTEM/готове"

mkdir -p "$SEMIREADY_DIR"/бібліотека
mkdir -p "$SEMIREADY_DIR"/КД
mkdir -p "$SEMIREADY_DIR"/машина/предмети
mkdir -p "$SEMIREADY_DIR"/перекладач
mkdir -p "$SEMIREADY_DIR"/пристрій
mkdir -p "$SEMIREADY_DIR"/розбирач
mkdir -p "$READY_DIR"

compile_tsil() {
  local input_file="$1"

  echo "перетворення $input_file"
  $TSIL "$SEMIREADY_DIR/$input_file.ллвмір" --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити "$input_file"
  mv "$SEMIREADY_DIR/$input_file.ллвмір" "$SEMIREADY_DIR/$input_file.ллвмір".ll

  LLIRFILES+=" $SEMIREADY_DIR/$input_file.ллвмір.ll"
}

compile_tsil "бібліотека/математика.ц"
compile_tsil "КД/КД.ц"
compile_tsil "машина/ВзятіЗначення.ц"
compile_tsil "машина/Властивості.ц"
compile_tsil "машина/Дійсність.ц"
compile_tsil "машина/Допоміжне.ц"
compile_tsil "машина/Задіяні.ц"
compile_tsil "машина/Значення.ц"
compile_tsil "машина/ІменованоЗадіяні.ц"
compile_tsil "машина/ІнформаціяПадіння.ц"
compile_tsil "машина/КористувацькіДані.ц"
compile_tsil "машина/Машина.ц"
compile_tsil "машина/МісцезнаходженняВказівок.ц"
compile_tsil "машина/НакопичувачТексту.ц"
compile_tsil "машина/Очищувач.ц"
compile_tsil "машина/Притримувач.ц"
compile_tsil "машина/Спроби.ц"
compile_tsil "машина/предмети/ПредметДаних.ц"
compile_tsil "машина/предмети/ПредметДіапазонуДробових.ц"
compile_tsil "машина/предмети/ПредметДіапазонуЦілих.ц"
compile_tsil "машина/предмети/ПредметДії.ц"
compile_tsil "машина/предмети/ПредметДробового.ц"
compile_tsil "машина/предмети/ПредметЗміннихДаних.ц"
compile_tsil "машина/предмети/ПредметКоду.ц"
compile_tsil "машина/предмети/ПредметМодуля.ц"
compile_tsil "машина/предмети/ПредметПараметра.ц"
compile_tsil "машина/предмети/ПредметПереборуДіапазонуДробових.ц"
compile_tsil "машина/предмети/ПредметПереборуДіапазонуЦілих.ц"
compile_tsil "машина/предмети/ПредметПереборуСписку.ц"
compile_tsil "машина/предмети/ПредметПослідовності.ц"
compile_tsil "машина/предмети/ПредметСловника.ц"
compile_tsil "машина/предмети/ПредметСписку.ц"
compile_tsil "машина/предмети/ПредметСтруктури.ц"
compile_tsil "машина/предмети/ПредметТексту.ц"
compile_tsil "машина/предмети/ПредметЦілого.ц"
compile_tsil "машина/предмети/СкладенийПредмет.ц"
compile_tsil "перекладач/перекладач.ц"
compile_tsil "пристрій/взяти_файл.ц"
compile_tsil "пристрій/вивід.ц"
compile_tsil "пристрій/глобальні.ц"
compile_tsil "пристрій/машина.ц"
compile_tsil "пристрій/пристрій.ц"
compile_tsil "розбирач/розбирач.ц"
compile_tsil "старт.ц"

echo "створення виконуваного файлу"

$CLANG --target="$TARGET_TRIPLE" \
       $CLANG_OPTIONS \
       -o "$READY_DIR"/"$OUTFILENAME" \
       "external/$COMMON_SYSTEM/main_$COMMON_SYSTEM.c" \
       "external/$COMMON_SYSTEM/prystriy_$COMMON_SYSTEM.c" \
       $LLIRFILES

echo "готово!"
echo "виконуваний файл: $READY_DIR/$OUTFILENAME"