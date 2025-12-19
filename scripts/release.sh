#!/bin/bash
set -e

RUNDIR="$PWD"

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat машина/ВЕРСІЯ)

VERSIONDIR="випуски/$BUILD_VERSION"

if [ -d "$VERSIONDIR" ]; then
  echo "Version directory \"$VERSIONDIR\" already exists. Aborting to prevent overwriting."
  exit 1
fi

rm -rf "будування"
rm -rf "машина/будування"

bash scripts/build.sh release linux-x86_64
bash scripts/build.sh release linux-aarch64
bash scripts/build.sh release macos-x86_64
bash scripts/build.sh release macos-aarch64
bash scripts/build.sh release windows-x86_64
bash scripts/build.sh release windows-aarch64
bash scripts/build.sh release android-aarch64
bash scripts/build.sh release wasm64

bash scripts/package_source.sh
bash scripts/package_platform.sh linux-x86_64
bash scripts/package_platform.sh linux-aarch64
bash scripts/package_platform.sh macos-x86_64
bash scripts/package_platform.sh macos-aarch64
bash scripts/package_platform.sh windows-x86_64
bash scripts/package_platform.sh windows-aarch64
bash scripts/package_platform.sh android-aarch64

cp -r "будування/$BUILD_VERSION/васм64/готове/мавка.wasm" "$VERSIONDIR/мавка-$BUILD_VERSION.wasm"