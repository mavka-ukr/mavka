#!/usr/bin/env sh
set -e
set -x

MAVKA_VERSION="$(cat Version)"

mkdir -p "package/мавка-$MAVKA_VERSION-linux-x86_64/bin"
mkdir -p "package/мавка-$MAVKA_VERSION-linux-x86_64/include"
mkdir -p "package/мавка-$MAVKA_VERSION-linux-x86_64-prepared"

cp "РМв1.ю8.в" "package/мавка-$MAVKA_VERSION-linux-x86_64/include/РМв1.ю8.в"
cp "out/мавка" "package/мавка-$MAVKA_VERSION-linux-x86_64/bin/мавка"
cd "package"
tar -czvf "мавка-$MAVKA_VERSION-linux-x86_64.tar.gz" "мавка-$MAVKA_VERSION-linux-x86_64"
cd -

cp -a source build.sh package.sh SourceFiles Version "package/мавка-$MAVKA_VERSION-linux-x86_64-prepared"
cd "package"
tar -czvf "мавка-$MAVKA_VERSION-linux-x86_64-prepared.tar.gz" "мавка-$MAVKA_VERSION-linux-x86_64-prepared"
cd -