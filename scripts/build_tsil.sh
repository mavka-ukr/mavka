#!/bin/bash
set -e

BUILD_MODE="$1"
BUILD_PLATFORM="$2"
OUTPUT_FORMAT="${3:-ll}"
TSIL_CMD="${4:-ціль}"
CLANG="$5"

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
LIST_FILE="$ROOT_DIR/БУДЦ"

BUILD_VERSION=$(cat "$ROOT_DIR/ВЕРСІЯ" | xargs)

case "$BUILD_MODE" in
  debug)
    TSIL_MODE="відлагодження"
    ;;
  release)
    TSIL_MODE="випуск"
    ;;
  *)
    echo "Unsupported build mode: $BUILD_MODE" >&2
    exit 1 ;;
esac

case "$BUILD_PLATFORM" in
  linux-x86_64)
    TSIL_PLATFORM="ікс86_64-пк-лінукс-гну"; TSIL_PLATFORM_FOLDER="лінукс-ікс86_64"
    TARGET_TRIPLE="x86_64-linux-gnu"
    ;;
  linux-aarch64)
    TSIL_PLATFORM="аарч64-пк-лінукс-гну";  TSIL_PLATFORM_FOLDER="лінукс-аарч64"
    TARGET_TRIPLE="aarch64-linux-gnu"
    ;;
  macos-x86_64)
    TSIL_PLATFORM="ікс86_64-епл-дарвін";  TSIL_PLATFORM_FOLDER="макос-ікс86_64"
    TARGET_TRIPLE="x86_64-macos"
    ;;
  macos-aarch64)
    TSIL_PLATFORM="аарч64-епл-дарвін";   TSIL_PLATFORM_FOLDER="макос-аарч64"
    TARGET_TRIPLE="aarch64-macos"
    ;;
  windows-x86_64)
    TSIL_PLATFORM="ікс86_64-пк-віндовс-гну"; TSIL_PLATFORM_FOLDER="віндовс-ікс86_64"
    TARGET_TRIPLE="x86_64-windows-gnu"
    ;;
  windows-aarch64)
    TSIL_PLATFORM="аарч64-пк-віндовс-гну"; TSIL_PLATFORM_FOLDER="віндовс-аарч64"
    TARGET_TRIPLE="aarch64-windows-gnu"
    ;;
  msvc-x86_64)
    TSIL_PLATFORM="ікс86_64-пк-віндовс-мсвс"; TSIL_PLATFORM_FOLDER="мсвс-ікс86_64"
    TARGET_TRIPLE="x86_64-windows-msvc"
    ;;
  msvc-aarch64)
    TSIL_PLATFORM="аарч64-пк-віндовс-мсвс"; TSIL_PLATFORM_FOLDER="мсвс-аарч64"
    TARGET_TRIPLE="aarch64-windows-msvc"
    ;;
  android-aarch64)
    TSIL_PLATFORM="аарч64-пк-лінукс-гну";  TSIL_PLATFORM_FOLDER="андроїд-аарч64"
    TARGET_TRIPLE="aarch64-linux-android24"
    ;;
  wasm64)
    TSIL_PLATFORM="васм64";         TSIL_PLATFORM_FOLDER="васм64"
    TARGET_TRIPLE="wasm64-unknown-unknown"
    ;;
  *)
    echo "Unsupported platform: $BUILD_PLATFORM" >&2
    exit 1 ;;
esac

if [ "$OUTPUT_FORMAT" = "o" ]; then
  SEMIREADY_DIR="$ROOT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/$TSIL_MODE/напівготове/ллвмо"
else
  SEMIREADY_DIR="$ROOT_DIR/будування/$BUILD_VERSION/$TSIL_PLATFORM_FOLDER/$TSIL_MODE/напівготове/ллвмір"
fi

if [ ! -f "$LIST_FILE" ]; then
  echo "Помилка: Файл конфігурації '$LIST_FILE' не знайдено." >&2
  exit 1
fi

while IFS= read -r line || [ -n "$line" ]; do
  line=$(echo "$line" | xargs)
  [[ -z "$line" || "$line" =~ ^# ]] && continue
  mkdir -p "$SEMIREADY_DIR/$(dirname "$line")"
done < "$LIST_FILE"

LLIRFILES=""
while IFS= read -r line || [ -n "$line" ]; do
  line=$(echo "$line" | xargs)
  [[ -z "$line" || "$line" =~ ^# ]] && continue

  echo "компілювання $line" >&2
  $TSIL_CMD \
    "$(realpath --relative-to="$(pwd)" "$SEMIREADY_DIR/$line.ллвмір")" -П="$TSIL_PLATFORM" \
    скомпілювати \
    "$(realpath --relative-to="$(pwd)" "$line")" -В=./КД/визначення -В=./визначення >&2

  if [ "$OUTPUT_FORMAT" = "o" ]; then
    $CLANG -c -o "$SEMIREADY_DIR/$line.ллвмо" -x ir "$SEMIREADY_DIR/$line.ллвмір"
    LLIRFILES+=" $SEMIREADY_DIR/$line.ллвмо"
    rm -f "$SEMIREADY_DIR/$line.ллвмір"
  else
    mv "$SEMIREADY_DIR/$line.ллвмір" "$SEMIREADY_DIR/$line.ллвмір.ll"
    LLIRFILES+=" $SEMIREADY_DIR/$line.ллвмір.ll"
  fi
done < "$LIST_FILE"

echo "$LLIRFILES"