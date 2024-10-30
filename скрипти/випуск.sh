set -e

MAVKA_BUILD_VERSION="$1"

echo "синонім ВЕРСІЯ_МАВКИ=ю8\"$MAVKA_BUILD_VERSION\";" >мавка/версія.в

rm -rf "випуски/$MAVKA_BUILD_VERSION"
mkdir -p "випуски/$MAVKA_BUILD_VERSION"

докс перетворити --вхід=документація/мавка --вихід=".будування/випуск/документація/мавка" --вигляд=external/xdocs
докс перетворити --вхід=документація/мама --вихід=".будування/випуск/документація/мама" --вигляд=external/xdocs
докс перетворити --вхід=інформація --вихід=".будування/випуск/інформація" --вигляд=external/xdocs

find ".будування/випуск/документація" -type f -name "*.html" -exec sed -i "s/{{ВЕРСІЯ_МАВКИ}}/$MAVKA_BUILD_VERSION/g" {} \;
find ".будування/випуск/інформація" -type f -name "*.html" -exec sed -i "s/{{ВЕРСІЯ_МАВКИ}}/$MAVKA_BUILD_VERSION/g" {} \;

bash скрипти/будування/збудувати_linux.sh --архітектура=x86_64 --режим=випуск
cp -r тексти/Ліцензія "будова/x86_64-linux-випуск-zig/Ліцензія"
rm -rf "будова/x86_64-linux-випуск-zig/документація"
rm -rf "будова/x86_64-linux-випуск-zig/інформація"
cp -r .будування/випуск/документація "будова/x86_64-linux-випуск-zig"
cp -r .будування/випуск/інформація "будова/x86_64-linux-випуск-zig"
cp -r "зміни/$MAVKA_BUILD_VERSION" "будова/x86_64-linux-випуск-zig/Зміни"
cd "будова/x86_64-linux-випуск-zig"
rm -rf "мавка-$MAVKA_BUILD_VERSION-x86_64-linux.zip"
zip -r -9 "мавка-$MAVKA_BUILD_VERSION-x86_64-linux.zip" \
  "мавка" \
  "документація" \
  "інформація" \
  "Ліцензія" \
  "Зміни"
cd -
cp -r "будова/x86_64-linux-випуск-zig/мавка-$MAVKA_BUILD_VERSION-x86_64-linux.zip" "випуски/$MAVKA_BUILD_VERSION"

bash скрипти/будування/збудувати_windows.sh --архітектура=x86_64 --режим=випуск
cp -r тексти/Ліцензія "будова/x86_64-windows-випуск-zig/Ліцензія"
rm -rf "будова/x86_64-windows-випуск-zig/документація"
rm -rf "будова/x86_64-windows-випуск-zig/інформація"
cp -r .будування/випуск/документація "будова/x86_64-windows-випуск-zig"
cp -r .будування/випуск/інформація "будова/x86_64-windows-випуск-zig"
cp -r "зміни/$MAVKA_BUILD_VERSION" "будова/x86_64-windows-випуск-zig/Зміни"
cd "будова/x86_64-windows-випуск-zig"
rm -rf "mavka-$MAVKA_BUILD_VERSION-x86_64-windows.zip"
zip -r -9 "mavka-$MAVKA_BUILD_VERSION-x86_64-windows.zip" \
  "mavka.exe" \
  "документація" \
  "інформація" \
  "Ліцензія" \
  "Зміни"
cd -
cp -r "будова/x86_64-windows-випуск-zig/mavka-$MAVKA_BUILD_VERSION-x86_64-windows.zip" "випуски/$MAVKA_BUILD_VERSION"

cp -r приклади/розширення_ехо приклад_РМв1
zip -r -9 "мавка-$MAVKA_BUILD_VERSION-приклад_РМв1.zip" приклад_РМв1
mv "мавка-$MAVKA_BUILD_VERSION-приклад_РМв1.zip" "випуски/$MAVKA_BUILD_VERSION"
rm -rf приклад_РМв1

zip -r -9 "мавка-$MAVKA_BUILD_VERSION-код.zip" \
  "external" \
  "документація" \
  "зміни" \
  "мавка" \
  "організація" \
  "приклади" \
  "ресурси" \
  "скрипти" \
  "тексти" \
  "тестування" \
  "ціль" \
  "часопис" \
  "інформація" \
  "Контрибуторам" \
  "Право" \
  "Прочитайка" \
  ".gitignore"
mv "мавка-$MAVKA_BUILD_VERSION-код.zip" "випуски/$MAVKA_BUILD_VERSION"