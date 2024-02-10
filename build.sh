set -e

TARGET=$1

if [ "$TARGET" = "" ]; then
    echo "Usage: build.sh <bin|Obin>"
    exit 1
fi

if [ "$TARGET" = "bin" ] || [ "$TARGET" = "all" ]; then
    mkdir -p build-bin
    cd build-bin
    cmake ..
    make -j8 mavka
    cd ..
fi

if [ "$TARGET" = "Obin" ] || [ "$TARGET" = "Oall" ]; then
    mkdir -p build-Obin
    cd build-Obin
    cmake ..
    make -j8 mavka_optimized
    cd ..
fi