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
#https://atcoder.jp/contests/abc114/tasks/abc114_c
#C - 755
"""
need to consider the case that ticket is not enough to lower everything
"""


def bt():
    global prefix, ans
    prefix *= 10

    for i in range(3):
        prefix += ds[i]
        cnt[i] += 1

        if prefix <= N:
            if all(cnt):
                ans += 1
            bt()
        cnt[i] -= 1
        prefix -= ds[i]
    prefix /= 10


N = gi()
prefix = 0
ds = [3, 5, 7]
cnt = [0] * 3
ans = 0

bt()
print(ans)
