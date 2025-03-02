#!/usr/bin/env bash
set -e
set -x

mkdir -p build-l

TSIL="ціль" sh external/scripts/prepare.sh linux-x86_64
cd build/linux-x86_64
sh build.sh
cd -

cp build/linux-x86_64/out/мавка build-l