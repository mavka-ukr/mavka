#!/bin/bash
set -e

RUNDIR="$PWD"

MAVKA_VERSION=$(cat ВЕРСІЯ)

BUILD_PLATFORM="$1"
BUILD_ARCH=""
BUILD_SYSTEM=""
TSIL_ARCH=""
TSIL_SYSTEM=""
OUTFILENAME=""

print_usage() {
  echo "Usage: $0 <platform>"
  echo "Supported platforms: x86_64-linux, aarch64-linux, x86_64-windows, aarch64-windows, x86_64-macos, aarch64-macos"
}

if [ -z "$BUILD_PLATFORM" ]; then
  print_usage
  exit 1
fi

if [[ "$BUILD_PLATFORM" == "x86_64-linux" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="linux"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="лінукс"
  OUTFILENAME="мавка"
elif [[ "$BUILD_PLATFORM" == "aarch64-linux" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="linux"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="лінукс"
  OUTFILENAME="мавка"
elif [[ "$BUILD_PLATFORM" == "x86_64-windows" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="windows"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="віндовс"
  OUTFILENAME="мавка.exe"
elif [[ "$BUILD_PLATFORM" == "aarch64-windows" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="windows"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="віндовс"
  OUTFILENAME="мавка.exe"
elif [[ "$BUILD_PLATFORM" == "x86_64-macos" ]]; then
  BUILD_ARCH="x86_64"
  BUILD_SYSTEM="macos"
  TSIL_ARCH="ікс86_64"
  TSIL_SYSTEM="макос"
  OUTFILENAME="мавка"
elif [[ "$BUILD_PLATFORM" == "aarch64-macos" ]]; then
  BUILD_ARCH="aarch64"
  BUILD_SYSTEM="macos"
  TSIL_ARCH="аарч64"
  TSIL_SYSTEM="макос"
  OUTFILENAME="мавка"
else
  echo "Unsupported build platform: $BUILD_PLATFORM"
  exit 1
fi

VERSIONDIR="випуски/$MAVKA_VERSION"
PLATFORMDIRNAME="мавка-$MAVKA_VERSION-$TSIL_SYSTEM-$TSIL_ARCH"
PLATFORMDIR="$VERSIONDIR/$PLATFORMDIRNAME"
BINDIR="$PLATFORMDIR"

if [ -d "$VERSIONDIR" ]; then
  echo "Version directory \"$VERSIONDIR\" already exists. Aborting to prevent overwriting."
  exit 1
fi

if [[ "$BUILD_SYSTEM" == "linux" || "$BUILD_SYSTEM" == "macos" ]]; then
  BINDIR="$PLATFORMDIR/bin"
fi

mkdir -p "$VERSIONDIR"
mkdir -p "$PLATFORMDIR"
mkdir -p "$BINDIR"

tar -cf "$VERSIONDIR/мавка-$MAVKA_VERSION.tar" --exclude=.git --exclude-vcs --exclude-from=.gitignore --transform="s|^\.|мавка-$MAVKA_VERSION|" .
tar -rf "$VERSIONDIR/мавка-$MAVKA_VERSION.tar" --transform="s|^\.gitignore|мавка-$MAVKA_VERSION/.gitignore|" .gitignore
xz -z "$VERSIONDIR/мавка-$MAVKA_VERSION.tar"

cp "будування/$MAVKA_VERSION/$TSIL_SYSTEM-$TSIL_ARCH/готове/$OUTFILENAME" "$BINDIR"

cp -a "означення" "$PLATFORMDIR/означення"
cp "КД/КД.о.ц" "$PLATFORMDIR/означення"

cd "$VERSIONDIR"

tar -cJvf "мавка-$MAVKA_VERSION-$TSIL_SYSTEM-$TSIL_ARCH.tar.xz" "$PLATFORMDIRNAME"

rm -rf "$PLATFORMDIRNAME"

PRIVATE_KEY_FILE="$RUNDIR/.releasegpgkey"
PRIVATE_KEY_FILE_PASSPHRASE="$RUNDIR/.releasegpgkeypassphrase"
TMP_GPG_HOME=$(mktemp -d)

export GNUPGHOME="$TMP_GPG_HOME"

# Import the private key into temporary keyring
gpg --batch --yes --import "$PRIVATE_KEY_FILE" >/dev/null 2>&1

# Get fingerprint from this keyring
FINGERPRINT=$(gpg --with-colons --list-secret-keys --fingerprint \
  | awk -F: '/^fpr:/ {print $10; exit}')

if [ -z "$FINGERPRINT" ]; then
  echo "Failed to get fingerprint (no secret key found)"
  exit 1
fi

echo "Using fingerprint: $FINGERPRINT"

# Read passphrase from file (trim spaces/newlines)
PASSPHRASE=$(<"$PRIVATE_KEY_FILE_PASSPHRASE")

for file in мавка-"$MAVKA_VERSION"-$TSIL_SYSTEM-$TSIL_ARCH.tar.xz мавка-"$MAVKA_VERSION".tar.xz; do
  if [ ! -f "$file" ]; then
    echo "File not found: $file"
    continue
  fi

  sha256sum "$file" > "$file.sha256"

  # Sign using the imported key ONLY inside this GNUPGHOME
  gpg --batch --yes --pinentry-mode loopback --passphrase "$PASSPHRASE" \
    --local-user "$FINGERPRINT" --clearsign --output "$file.sha256.signed" "$file.sha256"
done

# Clean up the temporary keyring
rm -rf "$TMP_GPG_HOME"

cd -