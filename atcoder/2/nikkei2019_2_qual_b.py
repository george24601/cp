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
#https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b?lang=en
#B - Counting of Trees
"""
sort, and then check how many next levels we have against the previes level
keep a prevcount, and each level is prev level ** cur elvel
"""
N = gi()
cnt = [0] * N
dist = [0] * N

MOD = 998244353

max_d = 0

for i in range(N):
    dist[i] = gi()
    cnt[dist[i]] += 1
    max_d = max(max_d, dist[i])


def run():
    if cnt[0] != 1 or dist[0] > 0:
        print(0)
        return

    ans = 1
    for i in range(1, max_d + 1):
        if cnt[i] == 0:
            print(0)
            return
        for _ in range(cnt[i]):
            ans *= cnt[i - 1]
            ans %= MOD

    print(ans)


run()
