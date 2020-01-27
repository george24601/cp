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
import heapq
#https://atcoder.jp/contests/abc148/tasks/abc148_f
#F - Playing Tag on Tree
"""
"""
N = gi()
M = gi()
g = [[] for _ in range(3 * N)]
for _ in range(M):
    u = gi() - 1
    v = gi() - 1
    for r in range(3):
        nu = u * 3 + r
        nv = v * 3 + (r + 1) % 3
        g[nu].append(nv)
        g[nv].append(nu)
S = (gi() - 1) * 3
T = (gi() - 1) * 3
d = [-1] * (3 * N)

q = deque()

d[S] = 0
q.append(S)

while len(q):
    v = q.pop()
    for u in g[v]:
        if d[u] >= 0:
            continue
        d[u] = d[v] + 1
        q.append(u)

if d[T] >= 0:
    print(d[T] // 3)
else:
    print(-1)
