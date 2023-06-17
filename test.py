# test normal assign
s = 2

# test floats, hexs, decs, octs, bins
s = 0o12 + 1.5 - 2 * 0o13 / 0b1 % 0xAaf12 + 123e-1 + 01.23e12

# test type assign
a: int
x: int = 3
x: float = 2
x: int = 1.2
x: str

# test normal expression (+, -, *, /, //, %, **, |, &, ^, <<, >>)
x: int = +7 - -5 // 3 ** 2 % 1 * 2 - 7 + 8 & 7 | 6 ^ 5 << 2 / 2 >> 0

# test string expression (no """ or ''' yet)
y: str = "123" '456' + "789"

# test compare expression (is, not, in, <=, <, >, >=)
z: bool = 1 <= 2 < 3 + x is not y > 0

# test and, or, not
w: bool = 1 and 2 or not 3 and 4 or not 5

# test tuple assign and star assign
x, y = 0x456, 1.85
x, *y = 1, 2, 3
x, a, b = *y, x

# test assign expr
a = b = 1
a, b = c, d = 2, 3

# test yield
# a = yield x
# yield a

# test nude expr
1
1,
12, 2
x, *y

# test comments
    # 2q34
# asdf       #      asdf
" # not a comment "

# test semicolon
pass; pass;
pass
