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
#https://atcoder.jp/contests/arc084/tasks/arc084_a
#C - Snuke Festival
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
A = [0] * N
B = [0] * N
C = [0] * N
sB = [0] * N
sC = [0] * N

for i in range(N):
    A[i] = gi()
A.sort()

for i in range(N):
    B[i] = gi()
B.sort()

nai = 0

for i in range(N):
    while nai < N and A[nai] < B[i]:
        nai += 1
    sB[i] = nai
    if i > 0:
        sB[i] += sB[i - 1]

for i in range(N):
    C[i] = gi()
C.sort()

nbi = 0
for i in range(N):
    while nbi < N and B[nbi] < C[i]:
        nbi += 1
    if nbi:
        sC[i] = sB[nbi - 1]

    if i > 0:
        sC[i] += sC[i - 1]

print(sC[-1])
