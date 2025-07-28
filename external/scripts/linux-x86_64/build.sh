#!/usr/bin/env sh
set -e

MavkaVersion="$(cat Version)"

Mode="$1"
if [ -z "$Mode" ]
then
  Mode="release"
fi

export CC="clang -target x86_64-pc-linux-gnu"
export CXX="clang++ -target x86_64-pc-linux-gnu"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
CC_OPTIONS="-DMAVKA_VERSION=\"$MavkaVersion\""

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
    appendCcOption "-fvisibility=hidden"
  ;;
  "debug-asan"*)
    appendCcOption "-g -fsanitize=address,undefined,leak"
  ;;
  "debug"*)
    appendCcOption "-g"
  ;;
esac

if [ -f /usr/include/readline/readline.h ]
then
  if [ -f /usr/include/readline/history.h ]
  then
    appendCcOption "-lreadline"
    appendCcOption "-DMAVKA_READLINE"
  fi
fi

appendCcOption "-lm"
appendCcOption "-luring"
appendCcOption "-lidn2"
appendCcOption "-lpthread"

SourceFiles="$(cat SourceFiles)"
mkdir -p "out"
Command="$CC -rdynamic $CC_OPTIONS -o out/мавка $SourceFiles"
echo "$Command"
$Command