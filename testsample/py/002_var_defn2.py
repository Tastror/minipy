# test domain of global var define and local define
a = 3
b = 5

def main():
    c = 2
    if True:
        a = 5
        c = a + b
    return c
