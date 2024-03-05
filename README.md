<img src="./assets/logo.png" width="100" height="100" /> 

# Мавка

Сучасна українська мова програмування.

## Встановлення

~

## Використання

```shell
мавка
```

## Ресурси

- [мавка.укр](https://мавка.укр) - офіційний вебсайт
- [пак.укр](https://пак.укр) - паки Мавки
- [фрагмент.укр](https://фрагмент.укр) - фрагменти Мавки
- [конкурс.укр](https://конкурс.укр) - конкурси Мавки
- [МаМа](https://github.com/mavka-ukr/mama) - Машина Мавки
- [Джеджалик](https://github.com/mavka-ukr/jejalyk) - компілятор Мавки в JavaScript
- [Парсер](https://github.com/mavka-ukr/parser) - розбирач коду Мавки

## Розробка

### Вимоги

- Clang
- CMake
- Make

### Початок

```
git clone https://github.com/mavka-ukr/mavka
cd mavka
git submodule update --init --recursive
```

### Будування

```shell
./build.sh bin # виконуваний файл
```

```shell
./build.sh Obin # оптимізований виконуваний файл
```

```shell
./dist.sh # архів з випуском
```

### Запуск

```shell
./build-bin/мавка старт.м
# або
./build-Obin/мавка_оптимізовано старт.м
```