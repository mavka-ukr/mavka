#!/usr/bin/env bash

set -e

if [ -z "$CC" ]; then
  export CC="clang"
fi
if [ -z "$CXX" ]; then
  export CXX="clang++"
fi
if [ -z "$AR" ]; then
  export AR="llvm-ar"
fi
if [ -z "$RANLIB" ]; then
  export RANLIB="llvm-ranlib"
fi
if [ -z "$TSIL" ]; then
  export TSIL="ціль"
fi

INDIR="$1"
OUTDIR="$2"

TSIL_FILES=(
  "біб/друк/друк.ц"
  "біб/юнікод/юнікод.ц"
)
C_FILES=(
  "біб/друк/друк.c"
)
OBJECT_FILES=()

rm -rf "$OUTDIR"
mkdir -p "$OUTDIR/бібліотека/"
cp -a "$INDIR/визначення" "$OUTDIR/бібліотека/"

for file in "${TSIL_FILES[@]}"; do
  echo "> Компіляція $INDIR/втілення/$file"
  $TSIL "$OUTDIR/скомпільоване/$file.ll" скомпілювати --бібліотека="$OUTDIR/бібліотека/" "$INDIR/втілення/$file"
  echo "> Компіляція $OUTDIR/скомпільоване/$file.ll"
  $CXX -c -o "$OUTDIR/скомпільоване/$file.o" "$OUTDIR/скомпільоване/$file.ll"
  OBJECT_FILES+=("$OUTDIR/скомпільоване/$file.o")
done

for file in "${C_FILES[@]}"; do
  echo "> Компіляція $INDIR/втілення/$file"
  $CC -c -o "$OUTDIR/скомпільоване/$file.o" "$INDIR/втілення/$file"
  OBJECT_FILES+=("$OUTDIR/скомпільоване/$file.o")
done

echo "> Створення архіву $OUTDIR/бібліотека/біб.a"
$AR rcs "$OUTDIR/бібліотека/біб.a" ${OBJECT_FILES[@]}