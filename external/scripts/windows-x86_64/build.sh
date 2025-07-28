#!/usr/bin/env sh
set -e

MavkaVersion="$(cat Version)"

Mode="$1"
if [ -z "$Mode" ]
then
  Mode="release"
fi

export CC="clang -target x86_64-pc-w64-mingw"
export CXX="clang++ -target x86_64-pc-w64-mingw"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
CC_OPTIONS="-municode -DMAVKA_VERSION=\"$MavkaVersion\""

appendCcOption() {
  if [ -z "$CC_OPTIONS" ]
  then
    CC_OPTIONS="$1"
  else
    CC_OPTIONS="$CC_OPTIONS $1"
  fi
}

case "$Mode" in
  "release"*)
    appendCcOption "-O3"
    appendCcOption "-g0"
    appendCcOption "-fvisibility=hidden"
  ;;
  "debug-asan"*)
    appendCcOption "-g -fsanitize=address,undefined,leak"
  ;;
  "debug"*)
    appendCcOption "-g"
  ;;
esac

appendCcOption "-lm"

SourceFiles="$(cat SourceFiles)"
mkdir -p "out"
Command="$CC $CC_OPTIONS -o out/mavka.exe $SourceFiles"
echo "$Command"
$Command