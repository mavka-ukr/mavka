#!/usr/bin/env sh
set -e

Mode="$1"
if [ -z "$Mode" ]
then
  Mode="release"
fi

export CC="clang"
export CXX="clang++"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
CXX_OPTIONS=""

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

if [ -f /usr/include/readline/readline.h ]
then
  appendCxxOption "-lreadline"
  appendCxxOption "-DMAVKA_READLINE"
fi

SourceFiles="$(cat SourceFiles)"
mkdir -p "out"
Command="$CXX $CXX_OPTIONS -o out/мавка $SourceFiles"
echo "$Command"
$Command