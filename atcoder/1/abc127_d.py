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
#https://atcoder.jp/contests/abc127/tasks/abc127_d
#D - Integer Cards
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
M = gi()
A = [0] * N
ops = []

for i in range(N):
    A[i] = gi()
for _ in range(M):
    b = gi()
    c = gi()
    ops.append((-c, b))

A.sort()
ops.sort()

i = 0
for op in ops:
    nv = -op[0]
    for _ in range(op[1]):
        if i >= N:
            break
        if nv < A[i]:
            break
        A[i] = nv
        i += 1

print(sum(A))
