#!/usr/bin/env bash

set -e

TARGET=$1

if [ "$TARGET" = "" ]; then
    echo "Usage: build.sh <bin|Obin>"
    exit 1
fi

LIBS_BUNDLE_HEAD="std::unordered_map<std::string, std::string> lib_modules = {"
LIBS_BUNDLE_TAIL="};"
LIBS=$(find біб | grep --color=never ".м\$")
LIBS_BUNDLE_CONTENT=""
IFSOLD=$IFS
for LIB in $LIBS; do
    IFS=
    LIB_CONTENT="$(cat "$LIB")"
    LIBS_BUNDLE_CONTENT="$LIBS_BUNDLE_CONTENT{\"$LIB\", R\"($LIB_CONTENT)\"},"
done
LIBS_BUNDLE_CONTENT="$LIBS_BUNDLE_HEAD $LIBS_BUNDLE_CONTENT $LIBS_BUNDLE_TAIL"
echo $LIBS_BUNDLE_CONTENT >lib_bundle.h
IFS=$IFSOLD

if [ "$TARGET" = "bin" ] || [ "$TARGET" = "all" ]; then
    mkdir -p build-bin
    cd build-bin
    cmake ..
    make -j4 mavka
    cd ..
fi

if [ "$TARGET" = "Obin" ] || [ "$TARGET" = "Oall" ]; then
    mkdir -p build-Obin
    cd build-Obin
    cmake ..
    make -j4 mavka_optimized
    cd ..
fi