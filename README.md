<img src="./лого.svg" width="100" height="100" />

# Мавка

Для будування треба:

- Ціль 0.47.0
- Clang
- Linux 5.1+
- lib `m`, `readline`, `uring`, `idn2`, `pthread`

Збудувати:

```shell
sh external/scripts/build.sh
```

Скомпільований бінарник буде в директорії `будування/{версія}/{платформа}/готове`.

Випуск:

```shell
sh external/scripts/release.sh
```
