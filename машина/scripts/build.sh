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
      clang_bin="$ZIG cc"
      extra_opts=""
      clangar_bin="$ZIG ar"
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
      clang_bin="$ZIG cc"
      extra_opts=""
      clangar_bin="$ZIG ar"
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
      clang_bin="$ZIG cc"
      extra_opts=""
      clangar_bin="$ZIG ar"
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
      clang_bin="$ZIG cc"
      extra_opts=""
      clangar_bin="$ZIG ar"
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
      clang_bin="$ZIG cc"
      extra_opts=""
      clangar_bin="$ZIG ar"
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
      clang_bin="$ZIG cc"
      extra_opts=""
      clangar_bin="$ZIG ar"
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
      if [ "$BUILD_LINKAGE" == "static" ]; then
        outfile="$PROGRAM_NAME.a"
      else
        outfile="$PROGRAM_NAME.so"
      fi
      clang_bin="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang"
      extra_opts=""
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
      clang_bin="clang"
      extra_opts="-nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined"
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
  mkdir -p "$SEMIREADY_DIR"/ДЧ
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
  mkdir -p "$SEMIREADY_DIR"/перетворювач
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
    "$(realpath --relative-to="$(pwd)" "$input_file")" -О=./бібліотека/означення -О=./означення
  mv "$SEMIREADY_DIR/$input_file.ллвмір" "$SEMIREADY_DIR/$input_file.ллвмір".ll

  $CLANG $CLANG_OPTIONS \
         -o "$SEMIREADY_DIR/$input_file.ллвмір.ll.o" \
         -Iexternal/include \
         -c \
         "$SEMIREADY_DIR/$input_file.ллвмір.ll"

  OBJECTFILES+=" $SEMIREADY_DIR/$input_file.ллвмір.ll.o"
}

compile_all_tsil_files() {
  compile_tsil "КД/КД.ц"


  compile_tsil "ВзятіЗначення.ц"
  compile_tsil "Дійсність.ц"
  compile_tsil "Діячі.ц"
  compile_tsil "Допоміжне.ц"
  compile_tsil "Задіяні.ц"
  compile_tsil "Значення.ц"
  compile_tsil "ІменованоЗадіяні.ц"
  compile_tsil "ІнформаціяПадіння.ц"
  compile_tsil "КористувацькіДані.ц"
  compile_tsil "Машина.ц"
  compile_tsil "МісцезнаходженняВказівок.ц"
  compile_tsil "НакопичувачТексту.ц"
  compile_tsil "Очищувач.ц"
  compile_tsil "Притримувач.ц"
  compile_tsil "Спроби.ц"

  compile_tsil "предмети/Дані/методи/чародія_перебір.ц"
  compile_tsil "предмети/Дані/ПредметДаних.ц"

  compile_tsil "предмети/ДіапазонЧисел/методи/чародія_перебір.ц"
  compile_tsil "предмети/ДіапазонЧисел/ПредметДіапазонуЧисел.ц"

  compile_tsil "предмети/Дія/ПредметДії.ц"

  compile_tsil "предмети/Код/ПредметКоду.ц"

  compile_tsil "предмети/Модуль/ПредметМодуля.ц"

  compile_tsil "предмети/Параметр/ПредметПараметра.ц"

  compile_tsil "предмети/ПеребірДаних/методи/далі.ц"
  compile_tsil "предмети/ПеребірДаних/ПредметПереборуДаних.ц"

  compile_tsil "предмети/ПеребірДіапазонуЧисел/методи/далі.ц"
  compile_tsil "предмети/ПеребірДіапазонуЧисел/ПредметПереборуДіапазонуЧисел.ц"

  compile_tsil "предмети/ПеребірПослідовності/методи/далі.ц"
  compile_tsil "предмети/ПеребірПослідовності/ПредметПереборуПослідовності.ц"

  compile_tsil "предмети/ПеребірСловника/методи/далі.ц"
  compile_tsil "предмети/ПеребірСловника/ПредметПереборуСловника.ц"

  compile_tsil "предмети/ПеребірСписку/методи/далі.ц"
  compile_tsil "предмети/ПеребірСписку/ПредметПереборуСписку.ц"

  compile_tsil "предмети/ПеребірТексту/методи/далі.ц"
  compile_tsil "предмети/ПеребірТексту/ПредметПереборуТексту.ц"

  compile_tsil "предмети/Послідовність/методи/чародія_перебір.ц"
  compile_tsil "предмети/Послідовність/ПредметПослідовності.ц"

  compile_tsil "предмети/Словник/методи/значення.ц"
  compile_tsil "предмети/Словник/методи/ключі.ц"
  compile_tsil "предмети/Словник/методи/містить.ц"
  compile_tsil "предмети/Словник/методи/чародія_перебір.ц"
  compile_tsil "предмети/Словник/методи/чародія_текст.ц"
  compile_tsil "предмети/Словник/ПредметСловника.ц"

  compile_tsil "предмети/Список/методи/чародія_текст.ц"
  compile_tsil "предмети/Список/методи/чародія_перебір.ц"
  compile_tsil "предмети/Список/методи/додати.ц"
  compile_tsil "предмети/Список/методи/забрати.ц"
  compile_tsil "предмети/Список/методи/знайти.ц"
  compile_tsil "предмети/Список/методи/знайти_позицію.ц"
  compile_tsil "предмети/Список/методи/фільтрований.ц"
  compile_tsil "предмети/Список/методи/перетворений.ц"
  compile_tsil "предмети/Список/методи/обернений.ц"
  compile_tsil "предмети/Список/методи/містить.ц"
  compile_tsil "предмети/Список/ПредметСписку.ц"

  compile_tsil "предмети/Структура/ПредметСтруктури.ц"

  compile_tsil "предмети/Текст/дії/з.ц"
  compile_tsil "предмети/Текст/методи/чародія_перебір.ц"
  compile_tsil "предмети/Текст/методи/чародія_текст.ц"
  compile_tsil "предмети/Текст/методи/чародія_число.ц"
  compile_tsil "предмети/Текст/ПредметТексту.ц"

  compile_tsil "предмети/Число/дії/з.ц"
  compile_tsil "предмети/Число/методи/чародія_текст.ц"
  compile_tsil "предмети/Число/методи/чародія_число.ц"
  compile_tsil "предмети/Число/ПредметЧисла.ц"

  compile_tsil "предмети/СкладенийПредмет.ц"


  compile_tsil "перетворювач/перетворювач.ц"


  compile_tsil "розбирач/розбирач.ц"


  compile_tsil "пристрій/взяти_файл.ц"
  compile_tsil "пристрій/вивід.ц"
  compile_tsil "пристрій/глобальні.ц"
  compile_tsil "пристрій/діалог.ц"
  compile_tsil "пристрій/машина.ц"
  compile_tsil "пристрій/пристрій.ц"
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