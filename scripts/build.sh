#!/usr/bin/env bash

set -e

TARGET=$1

if [ "$TARGET" = "" ]; then
    echo "Usage: build.sh <bin|Obin>"
    exit 1
fi

LIBS_BUNDLE_HEAD="std::unordered_map<std::string, std::string> MAVKA_LIB_MODULES = {"
LIBS_BUNDLE_TAIL="};"
LIBS=$(find "біб" | grep --color=never ".м\$")
LIBS_BUNDLE_CONTENT=""
for LIB in $LIBS; do
    LIB_CONTENT=$(xxd -i -n data "$LIB")
    LIBS_BUNDLE_CONTENT="$LIBS_BUNDLE_CONTENT{\"$LIB\", []() {
    $LIB_CONTENT
    return std::string(data, data + data_len);
}()},"
done
LIBS_BUNDLE_CONTENT="$LIBS_BUNDLE_HEAD $LIBS_BUNDLE_CONTENT $LIBS_BUNDLE_TAIL"
echo "$LIBS_BUNDLE_CONTENT" >MAVKA_LIB_MODULES.h

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