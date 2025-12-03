#!/bin/bash
set -e

RUNDIR="$PWD"

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat ВЕРСІЯ)

VERSIONDIR="випуски/$BUILD_VERSION"

if [ -d "$VERSIONDIR" ]; then
  echo "Version directory \"$VERSIONDIR\" already exists. Aborting to prevent overwriting."
  exit 1
fi

rm -rf "будування/$BUILD_VERSION"

sh scripts/build.sh release linux-x86_64
sh scripts/build.sh release linux-aarch64
sh scripts/build.sh release macos-x86_64
sh scripts/build.sh release macos-aarch64
sh scripts/build.sh release windows-x86_64
sh scripts/build.sh release windows-aarch64
sh scripts/build.sh release android-aarch64

sh scripts/package_source.sh
sh scripts/package_platform.sh linux-x86_64
sh scripts/package_platform.sh linux-aarch64
sh scripts/package_platform.sh macos-x86_64
sh scripts/package_platform.sh macos-aarch64
sh scripts/package_platform.sh windows-x86_64
sh scripts/package_platform.sh windows-aarch64
sh scripts/package_platform.sh android-aarch64