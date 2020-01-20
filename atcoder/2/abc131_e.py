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
# https://atcoder.jp/contests/abc131/tasks/abc131_e
# E - Friendships
"""

"""

N = gi()
K = gi()


def run():
    M = N - 1
    d = ((N - 1) * (N - 2)) // 2 - K
    M += d

    if M < (N - 1):
        print(-1)
        return

    print(M)
    for v in range(2, N + 1):
        print(1, v)

    for v in range(2, N + 1):
        for u in range(v + 1, N + 1):
            if not d:
                return
            d -= 1
            print(v, u)


run()
