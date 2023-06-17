# test normal assign
s = 2

# test floats, hexs, octs, decs
s = 0o12 + 1.5 - 2 * 0o13 / 0b1 % 0xaf12 + 123e1

# test tuple assign
x, y = 0x456, 1.85

# test type assign
x: int = 3
x: float = 2
x: int = 1.2

# test normal expression (+, -, *, /, //, %, **, |, &, ^, <<, >>)
x: int = +7 - -5 // 3 ** 2 % 1 * 2 - 7 + 8 & 7 | 6 ^ 5 << 2 / 2 >> 0

# test string expression 
y: str = "123" '456' + "789"

# test compare expression (is, not, in, <=, <, >, >=)
z: bool = 1 <= 2 < 3 + x is not y > 0

# test comments
    # 2q34
# asdf       #      asdf
" # not a comment "

# test semicolon
pass; pass;
pass
