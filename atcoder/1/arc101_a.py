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
# https://atcoder.jp/contests/abc107/tasks/arc101_a
# C - Candles
"""
need to consider the case that ticket is not enough to lower everything
"""
N = gi()
K = gi()
xs = [0] * N
for i in range(N):
    xs[i] = gi()

ans = abs(2 * xs[0]) + xs[-1]
if xs[0] >= 0:
    ans = min(ans, xs[K - 1])
elif xs[-1] <= 0:
    ans = min(ans, xs[-K + 1])

for i in range(N):
    if (i + K - 1 >= N):
        break
    r = xs[i + K - 1]
    l = xs[i]

    if (l <= 0 and r >= 0):
        ans = min(ans, -l + r + min(-l, r))

print(ans)
