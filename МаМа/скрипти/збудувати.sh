#!/usr/bin/env sh
set -e
set -x

OUT="build-l/МаМа.a"

mkdir -p build-l

export CC="clang"
export CXX="clang++"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
export TSIL="ціль"

TSIL_SOURCE_FILES=(
  "КД/КД.ц"
  "біб.ц"
  "Код.ц"
  "Машина.ц"
  "Назва.ц"
  "Обʼєкт.ц"
  "ОбʼєктБайтів.ц"
  "ОбʼєктДії.ц"
  "ОбʼєктЛогічного.ц"
  "ОбʼєктМодуля.ц"
  "ОбʼєктНативноїДії.ц"
  "ОбʼєктСловника.ц"
  "ОбʼєктСписку.ц"
  "ОбʼєктСтруктури.ц"
  "ОбʼєктТексту.ц"
  "ОбʼєктЮнікоду.ц"
  "ОбʼєктЧисла.ц"
  "Помилка.ц"
  "Середовище.ц"
  "СкладенийОбʼєкт.ц"
  "Утилізатор.ц"
)
TSIL_OBJECT_FILES=()
C_SOURCE_FILES=(
)
C_OBJECT_FILES=()

CC_OPTIONS=(
  "-O3"
)

for file in "${TSIL_SOURCE_FILES[@]}"; do
  mkdir -p $(dirname ".плавлення/"$file".ll")
  $TSIL .плавлення/"$file".ll скомпілювати "$file"
  $CC "${CC_OPTIONS[@]}" -c -o .плавлення/"$file".o .плавлення/"$file".ll
  TSIL_OBJECT_FILES+=(".плавлення/$file.o")
done

for file in "${C_SOURCE_FILES[@]}"; do
  mkdir -p $(dirname ".плавлення/"$file".o")
  $CC "${CC_OPTIONS[@]}" -c -o .плавлення/"$file".o "$file"
  C_OBJECT_FILES+=(".плавлення/$file.o")
done

$AR rcs "$OUT" "${TSIL_OBJECT_FILES[@]}" "${C_OBJECT_FILES[@]}"