r = 0o12 + 1.5 - 2 * 0o13 / 0b1 % 0xaf12 + 123e1

for i in range(1):
    pass; pass ; pass
    break; break; pass; continue;
    pass;

def input():
    global has_input, input_buf
    if has_input:
        has_input = False
        return input_buf
    else:
        return ""

"" + "123" + "'" + "\"" + '' + '456' + '"' + '\''
" # wrong comment 2
# test
    #testing

def get_input(input_str):   #asdf
    global has_input, input_buf
    has_input = True
    input_buf = input_str
    return