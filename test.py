def input():
    global has_input, input_buf
    if has_input:
        has_input = False
        return input_buf
    else:
        return ""

# test
    #test ing

def get_input(input_str):   #asdf
    global has_input, input_buf
    has_input = True
    input_buf = input_str
    return
