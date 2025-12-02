#!/bin/bash
set -e

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat ВЕРСІЯ)
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
  echo "Supported platforms: linux-x86_64, linux-aarch64, macos-x86_64, macos-aarch64, windows-x86_64, windows-aarch64"
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

download_and_extract_if_needed() {
  local tarball="$1"
  local url="$2"
  local extract_dir="$3"

  if [ ! -f "будування/$tarball" ]; then
    mkdir -p будування
    cd будування
    wget "$url"
    cd -
  fi

  if [ ! -d "$extract_dir" ]; then
    mkdir -p "$(dirname "$extract_dir")"
    cd "$(dirname "$extract_dir")"
    tar -xvf "../../$tarball"
    cd -
  fi
}

build_ncurses() {
  local tsil_system="$1"
  local tsil_arch="$2"
  local compiler="$3"
  local target="$4"

  local ncurses_dir="будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4"
  local build_dir="$ncurses_dir/build_ncurses"

  download_and_extract_if_needed "ncurses-6.4.tar.gz" \
    "https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.4.tar.gz" \
    "$ncurses_dir"

  if [ ! -d "$build_dir" ]; then
    cd "$ncurses_dir"
    if [ -n "$target" ]; then
      CC="$compiler" CFLAGS="-O3" LDFLAGS="-static" \
        ./configure --host="$target" --prefix="$(pwd)/build_ncurses" --with-shared=no --with-static=yes
    else
      CC="$compiler" ./configure --prefix="$(pwd)/build_ncurses" --with-shared=no --with-static=yes \
        CFLAGS="-O3" LDFLAGS="-static"
    fi
    make
    make install
    cd -
  fi

  echo "$build_dir"
}

build_readline() {
  local tsil_system="$1"
  local tsil_arch="$2"
  local compiler="$3"
  local target="$4"
  local ncurses_build_dir="$5"

  local readline_dir="будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2"
  local build_dir="$readline_dir/build_readline"

  download_and_extract_if_needed "readline-8.2.tar.gz" \
    "https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz" \
    "$readline_dir"

  if [ ! -d "$build_dir" ]; then
    cd "$readline_dir"
    local ncurses_include="-I$(pwd)/../ncurses-6.4/build_ncurses/include"
    local ncurses_lib="-L$(pwd)/../ncurses-6.4/build_ncurses/lib"

    if [ -n "$target" ]; then
      CC="$compiler" CFLAGS="-O3 $ncurses_include" LDFLAGS="-static $ncurses_lib" \
        ./configure --host="$target" --prefix="$(pwd)/build_readline" --enable-static --disable-shared --with-curses
    else
      CC="$compiler" CFLAGS="-O3 $ncurses_include" LDFLAGS="-static $ncurses_lib" \
        ./configure --prefix="$(pwd)/build_readline" --enable-static --disable-shared --with-curses
    fi
    make
    make install
    cd -
  fi

  echo "$build_dir"
}

setup_linux_libraries() {
  local tsil_system="$1"
  local tsil_arch="$2"
  local compiler="$3"
  local target="$4"
  local extra_opts_var="$5"
  local static_libs_var="$6"

  if [ "$BUILD_MODE" = "release" ]; then
    build_ncurses "$tsil_system" "$tsil_arch" "$compiler" "$target" > /dev/tty
    local ncurses_build=$(build_ncurses "$tsil_system" "$tsil_arch" "$compiler" "$target" 2>&1 | tail -n 1)

    build_readline "$tsil_system" "$tsil_arch" "$compiler" "$target" "$ncurses_build" > /dev/tty
    local readline_build=$(build_readline "$tsil_system" "$tsil_arch" "$compiler" "$target" "$ncurses_build" 2>&1 | tail -n 1)

    eval "$extra_opts_var+=\" -I$(pwd)/$ncurses_build/include\""
    eval "$extra_opts_var+=\" -DPROGRAM_USE_READLINE -I$(pwd)/$readline_build/include\""

    eval "$static_libs_var+=\" $(pwd)/$readline_build/lib/libreadline.a\""
    eval "$static_libs_var+=\" $(pwd)/$readline_build/lib/libhistory.a\""
    eval "$static_libs_var+=\" $(pwd)/$ncurses_build/lib/libncurses.a\""
    eval "$static_libs_var+=\" $(pwd)/$ncurses_build/lib/libform.a\""
    eval "$static_libs_var+=\" $(pwd)/$ncurses_build/lib/libpanel.a\""
  fi

  if [ "$BUILD_MODE" = "debug" ]; then
    eval "$extra_opts_var+=\" -DPROGRAM_USE_READLINE -lreadline\""
  fi
}

set_platform_vars() {
  local platform="$1"
  local system arch common_sys target tsil_system tsil_arch outfile clang_bin extra_opts static_libs

  case "$platform" in
    linux-x86_64)
      system="linux"
      arch="x86_64"
      common_sys="unix"
      target="x86_64-pc-linux-gnu"
      tsil_system="лінукс"
      tsil_arch="ікс86_64"
      outfile="$PROGRAM_NAME"
      clang_bin="clang"
      extra_opts="-lm"

      setup_linux_libraries "$tsil_system" "$tsil_arch" "$CLANG" "" extra_opts static_libs
      ;;
    linux-aarch64)
      system="linux"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-linux-gnu"
      tsil_system="лінукс"
      tsil_arch="аарч64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts="-lm"

      setup_linux_libraries "$tsil_system" "$tsil_arch" "$ZIG cc --target=$target" "$target" extra_opts static_libs
      ;;
    macos-x86_64)
      system="macos"
      arch="x86_64"
      common_sys="unix"
      target="x86_64-macos"
      tsil_system="макос"
      tsil_arch="ікс86_64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts="-lm"
      ;;
    macos-aarch64)
      system="macos"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-macos"
      tsil_system="макос"
      tsil_arch="аарч64"
      outfile="$PROGRAM_NAME"
      clang_bin="$ZIG cc"
      extra_opts="-lm"
      ;;
    windows-x86_64)
      system="windows"
      arch="x86_64"
      common_sys="windows"
      target="x86_64-windows-gnu"
      tsil_system="віндовс"
      tsil_arch="ікс86_64"
      outfile="$PROGRAM_NAME.exe"
      clang_bin="$ZIG cc"
      extra_opts=""
      ;;
    windows-aarch64)
      system="windows"
      arch="aarch64"
      common_sys="windows"
      target="aarch64-windows-gnu"
      tsil_system="віндовс"
      tsil_arch="аарч64"
      outfile="$PROGRAM_NAME.exe"
      clang_bin="$ZIG cc"
      extra_opts=""
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
  TSIL_PLATFORM="$tsil_system-$tsil_arch"
  OUTFILENAME="$outfile"
  CLANG="$clang_bin"
  CLANG_OPTIONS+=" $extra_opts"
  STATIC_LIBS="$static_libs"
}

if [ -z "$BUILD_MODE" ] || [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

set_build_mode "$BUILD_MODE"
set_platform_vars "$BUILD_PLATFORM"

SEMIREADY_DIR="будування/$BUILD_VERSION/$TSIL_PLATFORM/напівготове"
READY_DIR="будування/$BUILD_VERSION/$TSIL_PLATFORM/готове"

prepare_directories() {
  mkdir -p "$SEMIREADY_DIR"/бібліотека
  mkdir -p "$SEMIREADY_DIR"/КД
  mkdir -p "$SEMIREADY_DIR"/машина/предмети
  mkdir -p "$SEMIREADY_DIR"/перетворювач
  mkdir -p "$SEMIREADY_DIR"/пристрій
  mkdir -p "$SEMIREADY_DIR"/розбирач
  mkdir -p "$READY_DIR"
}

compile_tsil() {
  local input_file="$1"

  echo "перетворення $input_file"
  $TSIL "$SEMIREADY_DIR/$input_file.ллвмір" --платформа="$TSIL_PLATFORM" перетворити "$input_file"
  mv "$SEMIREADY_DIR/$input_file.ллвмір" "$SEMIREADY_DIR/$input_file.ллвмір".ll

  LLIRFILES+=" $SEMIREADY_DIR/$input_file.ллвмір.ll"
}

compile_all_tsil_files() {
  compile_tsil "бібліотека/бібліотека.ц"
  compile_tsil "бібліотека/математика.ц"
  compile_tsil "бібліотека/читати.ц"
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
  compile_tsil "перетворювач/перетворювач.ц"
  compile_tsil "пристрій/взяти_файл.ц"
  compile_tsil "пристрій/вивід.ц"
  compile_tsil "пристрій/глобальні.ц"
  compile_tsil "пристрій/діалог.ц"
  compile_tsil "пристрій/машина.ц"
  compile_tsil "пристрій/пристрій.ц"
  compile_tsil "розбирач/розбирач.ц"
  compile_tsil "старт.ц"
}

link_executable() {
  echo "створення виконуваного файлу"

  $CLANG --target="$TARGET_TRIPLE" \
         $CLANG_OPTIONS \
         -o "$READY_DIR/$OUTFILENAME" \
         "external/$COMMON_SYSTEM/main_$COMMON_SYSTEM.c" \
         "external/$COMMON_SYSTEM/prystriy_$COMMON_SYSTEM.c" \
         "external/$COMMON_SYSTEM/biblioteka_$COMMON_SYSTEM.c" \
         "external/$BUILD_SYSTEM/biblioteka_$BUILD_SYSTEM.c" \
         $LLIRFILES \
         $STATIC_LIBS

  echo "готово!"
  echo "виконуваний файл: $READY_DIR/$OUTFILENAME"
}

prepare_directories
compile_all_tsil_files
link_executable