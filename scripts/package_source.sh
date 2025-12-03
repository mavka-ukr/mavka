#!/bin/bash
set -e

RUNDIR="$PWD"

PROGRAM_NAME="мавка"
BUILD_VERSION=$(cat ВЕРСІЯ)

VERSIONDIR="випуски/$BUILD_VERSION"
PLATFORMDIRNAME="$PROGRAM_NAME-$BUILD_VERSION"
PLATFORMDIR="$VERSIONDIR/$PLATFORMDIRNAME"

if [ -d "$VERSIONDIR" ]; then
  echo "Version directory \"$VERSIONDIR\" already exists. Aborting to prevent overwriting."
  exit 1
fi

mkdir -p "$PLATFORMDIR"

create_source_tarball() {
  local tarball="$VERSIONDIR/$PROGRAM_NAME-$BUILD_VERSION.tar"
  tar -cf "$tarball" --exclude=.git --exclude-vcs --exclude-from=.gitignore --transform="s|^\.|$PROGRAM_NAME-$BUILD_VERSION|" .
  tar -rf "$tarball" --transform="s|^\.gitignore|$PROGRAM_NAME-$BUILD_VERSION/.gitignore|" .gitignore
  xz -z "$tarball"
  rm -rf "$PLATFORMDIR"
}

create_source_tarball

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

  for file in $PROGRAM_NAME-"$BUILD_VERSION".tar.xz; do
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