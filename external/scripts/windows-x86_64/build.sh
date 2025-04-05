#!/usr/bin/env sh
set -e

Mode="$1"
if [ -z "$Mode" ]
then
  Mode="release"
fi

export CC="zig cc -target x86_64-windows-gnu"
export CXX="zig c++ -target x86_64-windows-gnu"
export AR="zig ar"
export RANLIB="zig ranlib"
CC_OPTIONS="-municode"

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
    appendCcOption "-flto"
    appendCcOption "-ffast-math"
    appendCcOption "-fvisibility=hidden"
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