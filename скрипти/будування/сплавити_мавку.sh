set -e

if [ -z "$1" ]; then
  echo "Не вказано шлях для будування"
  exit 1
fi
if [ -z "$CC" ]; then
  echo "Змінна середовища CC не визначена"
  exit 1
fi
if [ -z "$CXX" ]; then
  echo "Змінна середовища CXX не визначена"
  exit 1
fi
if [ -z "$AR" ]; then
  echo "Змінна середовища AR не визначена"
  exit 1
fi
if [ -z "$RANLIB" ]; then
  echo "Змінна середовища RANLIB не визначена"
  exit 1
fi
if [ -z "$TSIL" ]; then
  echo "Змінна середовища TSIL не визначена"
  exit 1
fi

MAVKA_BUILD_DIRECTORY="$1"
MAVKA_BUILD_OUT_EXE="$2"
TSIL_LIBRARY_PATH="$MAVKA_BUILD_DIRECTORY/ціль/.плавлення-бібліотеки/бібліотека"

if [ -z "$MAVKA_BUILD_OUT_EXE" ]; then
  echo "Не вказано ім'я вихідного файлу"
  exit 1
fi

echo "CC=$CC"
echo "CXX=$CXX"
echo "AR=$AR"
echo "RANLIB=$RANLIB"
echo "TSIL=$TSIL"

#echo "Плавимо Бібліотеку Цілі"
#
#bash ціль/бібліотека/збудувати.sh ./ціль/бібліотека "$MAVKA_BUILD_DIRECTORY/ціль/.плавлення-бібліотеки"

echo "Плавимо Мавку"

MAVKA_BUILD_CPP_FILES=$(bash "./скрипти/будування/отримати_файли_для_будування_мавки.sh" "cpp")
MAVKA_BUILD_TSIL_FILES=$(bash "./скрипти/будування/отримати_файли_для_будування_мавки.sh" "ц")
MAVKA_BUILD_OBJECT_FILES=()

bash "./скрипти/будування/скомпілювати_parser.sh" "$(pwd)" "$MAVKA_BUILD_DIRECTORY"
bash "./скрипти/будування/скомпілювати_isocline.sh" "$(pwd)" "$MAVKA_BUILD_DIRECTORY"

for FILE in $MAVKA_BUILD_CPP_FILES
do
  echo "> Компіляція $FILE"
  FILE_DIRNAME=$(dirname "$FILE")
  FILE_NAME=$(basename "$FILE")
  OBJECT_FILE_NAME="$FILE_NAME.o"
  mkdir -p "$MAVKA_BUILD_DIRECTORY/$FILE_DIRNAME"
  $CXX -c -o "$MAVKA_BUILD_DIRECTORY/$FILE_DIRNAME/$OBJECT_FILE_NAME" "$FILE"
  MAVKA_BUILD_OBJECT_FILES+=("$MAVKA_BUILD_DIRECTORY/$FILE_DIRNAME/$OBJECT_FILE_NAME")
done

cd мавка
for FILE in $MAVKA_BUILD_TSIL_FILES
do
  echo "> Компіляція $FILE"
  FILE_DIRNAME=$(dirname "$FILE")
  FILE_NAME=$(basename "$FILE")
  LL_FILE_NAME="$FILE_NAME.ll"
  mkdir -p "$MAVKA_BUILD_DIRECTORY/.плавлення/скомпільоване/$FILE_DIRNAME"
  $TSIL "$MAVKA_BUILD_DIRECTORY/.плавлення/скомпільоване/$FILE_DIRNAME/$LL_FILE_NAME" скомпілювати --бібліотека="$TSIL_LIBRARY_PATH" "$FILE"
done
cd - >/dev/null

for FILE in $MAVKA_BUILD_TSIL_FILES
do
  LL_FILE_PATH="$MAVKA_BUILD_DIRECTORY/.плавлення/скомпільоване/$FILE.ll"
  OBJECT_FILE_PATH="$LL_FILE_PATH.o"
  echo "> Компіляція $LL_FILE_PATH"
  $CXX -c -o "$OBJECT_FILE_PATH" "$LL_FILE_PATH"
  MAVKA_BUILD_OBJECT_FILES+=("$OBJECT_FILE_PATH")
done

echo "> Створення виконуваного файлу $MAVKA_BUILD_DIRECTORY/$MAVKA_BUILD_OUT_EXE"
$CXX -Wl,-s -static -municode -o "$MAVKA_BUILD_DIRECTORY/$MAVKA_BUILD_OUT_EXE" \
  ${MAVKA_BUILD_OBJECT_FILES[*]} \
  "$MAVKA_BUILD_DIRECTORY/external/parser/build/libmavka_parser.a" \
  "$MAVKA_BUILD_DIRECTORY/external/parser/build/syntax/libmavka_syntax.a" \
  "$MAVKA_BUILD_DIRECTORY/external/parser/build/syntax/antlr4-cpp-runtime/libantlr4_cpp_runtime.a" \
  "$MAVKA_BUILD_DIRECTORY/external/isocline/build/libisocline.a"
echo "Готово."
