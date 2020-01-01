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


# numpy and scipy are available for use
import numpy
import scipy
#https://atcoder.jp/contests/abc147/tasks/abc147_c
#HonestOrUnkind2


def best(bm):
    res = [-1] * N
    for i in range(N):
        if (bm & (1 << i) == 0):
            if (res[i] == 1):
                return -1

            res[i] = 0
            continue

        if (res[i] == 0):
            return -1

        res[i] = 1

        for x, y in ts[i]:
            #   print("%d %d %d" % (i, x, y))
            if res[x] == -1:
                res[x] = y
            elif res[x] != y:
                return -1

    cnt = 0

    for v in res:
        if v:
            cnt += 1

    return cnt


# reads a single line
N = gi()
ts = []

for i in range(N):
    ai = gi()
    ts.append([])
    for j in range(ai):
        x = gi() - 1
        y = gi()
        ts[i].append((x, y))

ans = 0
for bitmap in range(1 << N):
    ans = max(ans, best(bitmap))

print(ans)

