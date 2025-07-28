#!/usr/bin/env sh
set -e
set -x

RunDir="$PWD"

Version="$(cat Версія)"
ReleaseFiles=$(cat ФайлиВипуску)

if [ -d "releases/$Version" ]; then
  echo "Випуск $Version вже існує"
  exit 1
fi

sh external/scripts/prepare.sh linux-x86_64
cd build/linux-x86_64
sh build.sh
sh package.sh
cd -

mkdir -p "releases/$Version"

cp "build/linux-x86_64/package/мавка-$Version-linux-x86_64.tar.xz" "releases/$Version"
cp "build/linux-x86_64/package/мавка-$Version-linux-x86_64-prepared.tar.xz" "releases/$Version"

mkdir -p "releases/$Version/мавка-$Version"

while IFS='' read -r ReleaseFile
do
  cp -r "$ReleaseFile" "releases/$Version/мавка-$Version"
done <<ReleaseFiles_HEREDOC_INPUT
$ReleaseFiles
ReleaseFiles_HEREDOC_INPUT

cd "releases/$Version"
tar -cJvf "мавка-$Version.tar.xz" "мавка-$Version"
cd -

rm -rf "releases/$Version/мавка-$Version"

cd "releases/$Version"

PRIVATE_KEY_FILE="$RunDir/.releasegpgkey"
PRIVATE_KEY_FILE_PASSPHRASE="$RunDir/.releasegpgkeypassphrase"

if [[ ! -f "$PRIVATE_KEY_FILE" || ! -f "$PRIVATE_KEY_FILE_PASSPHRASE" ]]; then
    echo "Error: Required key files not found." >&2
    exit 1
fi

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

for file in мавка-$Version-linux-x86_64.tar.xz мавка-$Version-linux-x86_64-prepared.tar.xz мавка-$Version.tar.xz; do
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