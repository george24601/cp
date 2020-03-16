from math import floor
from math import sqrt
from collections import deque
import numpy
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

# https://atcoder.jp/contests/abc145/tasks/abc145_e
# E - All-you-can-eat
"""
"""

N = gi()
T = gi()
A = [0] * (N + 5)
B = [0] * (N + 5)
for i in range(1, N + 1):
    A[i] = gi()
    B[i] = gi()

pref = [[0 for x in range(T + 5)] for i in range(N + 5)
       ]  #pop i order is inversed
suff = [[0 for x in range(T + 5)] for i in range(N + 5)]


def precalc():
    for i in range(1, N + 1):
        for t in range(T):  # max T - 1 complete minutes
            pref[i][t] = max(pref[i][t], pref[i - 1][t])
            if t >= A[i]:
                pref[i][t] = max(pref[i][t], pref[i - 1][t - A[i]] + B[i])

    for i in range(N, 0, -1):
        for t in range(T):
            suff[i][t] = max(suff[i][t], suff[i + 1][t])
            if t >= A[i]:
                suff[i][t] = max(suff[i][t], suff[i + 1][t - A[i]] + B[i])


precalc()

ans = 0

for li in range(1, N + 1):
    for pt in range(T):
        ans = max(ans, pref[li - 1][pt] + suff[li + 1][T - 1 - pt] + B[li])
print(ans)
