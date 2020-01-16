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
#https://atcoder.jp/contests/arc091/tasks/arc091_b
#D - Remainder Reminder
"""

"""

N = gi()
K = gi()

ans = 0
for b in range(K + 1, N + 1):
    full = N // b
    ans += full * (b - K)
    p = N % b
    if p:
        if K:
            ans += max(0, p + 1 - K)
        else:
            ans += max(0, p - K)

print(ans)
