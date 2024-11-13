#!/usr/bin/env sh

set -e

NAMES=$(cat "НАЗВИ")
i=0
for NAME in $NAMES; do
  echo "синонім ${NAME} = $i;"
  i=$((i+1))
done