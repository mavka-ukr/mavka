#!/bin/bash
set -e
set -x

MAVKA_VERSION="$1"

if [ -z "$MAVKA_VERSION" ]; then
  echo "Usage: $0 <mavka_version>"
  exit 1
fi

bash scripts/test.sh "./будування/$MAVKA_VERSION/лінукс-ікс86_64/готове/мавка"
bash scripts/test.sh "./будування/$MAVKA_VERSION/віндовс-ікс86_64/готове/мавка.exe"
bash scripts/test.sh ./scripts/test.ts
