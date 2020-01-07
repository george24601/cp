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
base = 0
half_i = N // 2

for i in range(half_i):
    base -= 2 * A[i]

for i in range(half_i, N):
    base += 2 * A[i]

el = 0
ol_l = 0
ol_h = 0

if N % 2 == 0:
    el = base - A[half_i] + A[half_i - 1]

if (N >= 3 and N % 2):
    ol_l = base - 3 * A[half_i] + A[half_i - 1]
    ol_h = base - A[half_i] - A[half_i + 1]

print(max(el, ol_l, ol_h))
