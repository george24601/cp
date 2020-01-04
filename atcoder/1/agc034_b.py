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
#https://atcoder.jp/contests/agc034/tasks/agc034_b
#B - ABC 
"""
need to consider the case that ticket is not enough to lower everything
"""


def cost(d):
    tc = 0
    d_cnt = 0
    for c in d:
        if c == 'D':
            tc += d_cnt
        else:
            d_cnt += 1

    return tc


s = gw()
d = []
i = 0
ans = 0
while i < len(s):
    if (s[i] == 'A'):
        d.append(s[i])
        i += 1
    elif (s[i] == 'B' and (i + 1) < len(s) and s[i + 1] == 'C'):
        d.append('D')
        i += 2
    else:
        ans += cost(d)
        d = []
        i += 1

ans += cost(d)

print(ans)
