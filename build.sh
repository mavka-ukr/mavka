set -e

TARGET=$1

if [ "$TARGET" = "" ]; then
    echo "Usage: build.sh <antlr4|bin|Obin>"
    exit 1
fi

if [ "$TARGET" = "antlr4" ]; then
    cd mama/parser/syntax
    java -jar antlr-4.13.0-complete.jar -Dlanguage=Cpp *.g4 -visitor
    cd ..
    exit 0
fi

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