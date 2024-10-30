set -e

MAVKA_BUILD_ARCHITECTURE=""
MAVKA_BUILD_MODE="розробка"
MAVKA_BUILD_OUT_EXE="mavka.exe"
MAVKA_BUILD_SUPPORTED_ARCHITECTURES=("aarch64" "x86_64")

if ! command -v zig &> /dev/null
then
    echo "Zig не знайдено"
    exit 1
fi

for i in "$@"
do
case $i in
    --архітектура=*)
      MAVKA_BUILD_ARCHITECTURE="${i#*=}"
      shift
    ;;
    --режим=*)
      MAVKA_BUILD_MODE="${i#*=}"
      shift
    ;;
    *)
    ;;
esac
done

if [[ $MAVKA_BUILD_ARCHITECTURE == "" ]]; then
  echo "Не вказано архітектуру"
  exit 1
fi

if [[ $MAVKA_BUILD_MODE == "" ]]; then
  echo "Не вказано режим"
  exit 1
fi

if [[ ! " ${MAVKA_BUILD_SUPPORTED_ARCHITECTURES[@]} " =~ " ${MAVKA_BUILD_ARCHITECTURE} " ]]; then
  echo "Непідтримувана архітектура"
  exit 1
fi

export CC="zig cc"
export CXX="zig c++"
export AR="zig ar"
export RANLIB="zig ranlib"
export USE_JEMALLOC=no
export USE_SYSTEMD=no
export TSIL="ціль"

MAVKA_BUILD_TARGET="$MAVKA_BUILD_ARCHITECTURE-windows"

export CC="$CC -target $MAVKA_BUILD_TARGET"
export CXX="$CXX -target $MAVKA_BUILD_TARGET"

if [[ $MAVKA_BUILD_MODE == "випуск" ]]; then
  export CC="$CC -O3"
  export CXX="$CXX -O3"
fi

MAVKA_BUILD_DIRECTORY="будова/$MAVKA_BUILD_ARCHITECTURE-windows-$MAVKA_BUILD_MODE"
MAVKA_BUILD_DIRECTORY="$MAVKA_BUILD_DIRECTORY-zig"

mkdir -p "$MAVKA_BUILD_DIRECTORY"

bash "./скрипти/будування/сплавити_мавку.sh" "$(realpath "$MAVKA_BUILD_DIRECTORY")" "$MAVKA_BUILD_OUT_EXE"
