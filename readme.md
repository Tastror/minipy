# MiniPy Compiler

## abstract

TBD

## environment

- flex ~= 2.6.4
- bison ~= 3.8.2
- make ~= 4.4.1
- gcc ~= 13.1.0

## build

```shell
make clean
make  # or `make building`, since `build` is a dir name here
```

## run

use demo `test.py`, see res in `log.txt`

```shell
make help  # --help of this compiler
make test  # or `make show` if you want to print to terminal colorfully, :)
```

or use what you like

```shell
build/compiler.exe -h
build/compiler.exe test.py -S -o out.asm --time
...
```
