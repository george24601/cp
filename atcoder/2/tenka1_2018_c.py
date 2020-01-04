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
#https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
#C - Align
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
A = [0] * N
ais = [0] * N

for i in range(N):
    A[i] = gi()

A.sort()
nl = -1
nr = 1
hi = N - 2
li = 0
big = 0

curL = A[N - 1]
curR = A[N - 1]

while (hi >= li):
    can = A[hi]
    actual = hi
    if big:
        hi -= 1
    else:
        can = A[li]
        actual = li
        li += 1

    big = 1 - big

    if (abs(curL - can) > abs(curR - can)):
        ais[actual] = nl
        nl -= 1
        curL = can
    else:
        ais[actual] = nr
        nr += 1
        curR = can

for i in range(N):
    ais[i] -= (nl + 1)

ans = [0] * N

for i in range(N):
    ans[ais[i]] = A[i]

s = 0
for i in range(N - 1):
    s += abs(ans[i] - ans[i + 1])

print(s)
