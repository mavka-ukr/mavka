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
- [джеджалик](https://github.com/mavka-ukr/jejalyk) - компілятор Мавки в JavaScript

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
./dist.sh # архів з релізом
```

### Запуск

```shell
./build-bin/мавка тест.м
# або
./build-Obin/мавка_оптимізовано тест.м
```

### Тестування

```shell
./dist.sh
./mtests.sh
```