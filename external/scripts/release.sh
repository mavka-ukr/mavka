#!/usr/bin/env sh
set -e
set -x

Version="$(cat Версія)"
ReleaseFiles=$(cat ФайлиВипуску)

if [ -d "releases/$Version" ]; then
  echo "Випуск $Version вже існує"
  exit 1
fi


mkdir -p "releases/$Version"

sh external/scripts/prepare.sh linux-x86_64
cd build/linux-x86_64
sh build.sh
sh package.sh
cd -

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