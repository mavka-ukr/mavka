#!/usr/bin/env sh
set -e
set -x

MAVKA_VERSION="$(cat Version)"

mkdir -p "package/мавка-$MAVKA_VERSION-linux-x86_64/bin"
mkdir -p "package/мавка-$MAVKA_VERSION-linux-x86_64/include"
mkdir -p "package/мавка-$MAVKA_VERSION-linux-x86_64-prepared"

cp "РМв1.в.ц" "package/мавка-$MAVKA_VERSION-linux-x86_64/include/РМв1.в.ц"
cp "out/мавка" "package/мавка-$MAVKA_VERSION-linux-x86_64/bin/мавка"
cd "package"
tar -cJvf "мавка-$MAVKA_VERSION-linux-x86_64.tar.xz" "мавка-$MAVKA_VERSION-linux-x86_64"
cd -

cp -a source build.sh package.sh SourceFiles Version "package/мавка-$MAVKA_VERSION-linux-x86_64-prepared"
cd "package"
tar -cJvf "мавка-$MAVKA_VERSION-linux-x86_64-prepared.tar.xz" "мавка-$MAVKA_VERSION-linux-x86_64-prepared"
cd -