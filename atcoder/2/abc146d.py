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
#https://atcoder.jp/contests/abc146/tasks/abc146_d
#D - Coloring Edges on Tree
"""
for each edge, keep track of parent, and each edges color
while we are BFSing, we can just iterate from 1, and skip if the next one is same as parents
"""

# reads a single line
N = gi()
ecs = {}
nbls = [[] for i in range(N + 5)]  #[] * N won't work
p = [0] * (N + 5)
in_l = []

max_d = 0

for i in range(1, N):
    a = gi()
    b = gi()
    nbls[a].append(b)
    nbls[b].append(a)
    max_d = max(max_d, len(nbls[a]), len(nbls[b]))
    in_l.append((min(a, b), max(a, b)))
p[1] = 0  #sentinel node to keep code clean
ecs[(0, 1)] = -1

c_i = 0
q = deque()
q.append(1)

while len(q):
    v = q.pop()
    #by the time we reach the node, the parent edge of this node has been colored
    parent_ci = ecs[(min(v, p[v]), max(v, p[v]))]
    for u in nbls[v]:
        if u == p[v]:
            continue
        q.append(u)
        p[u] = v
        if parent_ci == c_i:
            c_i += 1
            c_i %= max_d
        ecs[(min(u, v), max(u, v))] = c_i
        c_i += 1
        c_i %= max_d

print(max_d)
for e in in_l:
    print(ecs[e] + 1)

