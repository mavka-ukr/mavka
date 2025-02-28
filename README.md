<img src="./лого.svg" width="100" height="100" />

# Мавка

Для будування треба:

- Ціль 0.35.0
- Clang++
- Linux (на Windows поки нема Цілі)

Будуємо:

```shell
TSIL="ціль" sh external/scripts/prepare.sh linux-x86_64
cd build/linux-x86_64
sh build.sh
./out/мавка
```