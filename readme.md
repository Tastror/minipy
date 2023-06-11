# MiniPy Compiler

## abstract

![running.png](https://s2.loli.net/2023/05/27/WwLoUuJa8qt1zQZ.png)

## environment

- flex ~= 2.6.4
- bison ~= 3.8.2
- make ~= 4.4.1
- gcc ~= 13.1.0

## build

```shell
make clean
make
```

## run

use demo `test.py`, see res in `log.txt`

```shell
make test  # or `make noshow` if you do not want to print in shell
```

or use what you like

```shell
# show help
build/compiler.exe -h

# run, with time count in log.txt
build/compiler.exe -S test.py -o out.asm --time
```
