#!/bin/bash
set -e

CURRENT_DIR=$(pwd)

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat машина/ВЕРСІЯ)
BUILD_MODE="$1"
BUILD_PLATFORM="$2"

if [ -z "$TSIL" ]
then
  TSIL="ціль"
fi

if [ -z "$CLANG" ]
then
  CLANG="clang"
fi

if [ -z "$ZIG" ]
then
  ZIG="zig"
fi

CLANG_OPTIONS="-DPROGRAM_VERSION=\"$BUILD_VERSION\""
LLIRFILES=""

print_usage() {
  echo "Usage: $0 <debug|release> <platform>"
  echo "Supported platforms: linux-x86_64, linux-aarch64, macos-x86_64, macos-aarch64, windows-x86_64, windows-aarch64, android-aarch64, wasm64"
}

set_build_mode() {
  local mode="$1"

  case "$mode" in
    debug)
      CLANG_OPTIONS+=" -g -O0" ;;
    release)
      CLANG_OPTIONS+=" -O3" ;;
    *)
      echo "Unsupported build mode: $mode"
      print_usage
      exit 1 ;;
  esac
}

extract_if_needed() {
  local tarball="$1"
  local extract_dir="$2"

  if [ ! -d "$extract_dir" ]; then
    mkdir -p "$(dirname "$extract_dir")"
    cd "$(dirname "$extract_dir")"
    tar -xvf "$tarball"
    cd -
  fi
}

build_ncurses() {
  local ar="$1"
  local ranlib="$2"
  local cc="$3"
  local target="$4"
  local ldflags="$5"

  local ncurses_dir="будування/ncurses/$target/ncurses-6.4"
  local build_dir="$ncurses_dir/build_ncurses"

  extract_if_needed "$(pwd)/scripts/ncurses-6.4.tar.gz" \
    "$ncurses_dir"

  if [ ! -d "$build_dir" ]; then
    cd "$ncurses_dir"

    CONFIGURE_OPTS="--with-shared=no --with-static=yes --without-progs --without-tests --without-cxx --without-cxx-binding --without-ada --without-curses-h"

    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-O3" LDFLAGS="$ldflags" \
      ./configure --host="$target" --prefix="$(pwd)/build_ncurses" $CONFIGURE_OPTS

    make -j$(nproc)
    make install
    cd -
  fi

  echo "$build_dir"
}

build_readline() {
  local ar="$1"
  local ranlib="$2"
  local cc="$3"
  local target="$4"
  local ldflags="$5"
  local ncurses_build_dir="$6"

  local readline_dir="будування/readline/$target/readline-8.2"
  local build_dir="$readline_dir/build_readline"

  extract_if_needed "$(pwd)/scripts/readline-8.2.tar.gz" \
    "$readline_dir"

  if [ ! -d "$build_dir" ]; then
    cd "$readline_dir"
    if [[ "$target" == *"android"* ]]; then
      export ac_cv_func_getpwent=no
      export ac_cv_func_setpwent=no
      export ac_cv_func_endpwent=no
    fi

    CONFIGURE_OPTS="--enable-static --disable-shared --with-curses --without-progs --without-tests --without-cxx --without-cxx-binding"

    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-I$ncurses_build_dir/include -O3" LDFLAGS="$ldflags -L$ncurses_build_dir/lib" \
      ./configure --host="$target" --prefix="$(pwd)/build_readline" $CONFIGURE_OPTS

    make -j$(nproc)
    make install
    cd -
  fi

  echo "$build_dir"
}

build_idn2() {
  local ar="$1"
  local ranlib="$2"
  local cc="$3"
  local target="$4"
  local ldflags="$5"

  local idn2_dir="будування/libidn2/$target/libidn2-2.3.2"
  local build_dir="$idn2_dir/build_idn2"

  extract_if_needed "$(pwd)/scripts/libidn2-2.3.2.tar.gz" \
    "$idn2_dir"

  if [ ! -d "$build_dir" ]; then
    cd "$idn2_dir"

    if [[ "$target" == *"android"* ]]; then
      export ac_cv_func_strchrnul=no
    fi

    CONFIGURE_OPTS="--enable-static --disable-shared --without-tests --without-gcc-atomics"

    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-O3" LDFLAGS="$ldflags" \
      ./configure --host="$target" --prefix="$(pwd)/build_idn2" $CONFIGURE_OPTS

    make -j$(nproc)
    make install
    cd -
  fi

  echo "$build_dir"
}

setup_linux_libraries() {
  local ar="$1"
  local ranlib="$2"
  local cc="$3"
  local target="$4"
  local ldflags="$5"
  local extra_opts_var="$6"
  local static_libs_var="$7"

  build_ncurses "$ar" "$ranlib" "$cc" "$target" "$ldflags" > /dev/tty
  local ncurses_build=$(build_ncurses "$ar" "$ranlib" "$cc" "$target" "$ldflags" 2>&1 | tail -n 1)

  build_readline "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$ncurses_build" > /dev/tty
  local readline_build=$(build_readline "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$ncurses_build" 2>&1 | tail -n 1)

  build_idn2 "$ar" "$ranlib" "$cc" "$target" "$ldflags" > /dev/tty
  local idn2_build=$(build_idn2 "$ar" "$ranlib" "$cc" "$target" "$ldflags" 2>&1 | tail -n 1)

  eval "$extra_opts_var+=\" -I$(pwd)/$ncurses_build/include\""
  eval "$extra_opts_var+=\" -DPROGRAM_USE_READLINE -I$(pwd)/$readline_build/include\""
  eval "$extra_opts_var+=\" -I$(pwd)/$idn2_build/include\""

  eval "$static_libs_var+=\" $(pwd)/$readline_build/lib/libreadline.a\""
  eval "$static_libs_var+=\" $(pwd)/$readline_build/lib/libhistory.a\""
  eval "$static_libs_var+=\" $(pwd)/$ncurses_build/lib/libncurses.a\""
  eval "$static_libs_var+=\" $(pwd)/$ncurses_build/lib/libform.a\""
  eval "$static_libs_var+=\" $(pwd)/$ncurses_build/lib/libpanel.a\""

  eval "$static_libs_var+=\" $(pwd)/$idn2_build/lib/libidn2.a\""
}

set_platform_vars() {
  local platform="$1"
  local system arch common_sys target outfile clang_bin extra_opts static_libs

  case "$platform" in
    linux-x86_64)
      system="linux"
      arch="x86_64"
      common_sys="unix"
      target="x86_64-linux-gnu"
      tsil_platform="лінукс-ікс86_64"
      tsil_platform_folder="лінукс-ікс86_64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts=""

      setup_linux_libraries "zig ar" "zig ranlib" "$clang_bin" "$target" "" extra_opts static_libs
      ;;
    linux-aarch64)
      system="linux"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-linux-gnu"
      tsil_platform="лінукс-аарч64"
      tsil_platform_folder="лінукс-аарч64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts=""

      setup_linux_libraries "zig ar" "zig ranlib" "$clang_bin" "$target" "" extra_opts static_libs
      ;;
    macos-x86_64)
      system="macos"
      arch="x86_64"
      common_sys="unix"
      target="x86_64-macos"
      tsil_platform="макос-ікс86_64"
      tsil_platform_folder="макос-ікс86_64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts="-Wl,--export-dynamic"
      ;;
    macos-aarch64)
      system="macos"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-macos"
      tsil_platform="макос-аарч64"
      tsil_platform_folder="макос-аарч64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts="-Wl,--export-dynamic"
      ;;
    windows-x86_64)
      system="windows"
      arch="x86_64"
      common_sys="windows"
      target="x86_64-windows-gnu"
      tsil_platform="віндовс-ікс86_64"
      tsil_platform_folder="віндовс-ікс86_64"
      outfile="$PROGRAM_NAME.exe"
      clang_bin="$ZIG cc"
      extra_opts=""
      ;;
    windows-aarch64)
      system="windows"
      arch="aarch64"
      common_sys="windows"
      target="aarch64-windows-gnu"
      tsil_platform="віндовс-аарч64"
      tsil_platform_folder="віндовс-аарч64"
      outfile="$PROGRAM_NAME.exe"
      clang_bin="$ZIG cc"
      extra_opts=""
      ;;
    android-aarch64)
      if [ -z "$ANDROID_NDK_HOME" ]; then
        echo "ANDROID_NDK_HOME is not set. Please set it to the path of your Android NDK."
        exit 1
      fi

      system="linux"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-linux-android21"
      tsil_platform="лінукс-аарч64"
      tsil_platform_folder="андроїд-аарч64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang"
      extra_opts="-ldl -lc -lm"

      setup_linux_libraries "$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ar" "$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ranlib" "$clang_bin" "$target" "" extra_opts static_libs
      ;;
    wasm64)
      system="wasm64"
      arch="wasm64"
      common_sys="wasm64"
      target="wasm64-unknown-unknown"
      tsil_platform="васм64"
      tsil_platform_folder="васм64"
      outfile="$PROGRAM_NAME.wasm"
      clang_bin="clang"
      extra_opts="-nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,--export-memory -Wl,--initial-memory=16777216 -Wl,--max-memory=1073741824"
      ;;
    *)
      echo "Unsupported build platform: $platform"
      exit 1
      ;;
  esac

  BUILD_SYSTEM="$system"
  BUILD_ARCH="$arch"
  COMMON_SYSTEM="$common_sys"
  TARGET_TRIPLE="$target"
  TSIL_PLATFORM="$tsil_platform"
  TSIL_PLATFORM_FOLDER="$tsil_platform_folder"
  OUTFILENAME="$outfile"
  CLANG="$clang_bin --target=$TARGET_TRIPLE"
  CLANG_OPTIONS+=" $extra_opts"
  STATIC_LIBS="$static_libs"
}

if [ -z "$BUILD_MODE" ] || [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

set_build_mode "$BUILD_MODE"
set_platform_vars "$BUILD_PLATFORM"

SEMIREADY_DIR="$CURRENT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/напівготове"
READY_DIR="$CURRENT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/готове"

prepare_directories() {
  mkdir -p "$SEMIREADY_DIR"/бібліотека/математика
  mkdir -p "$SEMIREADY_DIR"/бібліотека/читати
  mkdir -p "$READY_DIR"
}

compile_tsil() {
  local input_file="$1"

  echo "перетворення $input_file"
  $TSIL \
    "$(realpath --relative-to="$(pwd)" "$SEMIREADY_DIR/$input_file.ллвмір")" -П="$TSIL_PLATFORM" \
    перетворити \
    "$(realpath --relative-to="$(pwd)" "$input_file")" -О=./бібліотека/означення -О=./машина/означення
  mv "$SEMIREADY_DIR/$input_file.ллвмір" "$SEMIREADY_DIR/$input_file.ллвмір".ll

  LLIRFILES+=" $SEMIREADY_DIR/$input_file.ллвмір.ll"
}

compile_all_tsil_files() {
  compile_tsil "бібліотека/математика/_.ц"
  compile_tsil "бібліотека/математика/синус.ц"
  compile_tsil "бібліотека/математика/косинус.ц"
  compile_tsil "бібліотека/математика/тангенс.ц"
  compile_tsil "бібліотека/математика/арксинус.ц"
  compile_tsil "бібліотека/математика/арккосинус.ц"
  compile_tsil "бібліотека/математика/арктангенс.ц"
  compile_tsil "бібліотека/математика/абсолютне.ц"
  compile_tsil "бібліотека/математика/експонента.ц"
  compile_tsil "бібліотека/математика/корінь.ц"
  compile_tsil "бібліотека/математика/стеля.ц"
  compile_tsil "бібліотека/математика/підлога.ц"
  compile_tsil "бібліотека/математика/округлити.ц"
  compile_tsil "бібліотека/читати/_.ц"
  compile_tsil "бібліотека/бібліотека.ц"

  compile_tsil "старт.ц"
}

link_executable() {
  echo "створення виконуваного файлу"

  $CLANG $CLANG_OPTIONS \
         -o "$READY_DIR/$OUTFILENAME" \
         -Iмашина/external/include \
         -Iexternal/include \
         "external/$COMMON_SYSTEM/main_$COMMON_SYSTEM.c" \
         "external/$COMMON_SYSTEM/biblioteka_$COMMON_SYSTEM.c" \
         "external/$BUILD_SYSTEM/biblioteka_$BUILD_SYSTEM.c" \
         "машина/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/готове/машина.a" \
         $LLIRFILES \
         $STATIC_LIBS

  echo "готово!"
  echo "виконуваний файл: $READY_DIR/$OUTFILENAME"
}

cd машина
bash scripts/build.sh static "$BUILD_MODE" "$BUILD_PLATFORM"
cd -

prepare_directories
compile_all_tsil_files
link_executable