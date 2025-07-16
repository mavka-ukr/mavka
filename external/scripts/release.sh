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

cp "build/linux-x86_64/package/мавка-$Version-linux-x86_64.tar.gz" "releases/$Version"
cp "build/linux-x86_64/package/мавка-$Version-linux-x86_64-prepared.tar.gz" "releases/$Version"

mkdir -p "releases/$Version/мавка-$Version"

while IFS='' read -r ReleaseFile
do
  cp -r "$ReleaseFile" "releases/$Version/мавка-$Version"
done <<ReleaseFiles_HEREDOC_INPUT
$ReleaseFiles
ReleaseFiles_HEREDOC_INPUT

cd "releases/$Version"
tar -czvf "мавка-$Version.tar.gz" "мавка-$Version"
cd -

rm -rf "releases/$Version/мавка-$Version"

cd "releases/$Version"

PRIVATE_KEY_FILE="$RunDir/.releasegpgkey"

FINGERPRINT=$(gpg --with-colons --import-options show-only --import "$PRIVATE_KEY_FILE" 2>/dev/null \
  | awk -F: '/^fpr:/ {print $10; exit}')

if [ -z "$FINGERPRINT" ]; then
  echo "Failed to get fingerprint"
  exit 1
fi

echo "Using fingerprint: $FINGERPRINT"

for file in мавка-$Version-linux-x86_64.tar.gz мавка-$Version-linux-x86_64-prepared.tar.gz мавка-$Version.tar.gz; do
  sha256sum "$file" > "$file.sha256"

  gpg --local-user "$FINGERPRINT" --clearsign --output "$file".sha256.signed "$file".sha256
done

gpg --batch --yes --delete-secret-keys "$FINGERPRINT"
gpg --batch --yes --delete-keys "$FINGERPRINT"

cd -
