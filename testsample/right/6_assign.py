# test normal assign
s = 2

# test floats, hexs, decs, octs, bins
s = 0o12 + 1.5 - 2 * 0o13 / 0b1 % 0xAaf12 + 123e-1 + 01.23e12

# test tuple assign
x, y = 0x456, 1.85

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
