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
# https://atcoder.jp/contests/abc107/tasks/arc101_a
# C - Candles
"""
need to consider the case that ticket is not enough to lower everything
"""


def run():
    for i in range(1, len(S)):
        ss = S[i] == S[i - 1]
        ts = T[i] == T[i - 1]
        if ss != ts:
            print("No - 1")
            return

    ss = {}
    ts = {}
    for i in range(len(S)):
        if S[i] in ss:
            ss[S[i]] += 1
        else:
            ss[S[i]] = 1

        if T[i] in ts:
            ts[T[i]] += 1
        else:
            ts[T[i]] = 1
    print(ss, ts)
    for k in ss:
        if not k in ts:
            print("No - 2")
            return

    sc = {}
    for _, v in ss.items():
        if v in sc:
            sc[v] += 1
        else:
            sc[v] = 1

    tc = {}
    for _, v in ts.items():
        if v in tc:
            tc[v] += 1
        else:
            tc[v] = 1

    for k, v in sc.items():
        if not k in tc or tc[k] != v:
            print("No - 3")
            return
    print("Yes")


S = gw()
T = gw()

run()
