set -e

MAVKA_BUILD_ARCHITECTURE="своя"
MAVKA_BUILD_MODE="розробка"
MAVKA_BUILD_USE_ZIG=0
MAVKA_BUILD_OUT_EXE="мавка"
MAVKA_BUILD_SUPPORTED_ARCHITECTURES=("aarch64" "x86_64")
MAVKA_BUILD_INSTALL=0

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
    --зіг=1)
      MAVKA_BUILD_USE_ZIG=1
      shift
    ;;
    --зіг=0)
      MAVKA_BUILD_USE_ZIG=0
      shift
    ;;
    --встановити=1)
      MAVKA_BUILD_INSTALL=1
      shift
    ;;
    --встановити=0)
      MAVKA_BUILD_INSTALL=0
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

if [[ $MAVKA_BUILD_INSTALL == 1 ]]; then
  if [[ $MAVKA_BUILD_ARCHITECTURE != "своя" ]]; then
    echo "Встановлення можливе тільки для своєї архітектури"
    exit 1
  fi
fi

export CC="clang"
export CXX="clang++"
export AR="ar"
export RANLIB="ranlib"
export USE_JEMALLOC=no
export USE_SYSTEMD=no
export TSIL="ціль"

if [[ $MAVKA_BUILD_ARCHITECTURE == "своя" ]]; then
  if [[ $MAVKA_BUILD_USE_ZIG == 1 ]]; then
    if ! command -v zig &> /dev/null
    then
        echo "Zig не знайдено"
        exit 1
    fi
    export CC="zig cc"
    export CXX="zig c++"
    export AR="zig ar"
    export RANLIB="zig ranlib"
  fi
else
  if ! command -v zig &> /dev/null
  then
      echo "Zig не знайдено"
      exit 1
  fi
  export CC="zig cc"
  export CXX="zig c++"
  export AR="zig ar"
  export RANLIB="zig ranlib"
  if [[ ! " ${MAVKA_BUILD_SUPPORTED_ARCHITECTURES[@]} " =~ " ${MAVKA_BUILD_ARCHITECTURE} " ]]; then
    echo "Непідтримувана архітектура"
    exit 1
  fi
  export CC="$CC -target $MAVKA_BUILD_ARCHITECTURE-linux-musl"
  export CXX="$CXX -target $MAVKA_BUILD_ARCHITECTURE-linux-musl"
  MAVKA_BUILD_USE_ZIG=1
fi

if [[ $MAVKA_BUILD_MODE == "випуск" ]]; then
  export CC="$CC -O3"
  export CXX="$CXX -O3"
fi

MAVKA_BUILD_DIRECTORY="будова/$MAVKA_BUILD_ARCHITECTURE-linux-$MAVKA_BUILD_MODE"
if [[ $MAVKA_BUILD_USE_ZIG == 1 ]]; then
  MAVKA_BUILD_DIRECTORY="$MAVKA_BUILD_DIRECTORY-zig"
fi

mkdir -p "$MAVKA_BUILD_DIRECTORY"

bash "./скрипти/будування/сплавити_мавку.sh" "$(realpath "$MAVKA_BUILD_DIRECTORY")" "$MAVKA_BUILD_OUT_EXE"

if [[ $MAVKA_BUILD_INSTALL == 1 ]]; then
  echo "Встановлення /usr/local/bin/$MAVKA_BUILD_OUT_EXE"
  sudo cp -r "$MAVKA_BUILD_DIRECTORY/$MAVKA_BUILD_OUT_EXE" "/usr/local/bin/$MAVKA_BUILD_OUT_EXE"
  echo "Встановлено!"
fi