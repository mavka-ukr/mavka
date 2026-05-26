#!/bin/bash
set -e

CURRENT_DIR=$(pwd)

PROGRAM_NAME="машина"
BUILD_VERSION=$(cat ВЕРСІЯ)
BUILD_LINKAGE="$1"
BUILD_MODE="$2"
BUILD_PLATFORM="$3"

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

ZIG_AVAILABLE=false
if command -v "$ZIG" &> /dev/null; then
  ZIG_AVAILABLE=true
fi

CLANG_OPTIONS="-DPROGRAM_VERSION=\"$BUILD_VERSION\""
OBJECTFILES=""

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

set_platform_vars() {
  local platform="$1"
  local system arch common_sys target outfile clang_bin extra_opts

  case "$platform" in
    linux-x86_64)
      system="linux"
      arch="x86_64"
      common_sys="unix"
      target="x86_64-linux-gnu"
      tsil_platform="лінукс-ікс86_64"
      tsil_platform_folder="лінукс-ікс86_64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.so"
      fi
      extra_opts=""
      if [ "$ZIG_AVAILABLE" = true ]; then
        clang_bin="$ZIG cc"
        clangar_bin="$ZIG ar"
      else
        clang_bin="clang"
        clangar_bin="ar"
      fi
      ;;
    linux-aarch64)
      system="linux"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-linux-gnu"
      tsil_platform="лінукс-аарч64"
      tsil_platform_folder="лінукс-аарч64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.so"
      fi
      extra_opts=""
      if [ "$ZIG_AVAILABLE" = true ]; then
        clang_bin="$ZIG cc"
        clangar_bin="$ZIG ar"
      else
        clang_bin="clang"
        clangar_bin="ar"
      fi
      ;;
    macos-x86_64)
      system="macos"
      arch="x86_64"
      common_sys="unix"
      target="x86_64-macos"
      tsil_platform="макос-ікс86_64"
      tsil_platform_folder="макос-ікс86_64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.dylib"
      fi
      extra_opts=""
      if [ "$ZIG_AVAILABLE" = true ]; then
        clang_bin="$ZIG cc"
        clangar_bin="$ZIG ar"
      else
        clang_bin="clang"
        clangar_bin="ar"
      fi
      ;;
    macos-aarch64)
      system="macos"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-macos"
      tsil_platform="макос-аарч64"
      tsil_platform_folder="макос-аарч64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.dylib"
      fi
      extra_opts=""
      if [ "$ZIG_AVAILABLE" = true ]; then
        clang_bin="$ZIG cc"
        clangar_bin="$ZIG ar"
      else
        clang_bin="clang"
        clangar_bin="ar"
      fi
      ;;
    windows-x86_64)
      system="windows"
      arch="x86_64"
      common_sys="windows"
      target="x86_64-windows-gnu"
      tsil_platform="віндовс-ікс86_64"
      tsil_platform_folder="віндовс-ікс86_64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.dll"
      fi
      extra_opts=""
      if [ "$ZIG_AVAILABLE" = true ]; then
        clang_bin="$ZIG cc"
        clangar_bin="$ZIG ar"
      else
        clang_bin="clang"
        clangar_bin="ar"
      fi
      ;;
    windows-aarch64)
      system="windows"
      arch="aarch64"
      common_sys="windows"
      target="aarch64-windows-gnu"
      tsil_platform="віндовс-аарч64"
      tsil_platform_folder="віндовс-аарч64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.dll"
      fi
      extra_opts=""
      if [ "$ZIG_AVAILABLE" = true ]; then
        clang_bin="$ZIG cc"
        clangar_bin="$ZIG ar"
      else
        clang_bin="clang"
        clangar_bin="ar"
      fi
      ;;
    android-aarch64)
      if [ -z "$ANDROID_NDK_HOME" ]; then
        echo "ANDROID_NDK_HOME is not set. Please set it to the path of your Android NDK."
        exit 1
      fi

      system="linux"
      arch="aarch64"
      common_sys="unix"
      target="aarch64-linux-android24"
      tsil_platform="лінукс-аарч64"
      tsil_platform_folder="андроїд-аарч64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.so"
      fi
      extra_opts=""
      clang_bin="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android24-clang"
      clangar_bin="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ar"
      ;;
    wasm64)
      system="wasm64"
      arch="wasm64"
      common_sys="wasm64"
      target="wasm64-unknown-unknown"
      tsil_platform="васм64"
      tsil_platform_folder="васм64"
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.wasm"
      fi
      extra_opts="-nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined"
      clang_bin="clang"
      clangar_bin="llvm-ar"
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
  CLANGAR="$clangar_bin"
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
  mkdir -p "$SEMIREADY_DIR"/КД
  mkdir -p "$SEMIREADY_DIR"/предмети/Дані/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ДіапазонЧисел/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Дія/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Код/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Модуль/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Параметр/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ПеребірДаних/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ПеребірДіапазонуЧисел/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ПеребірПослідовності/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ПеребірСловника/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ПеребірСписку/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/ПеребірТексту/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Послідовність/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Словник/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Список/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Структура/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Текст/дії
  mkdir -p "$SEMIREADY_DIR"/предмети/Текст/методи
  mkdir -p "$SEMIREADY_DIR"/предмети/Число/дії
  mkdir -p "$SEMIREADY_DIR"/предмети/Число/методи
  mkdir -p "$SEMIREADY_DIR"/перекладач
  mkdir -p "$SEMIREADY_DIR"/пристрій
  mkdir -p "$SEMIREADY_DIR"/розбирач
  mkdir -p "$READY_DIR"
}

compile_tsil() {
  local input_file="$1"

  echo "перетворення $input_file"
  $TSIL \
    "$(realpath --relative-to="$(pwd)" "$SEMIREADY_DIR/$input_file.ллвмір")" -П="$TSIL_PLATFORM" \
    перетворити \
    "$(realpath --relative-to="$(pwd)" "$input_file")" -О=./КД/означення -О=./означення
  mv "$SEMIREADY_DIR/$input_file.ллвмір" "$SEMIREADY_DIR/$input_file.ллвмір".ll

  $CLANG $CLANG_OPTIONS \
         -o "$SEMIREADY_DIR/$input_file.ллвмір.ll.o" \
         -Iexternal/include \
         -c \
         "$SEMIREADY_DIR/$input_file.ллвмір.ll"

  OBJECTFILES+=" $SEMIREADY_DIR/$input_file.ллвмір.ll.o"
}

compile_all_tsil_files() {
  compile_tsil "КД/КД.к"


  compile_tsil "ВзятіЗначення.к"
  compile_tsil "Дійсність.к"
  compile_tsil "Призначення.к"
  compile_tsil "Допоміжне.к"
  compile_tsil "Задіяні.к"
  compile_tsil "Значення.к"
  compile_tsil "ІнформаціяПадіння.к"
  compile_tsil "КористувацькіДані.к"
  compile_tsil "Машина.к"
  compile_tsil "МісцезнаходженняВказівок.к"
  compile_tsil "НакопичувачТексту.к"
  compile_tsil "Очищувач.к"
  compile_tsil "Притримувач.к"
  compile_tsil "Спроби.к"

  compile_tsil "предмети/Дані/методи/чародія_перебір.к"
  compile_tsil "предмети/Дані/ПредметДаних.к"

  compile_tsil "предмети/ДіапазонЧисел/методи/чародія_перебір.к"
  compile_tsil "предмети/ДіапазонЧисел/ПредметДіапазонуЧисел.к"

  compile_tsil "предмети/Дія/ПредметДії.к"

  compile_tsil "предмети/Код/ПредметКоду.к"

  compile_tsil "предмети/Модуль/ПредметМодуля.к"

  compile_tsil "предмети/Параметр/ПредметПараметра.к"

  compile_tsil "предмети/ПеребірДаних/методи/далі.к"
  compile_tsil "предмети/ПеребірДаних/ПредметПереборуДаних.к"

  compile_tsil "предмети/ПеребірДіапазонуЧисел/методи/далі.к"
  compile_tsil "предмети/ПеребірДіапазонуЧисел/ПредметПереборуДіапазонуЧисел.к"

  compile_tsil "предмети/ПеребірПослідовності/методи/далі.к"
  compile_tsil "предмети/ПеребірПослідовності/ПредметПереборуПослідовності.к"

  compile_tsil "предмети/ПеребірСловника/методи/далі.к"
  compile_tsil "предмети/ПеребірСловника/ПредметПереборуСловника.к"

  compile_tsil "предмети/ПеребірСписку/методи/далі.к"
  compile_tsil "предмети/ПеребірСписку/ПредметПереборуСписку.к"

  compile_tsil "предмети/ПеребірТексту/методи/далі.к"
  compile_tsil "предмети/ПеребірТексту/ПредметПереборуТексту.к"

  compile_tsil "предмети/Послідовність/методи/чародія_перебір.к"
  compile_tsil "предмети/Послідовність/ПредметПослідовності.к"

  compile_tsil "предмети/Словник/методи/значення.к"
  compile_tsil "предмети/Словник/методи/ключі.к"
  compile_tsil "предмети/Словник/методи/містить.к"
  compile_tsil "предмети/Словник/методи/чародія_перебір.к"
  compile_tsil "предмети/Словник/методи/чародія_текст.к"
  compile_tsil "предмети/Словник/ПредметСловника.к"

  compile_tsil "предмети/Список/методи/чародія_текст.к"
  compile_tsil "предмети/Список/методи/чародія_перебір.к"
  compile_tsil "предмети/Список/методи/додати.к"
  compile_tsil "предмети/Список/методи/забрати.к"
  compile_tsil "предмети/Список/методи/знайти.к"
  compile_tsil "предмети/Список/методи/знайти_позицію.к"
  compile_tsil "предмети/Список/методи/фільтрований.к"
  compile_tsil "предмети/Список/методи/перетворений.к"
  compile_tsil "предмети/Список/методи/обернений.к"
  compile_tsil "предмети/Список/методи/містить.к"
  compile_tsil "предмети/Список/ПредметСписку.к"

  compile_tsil "предмети/Структура/ПредметСтруктури.к"

  compile_tsil "предмети/Текст/дії/з.к"
  compile_tsil "предмети/Текст/методи/чародія_перебір.к"
  compile_tsil "предмети/Текст/методи/чародія_текст.к"
  compile_tsil "предмети/Текст/методи/чародія_число.к"
  compile_tsil "предмети/Текст/ПредметТексту.к"

  compile_tsil "предмети/Число/дії/з.к"
  compile_tsil "предмети/Число/методи/чародія_текст.к"
  compile_tsil "предмети/Число/методи/чародія_число.к"
  compile_tsil "предмети/Число/ПредметЧисла.к"

  compile_tsil "предмети/СкладенийПредмет.к"


  compile_tsil "перекладач/перекладач.к"


  compile_tsil "розбирач/розбирач.к"


  compile_tsil "пристрій/взяти_файл.к"
  compile_tsil "пристрій/вивід.к"
  compile_tsil "пристрій/глобальні.к"
  compile_tsil "пристрій/діалог.к"
  compile_tsil "пристрій/машина.к"
  compile_tsil "пристрій/пристрій.к"
}

link_executable() {
  case "$BUILD_LINKAGE" in
    static)
      echo "створення архіву"

      $CLANG $CLANG_OPTIONS \
             -o "$SEMIREADY_DIR/prystriy_$COMMON_SYSTEM.o" \
             -Iexternal/include \
             -c \
             "external/$COMMON_SYSTEM/prystriy_$COMMON_SYSTEM.c"

      mv "$READY_DIR/$OUTFILENAME" "$READY_DIR/$OUTFILENAME.old" 2>/dev/null || true

      $CLANGAR rcs "$READY_DIR/$OUTFILENAME" $OBJECTFILES "$SEMIREADY_DIR/prystriy_$COMMON_SYSTEM.o"

      echo "готово!"
      echo "файл архіву: $READY_DIR/$OUTFILENAME"
      ;;
    dynamic)
      echo "створення динамічної бібліотеки"

      mv "$READY_DIR/$OUTFILENAME" "$READY_DIR/$OUTFILENAME.old" 2>/dev/null || true

      $CLANG $CLANG_OPTIONS \
             -o "$READY_DIR/$OUTFILENAME" \
             -Iexternal/include \
             -shared -fPIC \
             "external/$COMMON_SYSTEM/prystriy_$COMMON_SYSTEM.c" \
             $OBJECTFILES

      echo "готово!"
      echo "файл динамічної бібліотеки: $READY_DIR/$OUTFILENAME"
      ;;
    *)
      echo "Unsupported linkage type: $BUILD_LINKAGE"
      print_usage
      exit 1 ;;
  esac
}

prepare_directories
compile_all_tsil_files
link_executable