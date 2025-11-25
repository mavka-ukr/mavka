# Мавка 0.123.0

Треба:

- GNU/Linux
- Ціль _0.48.0_
- Clang
- Zig (для компіляції для AArch64/Windows/MacOS)

## Будування

Будування відбувається лише через GNU/Linux.
Мавку можна збудувати на різні платформи, але прецездатність перевіряється насамперед на `x86_64-linux`.

### Для GNU/Linux

#### x86-64

```shell
sh build.sh debug x86_64-linux

./будування/ікс86_64-лінукс/готове/мавка
```

#### AArch64

```shell
sh build.sh debug aarch64-linux

./будування/аарч64-лінукс/готове/мавка
```

### Для Windows

#### x86

```shell
sh build.sh debug x86-windows

./будування/ікс86-віндовс/готове/мавка.exe
```

#### x86-64

```shell
sh build.sh debug x86_64-windows

./будування/ікс86_64-віндовс/готове/мавка.exe
```

#### AArch64

```shell
sh build.sh debug aarch64-windows

./будування/аарч64-віндовс/готове/мавка.exe
```

### Для MacOS

#### x86-64

```shell
sh build.sh debug x86_64-macos

./будування/ікс86_64-макос/готове/мавка
```

#### AArch64

```shell
sh build.sh debug aarch64-macos

./будування/аарч64-макос/готове/мавка
```
