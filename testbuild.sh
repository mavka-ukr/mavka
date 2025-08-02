#!/usr/bin/env bash
set -e
set -x

sh external/scripts/prepare.sh linux-x86_64
cd build/linux-x86_64
sh build.sh
cd -
mkdir -p out
cp build/linux-x86_64/out/мавка out/мавка