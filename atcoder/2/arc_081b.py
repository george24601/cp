from _collections import deque


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
import scipy
from collections import deque
from math import sqrt
from math import floor
#https://atcoder.jp/contests/arc081/tasks/arc081_b
#D - Coloring Dominoes
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
S1 = gw()
S2 = gw()

i = 1
ans = 3

if (N > 1 and S1[0] == S1[1]):
    i = 2
    ans = 6

while i < N:
    isV = S1[i - 1] == S2[i - 1]
    if S1[i] == S2[i]:
        if isV:
            ans *= 3
            ans %= MOD
        i += 1
    else:
        ans *= 2
        ans %= MOD
        i += 2

print(ans)
