# test normal assign
s = 2

# test type assign
a: int
x: int = 3
x: float = 2
x: int = 1.2
x: str

# test tuple assign and star assign
x, y = 1, 2
x, *y = 1, 2, 3
x, a, b = *y, x

# test assign expr
a = b = 1
a, b = c, d = 2, 3
