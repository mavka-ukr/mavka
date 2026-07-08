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

print_usage() {
  echo "Usage: $0 <debug|release> <platform> [ll|o]"
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
      extra_opts="-nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,--export-dynamic -Wl,--export-memory -Wl,--initial-memory=16777216 -Wl,--max-memory=1073741824"
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

if [ -z "$BUILD_MODE" ] || [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

set_build_mode "$BUILD_MODE"
set_platform_vars "$BUILD_PLATFORM"

case "$BUILD_MODE" in
  debug)   TSIL_MODE="відлагодження" ;;
  release) TSIL_MODE="випуск" ;;
esac

READY_DIR="$ROOT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/$TSIL_MODE/готове"
mkdir -p "$READY_DIR"

CLANG_CMD="$CLANG $CLANG_OPTIONS"

LLIRFILES=$(/bin/bash "$SCRIPT_DIR/build_tsil.sh" \
  "$BUILD_MODE" \
  "$BUILD_PLATFORM" \
  "ll" \
  "$TSIL" \
  "$CLANG_CMD")

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