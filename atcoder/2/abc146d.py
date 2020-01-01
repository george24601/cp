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

# numpy and scipy are available for use
import numpy
import scipy
#https://atcoder.jp/contests/abc146/tasks/abc146_d
#D - Coloring Edges on Tree
"""
this version has ac in all but 2 cases...
"""

# reads a single line
N = gi()
cs = {}
nbls = [[] for i in range(N)]  #[] * N won't work
ans = 0
il = []

for i in range(1, N):
    a = gi() - 1
    b = gi() - 1
    nbls[a].append(b)
    nbls[b].append(a)
    il.append((min(a, b), max(a, b)))


def color(v, p):
    #print(v, p)
    ecs = []
    tos = []
    for u in nbls[v]:
        e = (min(u, v), max(u, v))
        if e in cs:
            ecs.append(cs[e])
        else:
            tos.append(e)

    ecs.sort()

    can_cs = []

    prev_c = ecs[0] - 1
    while len(can_cs) < len(tos) and prev_c > 0:
        can_cs.append(prev_c)
        prev_c -= 1

    for i in range(1, len(ecs)):
        prev_c = ecs[i] - 1
        while prev_c > ecs[i - 1] and len(can_cs) < len(tos):
            can_cs.append(prev_c)
            prev_c -= 1

    next_c = ecs[-1] + 1
    while len(can_cs) < len(tos):
        global ans
        ans += 1
        can_cs.append(next_c)
        next_c += 1
    i = 0
    for to in tos:
        cs[to] = can_cs[i]
        i += 1

    for u in nbls[v]:
        if u != p:
            color(u, v)


for u in nbls[0]:
    e = (0, u)
    ans += 1
    cs[e] = ans

color(0, -1)

print(ans)
for e in il:
    print(cs[e])
