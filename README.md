<img src="./лого.svg" width="100" height="100" />

# Мавка

Для будування треба:

- Ціль 0.36.0
- Clang
- Linux (на Windows поки нема Цілі)

Компілюємо файли Цілі:

```shell
TSIL="ціль" sh external/scripts/prepare.sh linux-x86_64
```

Переходимо в підготовлену теку:

```shell
cd build/linux-x86_64
```

Будуємо виконуваний файл:

```shell
sh build.sh
```

Пробуємо:

```shell
./out/мавка
```

За бажанням, Мавку можна встановити глобально:

```shell
sudo cp ./out/мавка /usr/local/bin
```

Зробити випуск Мавки (після `sh build.sh`):

```shell
sh package.sh
```