#!/usr/bin/env bash
set -e
set -x

VERSION="$(cat ВЕРСІЯ)"

if [ -d випуски/"$VERSION" ]; then
  echo "Випуск $VERSION вже існує"
  exit 1
fi
mkdir -p випуски/"$VERSION"/мавка-"$VERSION"-x86_64-linux-gnu

bash скрипти/збудувати.sh
cp build-l/мавка випуски/"$VERSION"/мавка-"$VERSION"-x86_64-linux-gnu

cd випуски/"$VERSION"
zip -r -9 мавка-"$VERSION"-x86_64-linux-gnu.zip мавка-"$VERSION"-x86_64-linux-gnu