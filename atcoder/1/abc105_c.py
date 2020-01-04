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
#https://atcoder.jp/contests/abc105/tasks/abc105_c
#C - Base -2 Number
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()

ans = []

while (N != 0):  #
    r = N % 4
    #print(N, r)
    if (r == 0):  #
        ans.append(0)
        ans.append(0)  #
    elif r == 1:
        ans.append(1)
        ans.append(0)
    elif r == 2:
        ans.append(0)
        ans.append(1)
        N += 4
    else:
        ans.append(1)
        ans.append(1)
        N += 4
    N //= 4  #

if len(ans):
    ans.reverse()
    si = 0
    if (ans[si] == 0):  #
        si += 1

    for i in range(si, len(ans)):
        print(ans[i], end="")
else:
    print(0)  #
