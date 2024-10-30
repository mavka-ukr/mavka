set -e

MAVKA_SOURCE_DIRECTORY="$1"
MAVKA_BUILD_DIRECTORY="$2"

echo "> Компіляція parser"
mkdir -p "$MAVKA_BUILD_DIRECTORY/external/parser/build"
cd "$MAVKA_BUILD_DIRECTORY/external/parser/build"
cmake "$MAVKA_SOURCE_DIRECTORY/external/parser"
make -j4
cd - >/dev/null
