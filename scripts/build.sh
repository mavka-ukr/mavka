#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$ROOT_DIR"

source "$SCRIPT_DIR/build_deps.sh"

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat ВЕРСІЯ)
BUILD_MODE="$1"
BUILD_PLATFORM="$2"

TSIL="${TSIL:-ціль}"
ZIG="${ZIG:-zig}"

ZIG_AVAILABLE=false
if command -v "$ZIG" &> /dev/null; then
  ZIG_AVAILABLE=true
fi

CLANG_OPTIONS="-DMAVKA_VERSION=\"$BUILD_VERSION\""
LLIRFILES=""

print_usage() {
  echo "Usage: $0 <debug|release> <platform>"
  echo "Platforms: linux-x86_64, linux-aarch64, macos-x86_64, macos-aarch64, windows-x86_64, windows-aarch64, android-aarch64, wasm64"
}

set_build_mode() {
  case "$1" in
    debug)   CLANG_OPTIONS+=" -g -O0" ;;
    release) CLANG_OPTIONS+=" -O3" ;;
    *)
      echo "Unsupported build mode: $1"
      print_usage
      exit 1 ;;
  esac
}

set_platform_vars() {
  local platform="$1"
  local extra_opts="" static_libs=""

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  case "$platform" in
    linux-x86_64)
      BUILD_SYSTEM="linux"; BUILD_ARCH="x86_64"; COMMON_SYSTEM="unix"
      TARGET_TRIPLE="x86_64-linux-gnu"
      TSIL_PLATFORM="лінукс-ікс86_64"
      TSIL_PLATFORM_FOLDER="лінукс-ікс86_64"
      OUTFILENAME="$PROGRAM_NAME"
      extra_opts="-lm"
      if [ "$ZIG_AVAILABLE" = true ]; then
        CLANG_BIN="$ZIG cc"
        setup_linux_libraries "zig ar" "zig ranlib" "$CLANG_BIN" "$TARGET_TRIPLE" ""
      else
        CLANG_BIN="clang"
        setup_linux_libraries "ar" "ranlib" "$CLANG_BIN" "$TARGET_TRIPLE" ""
      fi
      ;;
    linux-aarch64)
      BUILD_SYSTEM="linux"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="unix"
      TARGET_TRIPLE="aarch64-linux-gnu"
      TSIL_PLATFORM="лінукс-аарч64"
      TSIL_PLATFORM_FOLDER="лінукс-аарч64"
      OUTFILENAME="$PROGRAM_NAME"
      extra_opts="-lm"
      if [ "$ZIG_AVAILABLE" = true ]; then
        CLANG_BIN="$ZIG cc"
        setup_linux_libraries "zig ar" "zig ranlib" "$CLANG_BIN" "$TARGET_TRIPLE" ""
      else
        CLANG_BIN="clang"
        setup_linux_libraries "ar" "ranlib" "$CLANG_BIN" "$TARGET_TRIPLE" ""
      fi
      ;;
    macos-x86_64)
      BUILD_SYSTEM="macos"; BUILD_ARCH="x86_64"; COMMON_SYSTEM="unix"
      TARGET_TRIPLE="x86_64-macos"
      TSIL_PLATFORM="макос-ікс86_64"
      TSIL_PLATFORM_FOLDER="макос-ікс86_64"
      OUTFILENAME="$PROGRAM_NAME"
      if [ "$ZIG_AVAILABLE" = true ]; then
        CLANG_BIN="$ZIG cc"
      else
        CLANG_BIN="clang"
      fi
      extra_opts="-Wl,--export-dynamic -lm"
      ;;
    macos-aarch64)
      BUILD_SYSTEM="macos"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="unix"
      TARGET_TRIPLE="aarch64-macos"
      TSIL_PLATFORM="макос-аарч64"
      TSIL_PLATFORM_FOLDER="макос-аарч64"
      OUTFILENAME="$PROGRAM_NAME"
      if [ "$ZIG_AVAILABLE" = true ]; then
        CLANG_BIN="$ZIG cc"
      else
        CLANG_BIN="clang"
      fi
      extra_opts="-Wl,--export-dynamic -lm"
      ;;
    windows-x86_64)
      BUILD_SYSTEM="windows"; BUILD_ARCH="x86_64"; COMMON_SYSTEM="windows"
      TARGET_TRIPLE="x86_64-windows-gnu"
      TSIL_PLATFORM="віндовс-ікс86_64"
      TSIL_PLATFORM_FOLDER="віндовс-ікс86_64"
      OUTFILENAME="$PROGRAM_NAME.exe"
      if [ "$ZIG_AVAILABLE" = true ]; then
        CLANG_BIN="$ZIG cc"
      else
        CLANG_BIN="clang"
      fi
      static_libs="scripts/icon.res"
      ;;
    windows-aarch64)
      BUILD_SYSTEM="windows"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="windows"
      TARGET_TRIPLE="aarch64-windows-gnu"
      TSIL_PLATFORM="віндовс-аарч64"
      TSIL_PLATFORM_FOLDER="віндовс-аарч64"
      OUTFILENAME="$PROGRAM_NAME.exe"
      if [ "$ZIG_AVAILABLE" = true ]; then
        CLANG_BIN="$ZIG cc"
      else
        CLANG_BIN="clang"
      fi
      static_libs="scripts/icon.res"
      ;;
    android-aarch64)
      if [ -z "$ANDROID_NDK_HOME" ]; then
        echo "ANDROID_NDK_HOME is not set."
        exit 1
      fi
      local ndk_toolchain="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64"
      BUILD_SYSTEM="linux"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="unix"
      TARGET_TRIPLE="aarch64-linux-android24"
      TSIL_PLATFORM="лінукс-аарч64"
      TSIL_PLATFORM_FOLDER="андроїд-аарч64"
      OUTFILENAME="$PROGRAM_NAME"
      CLANG_BIN="$ndk_toolchain/bin/aarch64-linux-android24-clang"
      extra_opts="-ldl -lc -lm"
      setup_linux_libraries \
        "$ndk_toolchain/bin/llvm-ar" \
        "$ndk_toolchain/bin/llvm-ranlib" \
        "$CLANG_BIN" "$TARGET_TRIPLE" ""
      ;;
    wasm64)
      BUILD_SYSTEM="wasm64"; BUILD_ARCH="wasm64"; COMMON_SYSTEM="wasm64"
      TARGET_TRIPLE="wasm64-unknown-unknown"
      TSIL_PLATFORM="васм64"
      TSIL_PLATFORM_FOLDER="васм64"
      OUTFILENAME="$PROGRAM_NAME.wasm"
      CLANG_BIN="clang"
      extra_opts="-nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,--export-memory -Wl,--initial-memory=16777216 -Wl,--max-memory=1073741824"
      ;;
    *)
      echo "Unsupported platform: $platform"
      print_usage
      exit 1 ;;
  esac

  CLANG="$CLANG_BIN --target=$TARGET_TRIPLE"
  CLANG_OPTIONS+=" $extra_opts $DEPS_CFLAGS"
  STATIC_LIBS="${static_libs:+$static_libs }$DEPS_LIBS"
}

compile_tsil() {
  local input_file="$1"
  echo "перетворення $input_file"
  $TSIL \
    "$(realpath --relative-to="$(pwd)" "$SEMIREADY_DIR/$input_file.ллвмір")" -П="$TSIL_PLATFORM" \
    перетворити \
    "$(realpath --relative-to="$(pwd)" "$input_file")" -В=./бібліотека/визначення -В=./КД/визначення -В=./визначення
  mv "$SEMIREADY_DIR/$input_file.ллвмір" "$SEMIREADY_DIR/$input_file.ллвмір.ll"
  LLIRFILES+=" $SEMIREADY_DIR/$input_file.ллвмір.ll"
}

if [ -z "$BUILD_MODE" ] || [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

set_build_mode "$BUILD_MODE"
set_platform_vars "$BUILD_PLATFORM"

SEMIREADY_DIR="$ROOT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/напівготове"
READY_DIR="$ROOT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/готове"

mkdir -p "$SEMIREADY_DIR"/бібліотека/математика
mkdir -p "$SEMIREADY_DIR"/бібліотека/система
mkdir -p "$SEMIREADY_DIR"/бібліотека/читати
mkdir -p "$SEMIREADY_DIR"/КД
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Дані/дії
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Дані/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПроміжокЧисел/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Дія/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Код/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Модуль/дії
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Модуль/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Параметр/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Ознака/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПеребірДаних/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПеребірПроміжкаЧисел/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПеребірПослідовності/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПеребірСловника/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПеребірСписку/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/ПеребірТексту/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Послідовність/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Словник/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Список/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Клас/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Текст/дії
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Текст/методи
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Число/дії
mkdir -p "$SEMIREADY_DIR"/машина/предмети/Число/методи
mkdir -p "$SEMIREADY_DIR"/машина/перекладач
mkdir -p "$SEMIREADY_DIR"/машина/розбирач
mkdir -p "$SEMIREADY_DIR"/пристрій
mkdir -p "$READY_DIR"

compile_tsil "КД/КД.ц"

compile_tsil "машина/Взяти.ц"
compile_tsil "машина/ВзятіЗначення.ц"
compile_tsil "машина/Вивід.ц"
compile_tsil "машина/Дійсність.ц"
compile_tsil "машина/Призначення.ц"
compile_tsil "машина/Допоміжне.ц"
compile_tsil "машина/Задіяні.ц"
compile_tsil "машина/Значення.ц"
compile_tsil "машина/ІнформаціяПадіння.ц"
compile_tsil "машина/КористувацькіДані.ц"
compile_tsil "машина/Машина.ц"
compile_tsil "машина/МісцезнаходженняВказівок.ц"
compile_tsil "машина/НакопичувачТексту.ц"
compile_tsil "машина/Очищувач.ц"
compile_tsil "машина/Притримувач.ц"
compile_tsil "машина/Розмова.ц"
compile_tsil "машина/Спроби.ц"

compile_tsil "машина/предмети/Дані/дії/виділити.ц"
compile_tsil "машина/предмети/Дані/дії/обнулено.ц"
compile_tsil "машина/предмети/Дані/методи/чародія_перебір.ц"
compile_tsil "машина/предмети/Дані/ПредметДаних.ц"

compile_tsil "машина/предмети/ПроміжокЧисел/методи/чародія_перебір.ц"
compile_tsil "машина/предмети/ПроміжокЧисел/ПредметПроміжкаЧисел.ц"

compile_tsil "машина/предмети/Дія/ПредметДії.ц"

compile_tsil "машина/предмети/Код/ПредметКоду.ц"

compile_tsil "машина/предмети/Модуль/дії/отримати_назву.ц"
compile_tsil "машина/предмети/Модуль/ПредметМодуля.ц"

compile_tsil "машина/предмети/Параметр/ПредметПараметра.ц"

compile_tsil "машина/предмети/Ознака/ПредметОзнаки.ц"

compile_tsil "машина/предмети/ПеребірДаних/методи/далі.ц"
compile_tsil "машина/предмети/ПеребірДаних/ПредметПереборуДаних.ц"

compile_tsil "машина/предмети/ПеребірПроміжкаЧисел/методи/далі.ц"
compile_tsil "машина/предмети/ПеребірПроміжкаЧисел/ПредметПереборуПроміжкаЧисел.ц"

compile_tsil "машина/предмети/ПеребірПослідовності/методи/далі.ц"
compile_tsil "машина/предмети/ПеребірПослідовності/ПредметПереборуПослідовності.ц"

compile_tsil "машина/предмети/ПеребірСловника/методи/далі.ц"
compile_tsil "машина/предмети/ПеребірСловника/ПредметПереборуСловника.ц"

compile_tsil "машина/предмети/ПеребірСписку/методи/далі.ц"
compile_tsil "машина/предмети/ПеребірСписку/ПредметПереборуСписку.ц"

compile_tsil "машина/предмети/ПеребірТексту/методи/далі.ц"
compile_tsil "машина/предмети/ПеребірТексту/ПредметПереборуТексту.ц"

compile_tsil "машина/предмети/Послідовність/методи/чародія_перебір.ц"
compile_tsil "машина/предмети/Послідовність/ПредметПослідовності.ц"

compile_tsil "машина/предмети/Словник/методи/значення.ц"
compile_tsil "машина/предмети/Словник/методи/ключі.ц"
compile_tsil "машина/предмети/Словник/методи/містить.ц"
compile_tsil "машина/предмети/Словник/методи/чародія_перебір.ц"
compile_tsil "машина/предмети/Словник/методи/чародія_текст.ц"
compile_tsil "машина/предмети/Словник/ПредметСловника.ц"

compile_tsil "машина/предмети/Список/методи/чародія_текст.ц"
compile_tsil "машина/предмети/Список/методи/чародія_перебір.ц"
compile_tsil "машина/предмети/Список/методи/додати.ц"
compile_tsil "машина/предмети/Список/методи/забрати.ц"
compile_tsil "машина/предмети/Список/методи/позиція.ц"
compile_tsil "машина/предмети/Список/методи/знайти.ц"
compile_tsil "машина/предмети/Список/методи/знайти_позицію.ц"
compile_tsil "машина/предмети/Список/методи/відібрати.ц"
compile_tsil "машина/предмети/Список/методи/перетворити.ц"
compile_tsil "машина/предмети/Список/методи/обернути.ц"
compile_tsil "машина/предмети/Список/методи/містить.ц"
compile_tsil "машина/предмети/Список/ПредметСписку.ц"

compile_tsil "машина/предмети/Клас/ПредметКласу.ц"

compile_tsil "машина/предмети/Текст/методи/чародія_перебір.ц"
compile_tsil "машина/предмети/Текст/методи/чародія_текст.ц"
compile_tsil "машина/предмети/Текст/методи/чародія_число.ц"
compile_tsil "машина/предмети/Текст/ПредметТексту.ц"

compile_tsil "машина/предмети/Число/методи/чародія_текст.ц"
compile_tsil "машина/предмети/Число/методи/чародія_число.ц"
compile_tsil "машина/предмети/Число/ПредметЧисла.ц"

compile_tsil "машина/предмети/СкладенийПредмет.ц"

compile_tsil "машина/перекладач/перекладач.ц"

compile_tsil "машина/розбирач/розбирач.ц"

compile_tsil "пристрій/глобальні.ц"
compile_tsil "пристрій/машина.ц"
compile_tsil "пристрій/пристрій.ц"

compile_tsil "бібліотека/математика/_.ц"
compile_tsil "бібліотека/система/_.ц"
compile_tsil "бібліотека/система/видалити.ц"
compile_tsil "бібліотека/система/дописати.ц"
compile_tsil "бібліотека/система/записати.ц"
compile_tsil "бібліотека/система/прочитати.ц"
compile_tsil "бібліотека/система/створити_папку.ц"
compile_tsil "бібліотека/система/виконати.ц"
compile_tsil "бібліотека/система/РезультатВиконання.ц"
compile_tsil "бібліотека/читати/_.ц"
compile_tsil "бібліотека/бібліотека.ц"

compile_tsil "початок.ц"

echo "створення виконуваного файлу"
set -x
$CLANG $CLANG_OPTIONS \
  -c -o "$READY_DIR/main.o" \
  -Iexternal/include \
  "external/$COMMON_SYSTEM/main_$COMMON_SYSTEM.c"
$CLANG $CLANG_OPTIONS \
  -c -o "$READY_DIR/prystriy_$COMMON_SYSTEM.o" \
  -Iexternal/include \
  "external/$COMMON_SYSTEM/prystriy_$COMMON_SYSTEM.c"
$CLANG $CLANG_OPTIONS \
  -c -o "$READY_DIR/biblioteka_$COMMON_SYSTEM.o" \
  -Iexternal/include \
  "external/$COMMON_SYSTEM/biblioteka_$COMMON_SYSTEM.c"

if [ "$BUILD_SYSTEM" != "$COMMON_SYSTEM" ]; then
  $CLANG $CLANG_OPTIONS \
    -c -o "$READY_DIR/biblioteka_$BUILD_SYSTEM.o" \
    -Iexternal/include \
    "external/$BUILD_SYSTEM/biblioteka_$BUILD_SYSTEM.c"
  BIBLIOTEKA_SYSTEM_OBJ="$READY_DIR/biblioteka_$BUILD_SYSTEM.o"
else
  BIBLIOTEKA_SYSTEM_OBJ=""
fi

$CLANG $CLANG_OPTIONS \
  -o "$READY_DIR/$OUTFILENAME" \
  "$READY_DIR/main.o" \
  "$READY_DIR/prystriy_$COMMON_SYSTEM.o" \
  "$READY_DIR/biblioteka_$COMMON_SYSTEM.o" \
  $BIBLIOTEKA_SYSTEM_OBJ \
  $LLIRFILES \
  $STATIC_LIBS

echo "готово: $READY_DIR/$OUTFILENAME"