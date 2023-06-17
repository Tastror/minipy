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

## notes

由于 bison 的 lookahead 的限制，很多语法并不能直接交给 bison 处理。所以 parser.y 中的语法其实上是 python 的超集，需要后续符号表扫描时提供更多的检查。
