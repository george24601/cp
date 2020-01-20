from _collections import deque
from _ast import Num


def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield (number)


input_parser = parser()


def gw():
    global input_parser
    return next(input_parser)


def gi():
    data = gw()
    return int(data)


MOD = int(1e9 + 7)

import numpy
from collections import deque
from math import sqrt
from math import floor
# https://atcoder.jp/contests/abc145/tasks/abc145_e
# E - All-you-can-eat
"""
DP1[i][j] =the maximum sum of deliciousness of dishes, which are chosen from 1st- to i-th dishes,
such that he can finish them in j minutes

still WA!!!

"""
t1 = gi()
t2 = gi()
a1 = gi()
a2 = gi()
b1 = gi()
b2 = gi()

if a1 < b1:
    a1, b1 = b1, a1
    a2, b2 = b2, a2

#print(a1, a2, b1, b2)

d1 = (a1 - b1) * t1
d2 = (a2 - b2) * t2

net = d1 + d2


def run():
    if d1 == 0 or net == 0:
        print('infinity')
        return
    elif net > 0:
        print(0)
        return

    d = abs(net)

    ans = 0
    p2 = (d1 // d)
    if (d1 % d == 0):
        ans = 2 * p2
    else:
        ans = 2 * p2 + 1

    print(ans)


run()
