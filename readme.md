# MiniPy Compiler

## Abstract

A compiler compile python to LLVM-IR.

## Environment

Windows
> Should work on linux too, but a few things need to be altered.

- flex ~= 2.6.4
- bison ~= 3.8.2
- make ~= 4.4.1
- gcc ~= 13.1.0

## Build

```shell
make clean
make  # or `make all`
```

## Run

Commands below will use demo `test.py`, and output results to `log.txt` and `result_ir.ll`.

```shell
make help  # help message of this compiler
make test  # or `make show` if you want to print to terminal colorfully, :)
make sample  # compile all testsamples in testsample/
```

Referring to `--help`, you'll see the usage as below,

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

and you can do whatever you like.

```shell
build\compiler.exe --help
build\compiler.exe test.py -i -o out.ll --debug ast -e ast.txt --time --show
...
```

## Notes (Chinese)

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

另外，修改了 enum 记得重新编译所有内容，因为其他文件的 enum 仍然是按照 int 记录的，没有改变。会导致奇奇怪怪的错误。

## Todo list (Chinese)

- [x] 配置 makefile
- [x] 沿用以前写的 log，微调
- [x] 完成泛用 shell（以后可以给别的程序用）
- [ ] 添加 Graphviz 好看的显示

<placeholder>

- [x] Lexer: 完成架构
- [x] Lexer: 完成 indent dedent 相关
- [x] Lexer: 完成 indent dedent 接触 EOF 时的特殊操作

<placeholder>

- [x] AST: 完成架构
- [x] AST: 完成基础 expression
- [x] AST: 完成基础 assign, tuple-assign
- [x] AST: 完成 dot, index, function-call 的文法
- [x] AST: 完善 str, list, tuple, set 的文法
- [x] AST: 完成绝大多数 simple statements 的文法
- [x] AST: 完成绝大多数 block statements 的文法

<placeholder>

- [x] Symbol: 完成架构
- [x] Symbol: 完成表的树状扫描搜索函数
- [x] Symbol: 完成基本类型、复合类型、函数、类的不同构造
- [ ] Symbol (Search AST): 完成基本类型的解析
- [x] Symbol (Search AST): 完成函数的解析
- [ ] Symbol (Search AST): 完成函数泛型（动态类型）的实例化
- [ ] Symbol (Search AST): 完善 class 的数据类型和继承类型的的保存

<placeholder>

- [x] LLVM-IR: 完成架构
- [ ] LLVM-IR: 完成表达式和赋值等基本语句的转化
- [ ] LLVM-IR: 完成循环、跳转的转化
- [x] LLVM-IR: 完成函数的转化
- [ ] LLVM-IR: 完成类的转化
