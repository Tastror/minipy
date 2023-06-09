# test usual function define
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

# test inner function
def outer():
    def inner():
        return 1
    return

# test yield
def y():
    a = yield 1
    yield a
    return a
    return

def z():
    return
    yield
    yield from y()

# test function use
a()
s = b()
c(not 3 == 1, y = 2)
y = 1, 2
d(*y)
