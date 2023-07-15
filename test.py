# test usual function define
def a():
    return

def b() -> int:
    return 1

def c(a, b):
    return a

def d(a: int, b = 0):
    a = 1
    b = 2
    return a + b

def e(a, b: int = 2) -> int:
    return b
