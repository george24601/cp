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
from collections import deque
from math import sqrt
from math import floor
# abc124_d handstand
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
K = gi()
S = gw()

seg_ps = []

seg_ps.append(0)

cl = 1
cur = S[0]

for i in range(1, len(S)):
    if (S[i] == S[i - 1]):
        cl += 1
    else:
        tail = seg_ps[-1]
        seg_ps.append(tail + cl)
        cur = S[i]
        cl = 1

seg_ps.append(seg_ps[-1] + cl)

ans = 0

start1 = S[0] == '1'

for i in range(1, len(seg_ps)):
    is1 = 0
    if start1:
        is1 = i % 2
    else:
        is1 = (i + 1) % 2
    if is1:
        si = max(0, i - 2 * K - 1)
    else:
        si = max(0, i - 2 * K)
    ans = max(ans, seg_ps[i] - seg_ps[si])

print(ans)
