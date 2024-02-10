set -e

VERSION=$1

if [ "$VERSION" = "" ]; then
    echo "Usage: dist.sh <version>"
    exit 1
fi

mkdir -p build-Obin
cd build-Obin
cmake ..
make -j8 mavka_optimized

cd ..
rm -rf dist
mkdir -p dist
cd dist
mkdir -p мавка-"$VERSION"
cp ../build-Obin/мавка_оптимізовано мавка-"$VERSION"/мавка
cp ../LICENSE мавка-"$VERSION"/Ліцензія
zip -r -9 мавка-"$VERSION"-linux_x64.zip мавка-"$VERSION"
cd ..
