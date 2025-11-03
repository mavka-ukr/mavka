#!/usr/bin/env sh
set -e
set -x

MavkaVersion="$(cat Версія)"
MavkaTarget="лінукс-ікс86_64"
BuildDir="будування/$MavkaVersion/$MavkaTarget"
BuildSourceDir="$BuildDir/напівготове"
BuildOutDir="$BuildDir/готове"
BuildPackageDir="$BuildDir/пакування"

mkdir -p "$BuildPackageDir/мавка-$MavkaVersion-$MavkaTarget/bin"

cp "$BuildOutDir/мавка" "$BuildPackageDir/мавка-$MavkaVersion-$MavkaTarget/bin"
cd "$BuildPackageDir"
tar -cJvf "мавка-$MavkaVersion-$MavkaTarget.tar.xz" "мавка-$MavkaVersion-$MavkaTarget"
cd -