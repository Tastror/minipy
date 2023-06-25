# MiniPy Compiler

## abstract

TBD

## environment

Windows
> Should work on linux too, but few things need to be altered

- flex ~= 2.6.4
- bison ~= 3.8.2
- make ~= 4.4.1
- gcc ~= 13.1.0

## build

```shell
make clean
make  # or `make building`
```

## run

use demo `test.py`, see res in `log.txt`

```shell
make help  # --help of this compiler
make test  # or `make show` if you want to print to terminal colorfully, :)
make sample  # compile all testsamples in testsample/right to sample-output/
```

refer to help, you'll see

```shell
# help
compiler -h

# run
compiler \
    <input_file> \
    [-i [-o <output_file>]] \
    [-d <debug_mode> [-e <debug_output_file>]] \
    [-O <num>] [-t] [-s]
```

```plaintext
-h == --help
-i == --ir:
-o == --out:
-d == --debug:
<debug_mode> can be shell, lex, parse, ast, sym
-e == --debug_out:
-O == --optimize:
-t == --time:
-s == --show 
```

do what you like

```shell
build\compiler.exe --help
build\compiler.exe test.py -i -o out.ll --debug ast -e ast.txt --time --show
...
```

## notes

由于 bison 的 lookahead 的限制，很多语法并不能直接交给 bison 处理。所以 parser.y 中的语法其实上是 python 的超集，需要后续符号表扫描时提供更多的检查。

文件的依赖关系是严格的：

```plaintext
color   timing
 │       ╽
 ╰────━ log ─────╮
         ╽       ╽
        lexer   shell
         ╽
        parser
         ╽
        symbol
         ╽
        ir
         ╽
        compiler
```

## Todo list

- [x] 配置 makefile
- [x] 沿用以前写的 log, shell，微调
- [x] 完成 lex 架构
- [x] 完成 lex indent dedent 相关
- [x] 完成 lex indent dedent 接触 EOF 时的特殊操作
- [x] 完成 ast 架构
- [x] 完成 ast 架构
- [x] 完成 ast 基础 expresstion
- [x] 完成 ast simple statements
- [x] 完成 ast block statements
- [x] 完善 tuple, str
- [ ] 完善 list, dict
- [x] 完成 symbol 架构
- [ ] 完善 symbol 中 class 的继承内容
- [x] 完成 ir 架构
- [ ] 完善 ir
- [ ] 添加 Graphviz 好看的显示
