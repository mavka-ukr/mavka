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

CLANG_OPTIONS="-DMAVKA_VERSION=\"$BUILD_VERSION\" -Iexternal/include"
OPTIMIZATIONS_CFLAGS=""

print_usage() {
  echo "Usage: $0 <debug|release> <platform> [ll|o]"
  echo "Platforms: linux-x86_64, linux-aarch64, macos-x86_64, macos-aarch64, windows-x86_64, windows-aarch64, android-aarch64, wasm64"
}

set_build_mode() {
  case "$1" in
    debug)   OPTIMIZATIONS_CFLAGS+="-g -O0" ;;
    release) OPTIMIZATIONS_CFLAGS+="-O3" ;;
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
      TARGET="x86_64-pc-linux-gnu"
      TARGET_CC="$(which clang)"
      TARGET_AR="$(which llvm-ar)"
      TARGET_RANLIB="$(which llvm-ranlib)"
      TARGET_RC="$(which llvm-rc)"
      TARGET_CFLAGS="$OPTIMIZATIONS_CFLAGS"
      TARGET_LDFLAGS="-fuse-ld=lld"
      TSIL_PLATFORM="лінукс-ікс86_64"
      TSIL_PLATFORM_FOLDER="лінукс-ікс86_64"
      OUTFILENAME="$PROGRAM_NAME"
      extra_opts="-lm -ldl -lpthread"
      setup_linux_libraries
      ;;
    linux-aarch64)
      BUILD_SYSTEM="linux"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="unix"
      TARGET="aarch64-linux-gnu"
      TARGET_CC="$(which clang)"
      TARGET_AR="$(which llvm-ar)"
      TARGET_RANLIB="$(which llvm-ranlib)"
      TARGET_RC="$(which llvm-rc)"
      TARGET_CFLAGS="--target=$TARGET --sysroot=/usr/$TARGET $OPTIMIZATIONS_CFLAGS"
      TARGET_LDFLAGS="-fuse-ld=lld"
      TSIL_PLATFORM="лінукс-аарч64"
      TSIL_PLATFORM_FOLDER="лінукс-аарч64"
      OUTFILENAME="$PROGRAM_NAME"
      extra_opts="-lm -ldl -lpthread $LDFLAGS"
      setup_linux_libraries
      ;;
    macos-x86_64)
      if [ -z "$OSXCROSS_PATH" ]; then
        echo "OSXCROSS_PATH is not set."
        exit 1
      fi
      local osxcross_path="$OSXCROSS_PATH"
      export PATH="$osxcross_path/bin:$PATH"
      BUILD_SYSTEM="macos"; BUILD_ARCH="x86_64"; COMMON_SYSTEM="unix"
      TARGET="x86_64-apple-darwin23"
      TARGET_CC="$osxcross_path/bin/x86_64-apple-darwin23-clang"
      TARGET_AR="$osxcross_path/bin/x86_64-apple-darwin23-ar"
      TARGET_RANLIB="$osxcross_path/bin/x86_64-apple-darwin23-ranlib"
      TARGET_RC="$osxcross_path/bin/x86_64-apple-darwin23-rc"
      TARGET_CFLAGS="$OPTIMIZATIONS_CFLAGS"
      TSIL_PLATFORM="макос-ікс86_64"
      TSIL_PLATFORM_FOLDER="макос-ікс86_64"
      OUTFILENAME="$PROGRAM_NAME"
      setup_macos_libraries
      extra_opts="-Wl,-export_dynamic -lm -lpthread"
      ;;
    macos-aarch64)
      if [ -z "$OSXCROSS_PATH" ]; then
        echo "OSXCROSS_PATH is not set."
        exit 1
      fi
      local osxcross_path="$OSXCROSS_PATH"
      export PATH="$osxcross_path/bin:$PATH"
      BUILD_SYSTEM="macos"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="unix"
      TARGET="aarch64-apple-darwin23"
      TARGET_CC="$osxcross_path/bin/aarch64-apple-darwin23-clang"
      TARGET_AR="$osxcross_path/bin/aarch64-apple-darwin23-ar"
      TARGET_RANLIB="$osxcross_path/bin/aarch64-apple-darwin23-ranlib"
      TARGET_RC="$osxcross_path/bin/aarch64-apple-darwin23-rc"
      TARGET_CFLAGS="$OPTIMIZATIONS_CFLAGS"
      TSIL_PLATFORM="макос-аарч64"
      TSIL_PLATFORM_FOLDER="макос-аарч64"
      OUTFILENAME="$PROGRAM_NAME"
      setup_macos_libraries
      extra_opts="-Wl,-export_dynamic -lm -lpthread"
      ;;
    windows-x86_64)
      if [ -z "$LLVM_MINGW_PATH" ]; then
        echo "LLVM_MINGW_PATH is not set."
        exit 1
      fi
      local llvm_mingw_path="$LLVM_MINGW_PATH"
      BUILD_SYSTEM="windows"; BUILD_ARCH="x86_64"; COMMON_SYSTEM="windows"
      TARGET="x86_64-w64-mingw32"
      TARGET_CC="$llvm_mingw_path/bin/x86_64-w64-mingw32-clang"
      TARGET_AR="$llvm_mingw_path/bin/x86_64-w64-mingw32-llvm-ar"
      TARGET_RANLIB="$llvm_mingw_path/bin/x86_64-w64-mingw32-llvm-ranlib"
      TARGET_RC="$llvm_mingw_path/bin/x86_64-w64-mingw32-llvm-rc"
      TARGET_CPPFLAGS="-DNOCRYPT"
      TARGET_CFLAGS="$OPTIMIZATIONS_CFLAGS"
      TSIL_PLATFORM="віндовс-ікс86_64"
      TSIL_PLATFORM_FOLDER="віндовс-ікс86_64"
      OUTFILENAME="$PROGRAM_NAME.exe"
      extra_opts="-lws2_32 -liphlpapi -luserenv -ldbghelp -lole32 -lgdi32 -lcrypt32 -luser32"
      static_libs="scripts/icon.res"
      setup_windows_libraries
      ;;
    windows-aarch64)
      if [ -z "$LLVM_MINGW_PATH" ]; then
        echo "LLVM_MINGW_PATH is not set."
        exit 1
      fi
      local llvm_mingw_path="$LLVM_MINGW_PATH"
      BUILD_SYSTEM="windows"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="windows"
      TARGET="aarch64-w64-mingw32"
      TARGET_CC="$llvm_mingw_path/bin/aarch64-w64-mingw32-clang"
      TARGET_AR="$llvm_mingw_path/bin/aarch64-w64-mingw32-llvm-ar"
      TARGET_RANLIB="$llvm_mingw_path/bin/aarch64-w64-mingw32-llvm-ranlib"
      TARGET_RC="$llvm_mingw_path/bin/aarch64-w64-mingw32-llvm-rc"
      TARGET_CPPFLAGS="-DNOCRYPT"
      TARGET_CFLAGS="$OPTIMIZATIONS_CFLAGS"
      TSIL_PLATFORM="віндовс-аарч64"
      TSIL_PLATFORM_FOLDER="віндовс-аарч64"
      OUTFILENAME="$PROGRAM_NAME.exe"
      extra_opts="-lws2_32 -liphlpapi -luserenv -ldbghelp -lole32 -lgdi32 -lcrypt32 -luser32"
      static_libs="scripts/icon.res"
      setup_windows_libraries
      ;;
    android-aarch64)
      if [ -z "$ANDROID_NDK_HOME" ]; then
        echo "ANDROID_NDK_HOME is not set."
        exit 1
      fi
      local ndk_toolchain="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64"
      BUILD_SYSTEM="linux"; BUILD_ARCH="aarch64"; COMMON_SYSTEM="unix"
      TARGET="aarch64-linux-android24"
      TARGET_CC="$ndk_toolchain/bin/aarch64-linux-android24-clang"
      TARGET_AR="$ndk_toolchain/bin/llvm-ar"
      TARGET_RANLIB="$ndk_toolchain/bin/llvm-ranlib"
      TARGET_RC="$ndk_toolchain/bin/llvm-rc"
      TARGET_CFLAGS="$OPTIMIZATIONS_CFLAGS"
      TSIL_PLATFORM="лінукс-аарч64"
      TSIL_PLATFORM_FOLDER="андроїд-аарч64"
      OUTFILENAME="$PROGRAM_NAME"
      extra_opts="-ldl -lc -lm"
      setup_linux_libraries
      ;;
    wasm64)
      BUILD_SYSTEM="wasm64"; BUILD_ARCH="wasm64"; COMMON_SYSTEM="wasm64"
      TARGET="wasm64-unknown-unknown"
      TARGET_CC="clang"
      TARGET_AR="llvm-ar"
      TARGET_RANLIB="llvm-ranlib"
      TARGET_RC="llvm-rc"
      TARGET_CFLAGS="--target=$TARGET $OPTIMIZATIONS_CFLAGS"
      TSIL_PLATFORM="васм64"
      TSIL_PLATFORM_FOLDER="васм64"
      OUTFILENAME="$PROGRAM_NAME.wasm"
      extra_opts="-nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,--export-dynamic -Wl,--export-memory -Wl,--initial-memory=16777216 -Wl,--max-memory=1073741824"
      ;;
    *)
      echo "Unsupported platform: $platform"
      print_usage
      exit 1 ;;
  esac

  CLANG="$TARGET_CC $TARGET_CPPFLAGS $TARGET_CFLAGS $TARGET_LDFLAGS"
  CLANG_OPTIONS+=" $extra_opts $CFLAGS $DEPS_CFLAGS"
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
  "$CLANG")

echo "створення виконуваного файлу"
set -x

 $CLANG_CMD \
  -c -o "$READY_DIR/main.o" \
  "external/$COMMON_SYSTEM/main_$COMMON_SYSTEM.c"

 $CLANG_CMD \
  -c -o "$READY_DIR/prystriy_$COMMON_SYSTEM.o" \
  "external/$COMMON_SYSTEM/prystriy_$COMMON_SYSTEM.c"

 $CLANG_CMD \
  -c -o "$READY_DIR/biblioteka_$COMMON_SYSTEM.o" \
  "external/$COMMON_SYSTEM/biblioteka_$COMMON_SYSTEM.c"

if [ "$BUILD_SYSTEM" != "$COMMON_SYSTEM" ]; then
  $CLANG_CMD \
    -c -o "$READY_DIR/biblioteka_$BUILD_SYSTEM.o" \
    "external/$BUILD_SYSTEM/biblioteka_$BUILD_SYSTEM.c"
  BIBLIOTEKA_SYSTEM_OBJ="$READY_DIR/biblioteka_$BUILD_SYSTEM.o"
else
  BIBLIOTEKA_SYSTEM_OBJ=""
fi

 $CLANG_CMD \
  -o "$READY_DIR/$OUTFILENAME" \
  "$READY_DIR/main.o" \
  "$READY_DIR/prystriy_$COMMON_SYSTEM.o" \
  "$READY_DIR/biblioteka_$COMMON_SYSTEM.o" \
  $BIBLIOTEKA_SYSTEM_OBJ \
  $LLIRFILES \
  $STATIC_LIBS

echo "готово: $READY_DIR/$OUTFILENAME"
