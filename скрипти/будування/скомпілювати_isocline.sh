set -e

MAVKA_SOURCE_DIRECTORY="$1"
MAVKA_BUILD_DIRECTORY="$2"

echo "> Компіляція fmt"
mkdir -p "$MAVKA_BUILD_DIRECTORY/external/isocline/build"
cd "$MAVKA_BUILD_DIRECTORY/external/isocline/build"
cmake "$MAVKA_SOURCE_DIRECTORY/external/isocline"
make -j4
cd - >/dev/null
