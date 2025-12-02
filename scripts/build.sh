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

set_platform_vars() {
  local platform="$1"
  local system arch common_sys target tsil_system tsil_arch outfile clang_bin extra_opts static_libs

  case "$platform" in
    linux-x86_64)
      system="linux"; arch="x86_64"; common_sys="unix"; target="x86_64-pc-linux-gnu"
      tsil_system="лінукс"; tsil_arch="ікс86_64"; outfile="$PROGRAM_NAME"; clang_bin="clang"; extra_opts="-lm"

      if [ "$BUILD_MODE" = "release" ]; then
        # ncurses
        if [ ! -f будування/ncurses-6.4.tar.gz ]; then
          mkdir -p будування
          cd будування
          wget https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.4.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4" ]; then
          mkdir -p "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          tar -xvf ../../ncurses-6.4.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses" ]; then
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4"
          CC="$CLANG" ./configure --prefix=$(pwd)/build_ncurses --with-shared=no --with-static=yes CFLAGS="-O3" LDFLAGS="-static"
          make
          make install
          cd -
        fi
        extra_opts+=" -I$(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/include"

        # readline
        if [ ! -f будування/readline-8.2.tar.gz ]; then
          mkdir -p будування
          cd будування
          wget https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2" ]; then
          mkdir -p "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          tar -xvf ../../readline-8.2.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline" ]; then
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2"
          CC="$CLANG" CFLAGS="-O3 -I$(pwd)/../$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/include" LDFLAGS="-static -L$(pwd)/../$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib" ./configure --prefix=$(pwd)/build_readline --enable-static --disable-shared --with-curses
          make
          make install
          cd -
        fi
        extra_opts+=" -DPROGRAM_USE_READLINE -I$(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline/include"

        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline/lib/libreadline.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline/lib/libhistory.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib/libncurses.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib/libform.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib/libpanel.a"
      fi

      if [ "$BUILD_MODE" = "debug" ]; then
        extra_opts+=" -lreadline"
      fi
      ;;
    linux-aarch64)
      system="linux"; arch="aarch64"; common_sys="unix"; target="aarch64-linux-gnu"
      tsil_system="лінукс"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME"; clang_bin="$ZIG cc"; extra_opts="-lm"

      if [ "$BUILD_MODE" = "release" ]; then
        # ncurses
        if [ ! -f будування/ncurses-6.4.tar.gz ]; then
          mkdir -p будування
          cd будування
          wget https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.4.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4" ]; then
          mkdir -p "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          tar -xvf ../../ncurses-6.4.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses" ]; then
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4"
          CC="$ZIG cc --target=$target" CFLAGS="-O3" LDFLAGS="-static" ./configure --host=$target --prefix=$(pwd)/build_ncurses --with-shared=no --with-static=yes
          make
          make install
          cd -
        fi
        extra_opts+=" -I$(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/include"

        # readline
        if [ ! -f будування/readline-8.2.tar.gz ]; then
          mkdir -p будування
          cd будування
          wget https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2" ]; then
          mkdir -p "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch"
          tar -xvf ../../readline-8.2.tar.gz
          cd -
        fi
        if [ ! -d "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline" ]; then
          cd "будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2"
          CC="$ZIG cc --target=$target" CFLAGS="-O3 -I$(pwd)/../$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/include" LDFLAGS="-static -L$(pwd)/../$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib" ./configure --host=$target --prefix=$(pwd)/build_readline --enable-static --disable-shared --with-curses
          make
          make install
          cd -
        fi
        extra_opts+=" -DPROGRAM_USE_READLINE -I$(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline/include"

        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline/lib/libreadline.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/readline-8.2/build_readline/lib/libhistory.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib/libncurses.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib/libform.a"
        static_libs+=" $(pwd)/будування/$BUILD_VERSION/$tsil_system-$tsil_arch/ncurses-6.4/build_ncurses/lib/libpanel.a"
      fi

      if [ "$BUILD_MODE" = "debug" ]; then
        extra_opts+=" -lreadline"
      fi

      ;;
    macos-x86_64)
      system="macos"; arch="x86_64"; common_sys="unix"; target="x86_64-macos"
      tsil_system="макос"; tsil_arch="ікс86_64"; outfile="$PROGRAM_NAME"; clang_bin="$ZIG cc"; extra_opts="-lm" ;;
    macos-aarch64)
      system="macos"; arch="aarch64"; common_sys="unix"; target="aarch64-macos"
      tsil_system="макос"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME"; clang_bin="$ZIG cc"; extra_opts="-lm" ;;
    windows-x86_64)
      system="windows"; arch="x86_64"; common_sys="windows"; target="x86_64-windows-gnu"
      tsil_system="віндовс"; tsil_arch="ікс86_64"; outfile="$PROGRAM_NAME.exe"; clang_bin="$ZIG cc"; extra_opts="" ;;
    windows-aarch64)
      system="windows"; arch="aarch64"; common_sys="windows"; target="aarch64-windows-gnu"
      tsil_system="віндовс"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME.exe"; clang_bin="$ZIG cc"; extra_opts="" ;;
    *)
      echo "Unsupported build platform: $platform"
      exit 1 ;;
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