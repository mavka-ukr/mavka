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
CXX_OPTIONS="-municode"

appendCxxOption() {
  if [ -z "$CXX_OPTIONS" ]
  then
    CXX_OPTIONS="$1"
  else
    CXX_OPTIONS="$CXX_OPTIONS $1"
  fi
}

case "$Mode" in
  "release"*)
    appendCxxOption "-O3"
    appendCxxOption "-g0"
    appendCxxOption "-flto"
    appendCxxOption "-ffast-math"
    appendCxxOption "-fvisibility=hidden"
  ;;
  "debug"*)
    appendCxxOption "-g"
  ;;
esac

SourceFiles="$(cat SourceFiles)"
mkdir -p "out"
Command="$CXX $CXX_OPTIONS -o out/mavka.exe $SourceFiles"
echo "$Command"
$Command