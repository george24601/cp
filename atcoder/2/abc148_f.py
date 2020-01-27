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
u = gi()
v = gi()
t = [[] for i in range(N + 1)]
d = [[0 for i in range(2)] for j in range(N + 1)]

for _ in range(1, N):
    a = gi()
    b = gi()
    t[a].append(b)
    t[b].append(a)


def dfs(i, p, di):
    for nei in t[i]:
        if nei == p:
            continue
        d[nei][di] = d[i][di] + 1
        dfs(nei, i, di)


d[u][0] = 0
dfs(u, -1, 0)
d[v][1] = 0
dfs(v, -1, 1)

ans = 0
for i in range(1, N + 1):
    du = d[i][0]
    dv = d[i][1]
    if du % 2 == dv % 2:
        if dv >= du:
            ans = max(ans, dv)
    else:
        if dv >= du - 1:
            ans = max(ans, dv)

print(ans)
