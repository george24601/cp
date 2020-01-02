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
"""

# reads a single line
N = gi()
tails = [0] * (N + 5)

tails[0] = 3
ans = 1
for i in range(N):
    a = gi()
    ans *= tails[a]
    ans %= MOD
    tails[a] -= 1
    tails[a + 1] += 1

print(ans)
