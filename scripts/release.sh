set -e

VERSION=$(cat VERSION)

echo "Пакуємо Мавку $VERSION для Linux 64-біт"

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
echo -en "Вітання!\n\nВи завантажили Мавку $VERSION.\nЦя версія є експериментальною і може містити вади.\nЯкщо ви знайшли таку ваду — зробіть issue на GitHub-і: https://github.com/mavka-ukr/mavka\n\nДокументація до Мавки знаходиться тут: https://мавка.укр/документація" >мавка-"$VERSION"/Прочитайка
zip -r -9 mavka-"$VERSION"-linux_64.zip мавка-"$VERSION"
cd ..
