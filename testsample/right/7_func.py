def a():
    return

def b() -> int:
    return 1

def c(a, b):
    return a + b

def d(a: int, b = 0):
    return a - b

def e(a, b: int = 2) -> int:
    return a * b

# test func use
a()
s = b()
c(not 3 == 1, y = 2)
y = 1, 2
d(*y)

# test yield
def y():
    a = yield 1
    yield a
    return a
    return
