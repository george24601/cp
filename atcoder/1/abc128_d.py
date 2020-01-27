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
# https://atcoder.jp/contests/abc128/tasks/abc128_d
# D - equeue
"""
"""
K = gi()
V = [0] * N

for i in range(N):
    V[i] = gi()


def c(l):
    free = K - len(l)
    s = 0
    for v in l:
        if v < 0 and free:
            free -= 1
        else:
            s += v
    return s


ans = -1e9
for i in range(-1, N):
    for j in range(i + 1, N + 1):
        sub = V[0:i + 1] + V[j:N]
        if len(sub) > K:
            continue
        sub.sort()
        ans = max(ans, c(sub))

print(ans)
