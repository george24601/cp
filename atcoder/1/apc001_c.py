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
#https://atcoder.jp/contests/apc001/tasks/apc001_c
#C - Vacant Seat
"""
m > n impossible
m = n, possible only when n = 1


"""

def find(si, ei):
    if si > ei:
        return
    
    mid = (si + ei)//2
    
    pg(mid)
    if found >= 0:
        print(found)
        return
    
    if mid == si:
        
    
    d = mid - si
    
    if d % 2:
        if ss[mid] ^ ss[si]:
            find(mid + 1, ei)
        else:
            find(si, mid)
    else:
        if ss[mid] ^ ss[si]:
            find(si + 1, mid - 1)
        else:
            find(mid + 1, ei - 1)

def pg(i):
    if (ss[i] >= 0):
        return ss[i]
    
    global found
    print(i)
    s = gi()
    ss[i] = s
    if (s == 2):
        found = i


N = gi()
ss = [-1] * N
found = -1
find(0, N-1)
