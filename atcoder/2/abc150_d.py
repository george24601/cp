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
# https://atcoder.jp/contests/abc150/tasks/abc150_d
# D - Semi Common Multiple
"""

"""
def gcd(a, b):
    h = max(a, b)
    l = min(a, b)
    if h % l:
        return gcd(l, h % l)
    else:
        return l


N = gi()
M = gi()
A = [0] * N
g = 0
for i in range(N):
    A[i] = gi()
    if i:
        g = gcd(g, A[i])
    else:
        g = A[i]

lcm = g

for a in A:  #catch!!!
    lcm = (lcm * a) // gcd(lcm, a)

hl = lcm // 2
all_good = 1
for a in A:
    q = lcm // a
    if (q % 2 == 0 or lcm % a):
        all_good = 0
        break

if all_good:
    ans = M // hl - M // lcm  #cleaner!!!
else:
    ans = 0
print(ans)
