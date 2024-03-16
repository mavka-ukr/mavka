# Raylib з Мавкою

## Вимоги

- clang++ (std=c++20)
- mavka_api_v0.h

## Будуємо so бібліотеку

```bash
clang++ -std=c++20 -shared -o ext.so ext.cpp raylib-5.0_linux_amd64/lib/libraylib.a
```