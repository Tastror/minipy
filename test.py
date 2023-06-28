def init(r) -> None:
    r = 4
    return r

class TypeA:
    a: int = 1
    b: str = "test"

    def __init__(self) -> None:
        self.c = 4
    
    def test(self, r):
        return r


s = TypeA
x = s.a + s.c
y = s.b
z = s.test(1)