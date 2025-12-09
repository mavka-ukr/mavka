#!/bin/bash
set -e

RUNDIR="$PWD"

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat машина/ВЕРСІЯ)
BUILD_PLATFORM="$1"

print_usage() {
  echo "Usage: $0 <platform>"
  echo "Supported platforms: linux-x86_64, linux-aarch64, macos-x86_64, macos-aarch64, windows-x86_64, windows-aarch64, android-aarch64"
}

set_platform_vars() {
  local platform="$1"
  local system arch tsil_system tsil_arch outfile

  case "$platform" in
    linux-x86_64)
      system="linux"; arch="x86_64"; tsil_system="лінукс"; tsil_arch="ікс86_64"; outfile="$PROGRAM_NAME" ;;
    linux-aarch64)
      system="linux"; arch="aarch64"; tsil_system="лінукс"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME" ;;
    macos-x86_64)
      system="macos"; arch="x86_64"; tsil_system="макос"; tsil_arch="ікс86_64"; outfile="$PROGRAM_NAME" ;;
    macos-aarch64)
      system="macos"; arch="aarch64"; tsil_system="макос"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME" ;;
    windows-x86_64)
      system="windows"; arch="x86_64"; tsil_system="віндовс"; tsil_arch="ікс86_64"; outfile="$PROGRAM_NAME.exe" ;;
    windows-aarch64)
      system="windows"; arch="aarch64"; tsil_system="віндовс"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME.exe" ;;
    android-aarch64)
      system="android"; arch="aarch64"; tsil_system="андроїд"; tsil_arch="аарч64"; outfile="$PROGRAM_NAME" ;;
    *)
      echo "Unsupported build platform: $platform"
      exit 1 ;;
  esac

  BUILD_SYSTEM="$system"
  BUILD_ARCH="$arch"
  TSIL_SYSTEM="$tsil_system"
  TSIL_ARCH="$tsil_arch"
  OUTFILENAME="$outfile"
}

if [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

set_platform_vars "$BUILD_PLATFORM"

VERSIONDIR="випуски/$BUILD_VERSION"
PLATFORMDIRNAME="$PROGRAM_NAME-$BUILD_VERSION-$TSIL_SYSTEM-$TSIL_ARCH"
PLATFORMDIR="$VERSIONDIR/$PLATFORMDIRNAME"
BINDIR="$PLATFORMDIR"

[[ "$BUILD_SYSTEM" == "linux" || "$BUILD_SYSTEM" == "macos" || "$BUILD_SYSTEM" == "android" ]] && BINDIR="$PLATFORMDIR/bin"

mkdir -p "$BINDIR"

prepare_platform_dir() {
  echo "$PWD"
  cp "будування/$BUILD_VERSION/$TSIL_SYSTEM-$TSIL_ARCH/готове/$OUTFILENAME" "$BINDIR"
  mkdir -p "$PLATFORMDIR/означення"
  cp -a "бібліотека/означення" "$PLATFORMDIR"
  cp -a "машина/означення" "$PLATFORMDIR"
}

create_platform_tarball() {
  cd "$VERSIONDIR"
  tar -cJvf "$PROGRAM_NAME-$BUILD_VERSION-$TSIL_SYSTEM-$TSIL_ARCH.tar.xz" "$PLATFORMDIRNAME"
  rm -rf "$PLATFORMDIRNAME"
  cd - > /dev/null
}

prepare_platform_dir
create_platform_tarball

get_gpg_fingerprint() {
  gpg --with-colons --list-secret-keys --fingerprint | awk -F: '/^fpr:/ {print $10; exit}'
}

sign_release_files() {
  local private_key="$RUNDIR/.releasegpgkey"
  local passphrase_file="$RUNDIR/.releasegpgkeypassphrase"
  local tmp_gpg_home=$(mktemp -d)

  export GNUPGHOME="$tmp_gpg_home"

  gpg --batch --yes --import "$private_key" >/dev/null 2>&1

  local fingerprint=$(get_gpg_fingerprint)
  if [ -z "$fingerprint" ]; then
    echo "Failed to get fingerprint (no secret key found)"
    rm -rf "$tmp_gpg_home"
    exit 1
  fi

  echo "Using fingerprint: $fingerprint"

  local passphrase=$(<"$passphrase_file")

  cd "$VERSIONDIR"

  for file in $PROGRAM_NAME-"$BUILD_VERSION"-$TSIL_SYSTEM-$TSIL_ARCH.tar.xz; do
    [ ! -f "$file" ] && { echo "File not found: $file"; continue; }

    sha256sum "$file" > "$file.sha256"
    gpg --batch --yes --pinentry-mode loopback --passphrase "$passphrase" \
      --local-user "$fingerprint" --clearsign --output "$file.sha256.signed" "$file.sha256"
  done

  cd - > /dev/null
  rm -rf "$tmp_gpg_home"
}

if [ -f ".releasegpgkey" ] && [ -f ".releasegpgkeypassphrase" ]; then
  sign_release_files
fi