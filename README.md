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
- [джеджалик](https://diia.dev/mavka/jejalyk) - компілятор Мавки в JavaScript

## Розробка

### Вимоги

- Clang
- CMake
- Make
- Java (для ANTLR4)

### Початок

```
git clone https://github.com/mavka-ukr/mavka
cd mavka
```

### Будування

```shell
./build.sh antlr4 # antlr4 grammar
```

```shell
./build.sh bin # executable
```

```shell
./build.sh Obin # optimized executable
```
