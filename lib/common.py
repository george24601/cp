a, b, c = 1, 2L, "john"
#casting
float(value)
bool(value) # Will only return false for an empty string or an int=0

#swap values
x, y = 1, 2
x, y = y, x

2 ** 10 = 1024

### IO

ans = [[0 for x in range(W)] for i in range(H + 5)]  #[] * N won't work
nbls = [[] for i in range(N + 5)]  #[] * N won't work
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def gw():
    global input_parser
    return next(input_parser)

def gi():
    data = get_word()
    return int(data)

# numpy and scipy are available for use
import numpy
import scipy

# reads a single line

