set -e

MAVKA_BUILD_WEBSITE_OUT=".будування/вебсайт"
MAVKA_BUILD_VERSION="а.б.в"

if [[ ! -z "$1" ]]; then
  MAVKA_BUILD_VERSION="$1"
fi

for i in "$@"
do
case $i in
    --вихід=*)
      MAVKA_BUILD_WEBSITE_OUT="${i#*=}"
      shift
    ;;
    *)
    ;;
esac
done

rm -rf "$MAVKA_BUILD_WEBSITE_OUT"

mkdir -p "$MAVKA_BUILD_WEBSITE_OUT"

cp -r external/website/* "$MAVKA_BUILD_WEBSITE_OUT"

докс перетворити --вхід=документація/мавка --вихід="$MAVKA_BUILD_WEBSITE_OUT/документація" --вигляд=external/xdocs --ґтег=G-0PFF0HTWKB
докс перетворити --вхід=документація/мама --вихід="$MAVKA_BUILD_WEBSITE_OUT/мама" --вигляд=external/xdocs --ґтег=G-0PFF0HTWKB
докс перетворити --вхід=організація --вихід="$MAVKA_BUILD_WEBSITE_OUT/організація" --вигляд=external/xdocs --ґтег=G-0PFF0HTWKB
докс перетворити --вхід=інформація --вихід="$MAVKA_BUILD_WEBSITE_OUT/інформація" --вигляд=external/xdocs --ґтег=G-0PFF0HTWKB
докс перетворити --вхід=часопис --вихід="$MAVKA_BUILD_WEBSITE_OUT/часопис" --вигляд=external/xdocs --ґтег=G-0PFF0HTWKB

докс карта --вхід="$MAVKA_BUILD_WEBSITE_OUT" --вихід="$MAVKA_BUILD_WEBSITE_OUT" --домен=мавка.укр

# relace in all html files
find "$MAVKA_BUILD_WEBSITE_OUT" -type f -name "*.html" -exec sed -i "s/{{ВЕРСІЯ_МАВКИ}}/$MAVKA_BUILD_VERSION/g" {} \;