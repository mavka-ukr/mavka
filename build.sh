#!/usr/bin/env sh
set -e
set -x

sh external/scripts/prepare.sh linux-x86_64
cd build/linux-x86_64
sh build.sh debug
cd ../../
mkdir -p out
cp build/linux-x86_64/out/мавка out/мавка