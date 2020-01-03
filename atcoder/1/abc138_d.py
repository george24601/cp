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
#https://atcoder.jp/contests/abc138/tasks/abc138_d
#D - Ki
"""
need to consider the case that ticket is not enough to lower everything
"""
N = gi()
Q = gi()
nbls = [[] for _ in range(N + 5)]
ps = [0] * (N + 5)
xs = [0] * (N + 5)

for _ in range(N - 1):
    a = gi()
    b = gi()
    nbls[a].append(b)
    nbls[b].append(a)

for _ in range(Q):
    p = gi()
    x = gi()
    xs[p] += x

q = deque()
q.append(1)

while len(q):
    v = q.pop()
    for u in nbls[v]:
        if (u == ps[v]):
            continue
        ps[u] = v
        xs[u] += xs[v]
        q.append(u)

for i in range(1, N + 1):
    if (i == N):
        print(xs[i])
    else:
        print("%d " % (xs[i]), end=" ")

