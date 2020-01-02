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
#https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
#C - Strawberry Cakes
"""
harder to do line by line input reading in python with exisiting lib
iterate on each row
if no found, inherit from the above and below
1. find the first sb
2. start the process
3. upon seeing a new one, add one and continue
"""


def cp_ans(r, delta):
    for i in range(W):
        global ans
        ans[r][i] = ans[r + delta][i]


# reads a single line
H = gi()
W = gi()
K = gi()
ecs = {}
ans = [[[0 for x in range(W)]] for i in range(H + 5)]  #[] * N won't work
rows = []

for i in range(K):
    w = gw()
    print(w)
    rows.append(w)

sr = 0
cnt = 0
for i in range(H):
    if rows[i].find("#") == -1:
        sr += 1
for r in range(sr, H):
    fi = rows[r].find("#")
    if fi == -1:
        cp_ans(-1)
        continue
    #solve for a row here
    for i in range(fi, W):
        if (rows[r][i] == '#'):
            cnt += 1
            ans[r][i] = cnt
            for pi in range(i - 1, -1, -1):
                if (ans[r][pi]):
                    break
                else:
                    ans[r][pi] = ans[r][pi + 1]
        else:
            ans[r][i] = ans[r][i - 1]

for i in range(sr - 1, -1, -1):
    cp_ans(1)

for r in range(H):
    for c in range(W):
        if c == W - 1:
            print(ans[r][c])
        else:
            print("%d " % (ans[r][c]), end="")
