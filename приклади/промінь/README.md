# Raylib з Мавкою

## Вимоги

- clang++ (std=c++20)
- mavka_api_v0.h

## Будуємо so бібліотеку

```shell
wget https://github.com/raysan5/raylib/releases/download/5.0/raylib-5.0_linux_amd64.tar.gz
tar -xvf raylib-5.0_linux_amd64.tar.gz
```

```bash
clang++ -std=c++20 -shared -o ext.so ext.cpp raylib-5.0_linux_amd64/lib/libraylib.a
```