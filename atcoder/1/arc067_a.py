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
# https://atcoder.jp/contests/arc067/tasks/arc067_a
# C - Factors of Factorial
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
cnt = [0] * (N + 1)

cnt[1] = 1

for i in range(2, N + 1):
    t = i
    for d in range(2, int(sqrt(i)) + 1):
        while (t % d == 0):
            cnt[d] += 1
            t = t // d

    if (t > 1):
        cnt[t] += 1

ans = 1

#print(cnt)

for d in range(2, N + 1):
    if cnt[d]:
        ans *= (cnt[d] + 1)
        ans %= MOD

print(ans)
