#!/bin/bash
set -x
set -e

BUILD_PLATFORM="$1"
BUILD_ARCH=""
BUILD_SYSTEM=""
COMMON_SYSTEM=""
TARGET_TRIPLE=""
TSIL_ARCH=""
TSIL_SYSTEM=""
OUTFILENAME=""

TSIL="ціль0480"
CLANG="clang"

if [ -z "$BUILD_PLATFORM" ]; then
  echo "Usage: $0 <x86_64-linux|aarch64-linux|x86_64-windows|aarch64-windows|x86-windows|x86_64-macos|aarch64-macos>"
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
elif [[ "$BUILD_PLATFORM" == "aarch64-linux" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="linux"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="aarch64-linux-gnu"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="лінукс"
  CLANG="zig cc"
  OUTFILENAME="мавка"
elif [[ "$BUILD_PLATFORM" == "x86_64-windows" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="windows"
  COMMON_SYSTEM="windows"
  TARGET_TRIPLE="x86_64-windows-gnu"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="віндовс"
  CLANG="zig cc"
  OUTFILENAME="mavka.exe"
elif [[ "$BUILD_PLATFORM" == "aarch64-windows" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="windows"
  COMMON_SYSTEM="windows"
  TARGET_TRIPLE="aarch64-windows-gnu"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="віндовс"
  CLANG="zig cc"
  OUTFILENAME="mavka.exe"
elif [[ "$BUILD_PLATFORM" == "x86-windows" ]]; then
  BUILD_ARCH="x86"
  BUILD_SYSTEM="windows"
  COMMON_SYSTEM="windows"
  TARGET_TRIPLE="x86-windows-gnu"
  TSIL_ARCH="ікс86"
  TSIL_SYSTEM="віндовс"
  CLANG="zig cc"
  OUTFILENAME="mavka.exe"
elif [[ "$BUILD_PLATFORM" == "x86_64-macos" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="macos"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="x86_64-macos"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="макос"
  CLANG="zig cc"
  OUTFILENAME="мавка"
elif [[ "$BUILD_PLATFORM" == "aarch64-macos" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="macos"
  COMMON_SYSTEM="unix"
  TARGET_TRIPLE="aarch64-macos"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="макос"
  CLANG="zig cc"
  OUTFILENAME="мавка"
else
  echo "Unsupported build platform: $BUILD_PLATFORM"
  exit 1
fi

SEMIRAW_DIR="будування/$TSIL_ARCH-$TSIL_SYSTEM/напівготове"
READY_DIR="будування/$TSIL_ARCH-$TSIL_SYSTEM/готове"

mkdir -p "$SEMIRAW_DIR"/бібліотека
mkdir -p "$SEMIRAW_DIR"/КД
mkdir -p "$SEMIRAW_DIR"/машина
mkdir -p "$SEMIRAW_DIR"/перекладач
mkdir -p "$SEMIRAW_DIR"/пристрій
mkdir -p "$SEMIRAW_DIR"/розбирач
mkdir -p "$READY_DIR"

$TSIL "$SEMIRAW_DIR"/бібліотека/математика.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити бібліотека/математика.ц
mv "$SEMIRAW_DIR"/бібліотека/математика.ц.ллвмір "$SEMIRAW_DIR"/бібліотека/математика.ц.ll

$TSIL "$SEMIRAW_DIR"/КД/КД.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити КД/КД.ц
mv "$SEMIRAW_DIR"/КД/КД.ц.ллвмір "$SEMIRAW_DIR"/КД/КД.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ВзятіЗначення.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ВзятіЗначення.ц
mv "$SEMIRAW_DIR"/машина/ВзятіЗначення.ц.ллвмір "$SEMIRAW_DIR"/машина/ВзятіЗначення.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Дійсність.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Дійсність.ц
mv "$SEMIRAW_DIR"/машина/Дійсність.ц.ллвмір "$SEMIRAW_DIR"/машина/Дійсність.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Допоміжне.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Допоміжне.ц
mv "$SEMIRAW_DIR"/машина/Допоміжне.ц.ллвмір "$SEMIRAW_DIR"/машина/Допоміжне.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Значення.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Значення.ц
mv "$SEMIRAW_DIR"/машина/Значення.ц.ллвмір "$SEMIRAW_DIR"/машина/Значення.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ІменованоЗадіяні.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ІменованоЗадіяні.ц
mv "$SEMIRAW_DIR"/машина/ІменованоЗадіяні.ц.ллвмір "$SEMIRAW_DIR"/машина/ІменованоЗадіяні.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ІнформаціяПадіння.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ІнформаціяПадіння.ц
mv "$SEMIRAW_DIR"/машина/ІнформаціяПадіння.ц.ллвмір "$SEMIRAW_DIR"/машина/ІнформаціяПадіння.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/КористувацькіДані.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/КористувацькіДані.ц
mv "$SEMIRAW_DIR"/машина/КористувацькіДані.ц.ллвмір "$SEMIRAW_DIR"/машина/КористувацькіДані.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Машина.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Машина.ц
mv "$SEMIRAW_DIR"/машина/Машина.ц.ллвмір "$SEMIRAW_DIR"/машина/Машина.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/МісцезнаходженняВказівок.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/МісцезнаходженняВказівок.ц
mv "$SEMIRAW_DIR"/машина/МісцезнаходженняВказівок.ц.ллвмір "$SEMIRAW_DIR"/машина/МісцезнаходженняВказівок.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/НакопичувачТексту.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/НакопичувачТексту.ц
mv "$SEMIRAW_DIR"/машина/НакопичувачТексту.ц.ллвмір "$SEMIRAW_DIR"/машина/НакопичувачТексту.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Очищувач.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Очищувач.ц
mv "$SEMIRAW_DIR"/машина/Очищувач.ц.ллвмір "$SEMIRAW_DIR"/машина/Очищувач.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Послідовність.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Послідовність.ц
mv "$SEMIRAW_DIR"/машина/Послідовність.ц.ллвмір "$SEMIRAW_DIR"/машина/Послідовність.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметДаних.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметДаних.ц
mv "$SEMIRAW_DIR"/машина/ПредметДаних.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметДаних.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметДіапазонуДробових.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметДіапазонуДробових.ц
mv "$SEMIRAW_DIR"/машина/ПредметДіапазонуДробових.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметДіапазонуДробових.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметДіапазонуЦілих.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметДіапазонуЦілих.ц
mv "$SEMIRAW_DIR"/машина/ПредметДіапазонуЦілих.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметДіапазонуЦілих.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметДії.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметДії.ц
mv "$SEMIRAW_DIR"/машина/ПредметДії.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметДії.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметДробового.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметДробового.ц
mv "$SEMIRAW_DIR"/машина/ПредметДробового.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметДробового.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметЗміннихДаних.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметЗміннихДаних.ц
mv "$SEMIRAW_DIR"/машина/ПредметЗміннихДаних.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметЗміннихДаних.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметКоду.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметКоду.ц
mv "$SEMIRAW_DIR"/машина/ПредметКоду.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметКоду.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметМодуля.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметМодуля.ц
mv "$SEMIRAW_DIR"/машина/ПредметМодуля.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметМодуля.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметПараметра.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметПараметра.ц
mv "$SEMIRAW_DIR"/машина/ПредметПараметра.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметПараметра.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуДробових.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметПереборуДіапазонуДробових.ц
mv "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуДробових.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуДробових.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуЦілих.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметПереборуДіапазонуЦілих.ц
mv "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуЦілих.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуЦілих.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметПереборуСписку.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметПереборуСписку.ц
mv "$SEMIRAW_DIR"/машина/ПредметПереборуСписку.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметПереборуСписку.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметСловника.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметСловника.ц
mv "$SEMIRAW_DIR"/машина/ПредметСловника.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметСловника.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметСписку.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметСписку.ц
mv "$SEMIRAW_DIR"/машина/ПредметСписку.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметСписку.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметСтруктури.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметСтруктури.ц
mv "$SEMIRAW_DIR"/машина/ПредметСтруктури.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметСтруктури.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметТексту.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметТексту.ц
mv "$SEMIRAW_DIR"/машина/ПредметТексту.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметТексту.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/ПредметЦілого.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/ПредметЦілого.ц
mv "$SEMIRAW_DIR"/машина/ПредметЦілого.ц.ллвмір "$SEMIRAW_DIR"/машина/ПредметЦілого.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Притримувач.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Притримувач.ц
mv "$SEMIRAW_DIR"/машина/Притримувач.ц.ллвмір "$SEMIRAW_DIR"/машина/Притримувач.ц.ll

$TSIL "$SEMIRAW_DIR"/машина/Спроби.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити машина/Спроби.ц
mv "$SEMIRAW_DIR"/машина/Спроби.ц.ллвмір "$SEMIRAW_DIR"/машина/Спроби.ц.ll
$TSIL "$SEMIRAW_DIR"/перекладач/перекладач.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити перекладач/перекладач.ц
mv "$SEMIRAW_DIR"/перекладач/перекладач.ц.ллвмір "$SEMIRAW_DIR"/перекладач/перекладач.ц.ll

$TSIL "$SEMIRAW_DIR"/пристрій/глобальні.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити пристрій/глобальні.ц
mv "$SEMIRAW_DIR"/пристрій/глобальні.ц.ллвмір "$SEMIRAW_DIR"/пристрій/глобальні.ц.ll

$TSIL "$SEMIRAW_DIR"/пристрій/пристрій.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити пристрій/пристрій.ц
mv "$SEMIRAW_DIR"/пристрій/пристрій.ц.ллвмір "$SEMIRAW_DIR"/пристрій/пристрій.ц.ll

$TSIL "$SEMIRAW_DIR"/розбирач/розбирач.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити розбирач/розбирач.ц
mv "$SEMIRAW_DIR"/розбирач/розбирач.ц.ллвмір "$SEMIRAW_DIR"/розбирач/розбирач.ц.ll

$TSIL "$SEMIRAW_DIR"/старт.ц.ллвмір --архітектура="$TSIL_ARCH" --система="$TSIL_SYSTEM" перетворити старт.ц
mv "$SEMIRAW_DIR"/старт.ц.ллвмір "$SEMIRAW_DIR"/старт.ц.ll

$CLANG -ggdb --target="$TARGET_TRIPLE" -lm -o "$READY_DIR"/"$OUTFILENAME" \
        external/"$COMMON_SYSTEM"/main_$COMMON_SYSTEM"".c \
        external/"$COMMON_SYSTEM"/prystriy_$COMMON_SYSTEM"".c \
        "$SEMIRAW_DIR"/бібліотека/математика.ц.ll \
        "$SEMIRAW_DIR"/КД/КД.ц.ll \
        "$SEMIRAW_DIR"/машина/ВзятіЗначення.ц.ll \
        "$SEMIRAW_DIR"/машина/Дійсність.ц.ll \
        "$SEMIRAW_DIR"/машина/Допоміжне.ц.ll \
        "$SEMIRAW_DIR"/машина/Значення.ц.ll \
        "$SEMIRAW_DIR"/машина/ІменованоЗадіяні.ц.ll \
        "$SEMIRAW_DIR"/машина/ІнформаціяПадіння.ц.ll \
        "$SEMIRAW_DIR"/машина/КористувацькіДані.ц.ll \
        "$SEMIRAW_DIR"/машина/Машина.ц.ll \
        "$SEMIRAW_DIR"/машина/МісцезнаходженняВказівок.ц.ll \
        "$SEMIRAW_DIR"/машина/НакопичувачТексту.ц.ll \
        "$SEMIRAW_DIR"/машина/Очищувач.ц.ll \
        "$SEMIRAW_DIR"/машина/Послідовність.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметДаних.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметДіапазонуДробових.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметДіапазонуЦілих.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметДії.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметДробового.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметЗміннихДаних.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметКоду.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметМодуля.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметПараметра.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуДробових.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметПереборуДіапазонуЦілих.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметПереборуСписку.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметСловника.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметСписку.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметСтруктури.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметТексту.ц.ll \
        "$SEMIRAW_DIR"/машина/ПредметЦілого.ц.ll \
        "$SEMIRAW_DIR"/машина/Притримувач.ц.ll \
        "$SEMIRAW_DIR"/машина/Спроби.ц.ll \
        "$SEMIRAW_DIR"/перекладач/перекладач.ц.ll \
        "$SEMIRAW_DIR"/пристрій/глобальні.ц.ll \
        "$SEMIRAW_DIR"/пристрій/пристрій.ц.ll \
        "$SEMIRAW_DIR"/розбирач/розбирач.ц.ll \
        "$SEMIRAW_DIR"/старт.ц.ll