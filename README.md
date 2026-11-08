# Мавка

Сучасна українська мова програмування.

## Будування

Треба:

- GNU/Linux
- [Ціль](https://ціль.мавка.укр) _0.85.0_
- Clang, LLVM, LLD, Make, CMake, etc
- [llvm-mingw](https://github.com/mstorsjo/llvm-mingw) (для компіляції для Windows)
- [osxcross](https://github.com/tpoechtrager/osxcross) (для компіляції для MacOS, треба [MacOSX 14.0 SDK](https://github.com/roblabla/MacOSX-SDKs/releases/tag/macosx14.0))

```shell
bash scripts/build.sh debug linux-x86_64
```

```shell
./будування/{ВЕРСІЯ}/лінукс-ікс86_64/відлагодження/готове/мавка
```

Будування відбувається лише через GNU/Linux, так як Ціль наразі доступна лише там.
Мавку можна збудувати на різні платформи, але працездатність перевіряється насамперед на `linux-x86_64`.
Можливості на платформах відмінних від `linux-x86_64` можуть бути обмеженими.

Доступні режими будування:

- `debug`
- `release`

Доступні платформи будування:

- `linux-i686`
- `linux-x86_64`
- `linux-aarch64`
- `macos-x86_64`
- `macos-aarch64`
- `windows-x86_64`
- `windows-aarch64`
- `android-aarch64`
- `wasm64`

Для будування для Windows треба вказати **абсолютний** шлях до [llvm-mingw](https://github.com/mstorsjo/llvm-mingw/releases/tag/20260616):

```shell
LLVM_MINGW_PATH="$HOME/Compilers/llvm-mingw-20260616-ucrt-ubuntu-22.04-x86_64" bash scripts/build.sh debug windows-x86_64
```

Для будування для MacOS треба вказати **абсолютний** шлях до збудованого [osxcross](https://github.com/tpoechtrager/osxcross) ([MacOSX 14.0 SDK](https://github.com/roblabla/MacOSX-SDKs/releases/tag/macosx14.0)):

```shell
OSXCROSS_PATH="$HOME/Compilers/osxcross/target" bash scripts/build.sh debug macos-x86_64
```

Для будування для Android треба вказати **абсолютний** шлях до [NDK](https://developer.android.com/ndk/downloads):

```shell
ANDROID_NDK_HOME="$HOME/Compilers/android-ndk-r27d" bash scripts/build.sh debug android-aarch64
```

### Як збудувати osxcross

```shell
mkdir -p $HOME/Compilers
cd $HOME/Compilers

git clone https://github.com/tpoechtrager/osxcross.git --depth=1

cd osxcross

wget -P tarballs https://github.com/roblabla/MacOSX-SDKs/releases/download/macosx14.0/MacOSX14.0.sdk.tar.xz

UNATTENDED=1 ./build.sh
```

## Розробка

Мавку написано мовою Ціль. Але.
Деякі частини, такі як взаємодія з операційною системою (Unix/Windows), написані мовою _C (eng)_ (зараз зробити інакше не вийде).
Тому під час розробки це треба мати наувазі - використання _C (eng)_ лише для крайньої необхідності.

Усі файли, що написані мовою _C (eng)_, розташовуються в папці `пристрій_мавки/external`.

В папці `пристрій_мавки` знаходяться файли які втілюють запуск Машини Мавки для конкретної платформи (тобто самої Мавки).

В папці `пристрій_мавки/external/unix` знаходяться необхідні файли для компілювання для Linux/MacOS/Android.

В папці `пристрій_мавки/external/windows` знаходяться необхідні файли для компілювання для Windows.

В папці `пристрій_мавки/external/wasm64` знаходяться необхідні файли для компілювання для Wasm64.

Мавка, як і Ціль, майже не використовує Unicode - лише у випадках, де без нього не обійтись.
Натомість використовується [Дієкод](https://xn--80aaf6ah.xn--j1amh/%D0%B4%D0%BE%D0%BA%D1%83%D0%BC%D0%B5%D0%BD%D1%82%D0%B0%D1%86%D1%96%D1%8F/%D0%B4%D1%96%D1%94%D0%BA%D0%BE%D0%B4.html).

По причині того, що всі сучасні редактори і ОС за замовчуванням зберігають текстові файли використовуючи Unicode,
у Мавці на вхід передаються саме Unicode-файли (UTF-8),
але вони надалі перекодовуються в Дієкод. І вже під час розбору (і далі) Unicode не використовується.
По-суті, Unicode використовується лише для взаємодії з ОС. Цього позбутись, щонайменше на Unix/Windows, не вийде.

## Тестування

Запустити тести:

```shell
bash scripts/test.sh <шлях_до_мавки>
```
