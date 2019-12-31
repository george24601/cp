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

