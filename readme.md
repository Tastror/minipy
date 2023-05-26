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
make
```

## run

```shell
# show help
build/compiler.exe -h

# run, with time count in log.txt
build/compiler.exe -S test.py -o out.asm --time
```
