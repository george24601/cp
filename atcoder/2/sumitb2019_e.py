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

# numpy and scipy are available for use
import numpy
import scipy
#https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
#Colorful Hats 2
"""
WA in all but the last two answers 
"""

# reads a single line
N = gi()
tails = [0] * N

ans = 1
for i in range(N):
    tails[i] = 0
    cur = gi()
    #print(cur)
    if cur == 0:
        tails[cur] += 1
        continue

    tail_c = tails[cur - 1]

    ans *= tail_c
    ans %= MOD
    tails[cur - 1] -= 1
    tails[cur] += 1

num_c = 0
for v in tails:
    num_c += v

if num_c == 1:
    ans *= 3
elif num_c > 1:
    ans *= 6

ans %= MOD

print(ans)

