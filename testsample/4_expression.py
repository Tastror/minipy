# test normal expression (+, -, *, /, //, %, **, |, &, ^, <<, >>)
x: int = +7 - -5 // 3 ** 2 % 1 * (2 - 7) + 8 & (7 | 6) ^ 5 << 2 / 2 >> 0

# test string expression with +
y: str = "123" '456' + "789"

# test compare expression (is, not, in, <=, <, >, >=)
z: bool = 1 <= 2 < 3 + x is not y > (0 - 2)

# test and, or, not
w: bool = 1 and (2 or not 3) and 4 or not 5

# test nude expr
1
1,
12, 2
x, *y
