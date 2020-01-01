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
#https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d 
#D - Lucky PIN
"""
iterate over bits
1. calculate how many bits we have on that position
2. for each 1, we need to add num 0s * num 1s * 2s
3. sum them up

This version has TLE
"""

# reads a single line
N = gi()
S = gw()

ans = 0
for fd in range(10):
    fi = -1
    for i in range(N):
        if int(S[i]) == fd:
            fi = i
            break
    if fi < 0:
        continue
    for sd in range(10):
        si = -1
        for i in range(fi + 1, N):
            if int(S[i]) == sd:
                si = i
                #                print(i, S[i])
                break
        if si < 0:
            continue
        for td in range(10):
            for i in range(si + 1, N):
                if int(S[i]) == td:
                    ans += 1
                    #                    print(fd, sd, td)
                    break

print(ans)
