
ans = [[0 for x in range(W)] for i in range(H + 5)]  #[] * N won't work
nbls = [[] for i in range(N + 5)]  #[] * N won't work
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def gw():
    global input_parser
    return next(input_parser)

def gi():
    data = get_word()
    return int(data)

# numpy and scipy are available for use
import numpy
import scipy

###U-F
def union(p, i, j):
    if i == j:
        return
    pi = find(p, i)
    pj = find(p, j)
    p[max(pi, pj)] = min(pi, pj)


def find(p, i):
    if p[i] == i:
        return i
    p[i] = find(p, p[i])
    return p[i]

### array to LL
def toLL(l):
    head = ListNode(l[0])
    tail = head
    for i in range(1, len(l)):
        node = ListNode(l[i])
        tail.next = node
        tail = node
    return head

#print tree
def ppre(root):
    rv = root.val
    print(rv)
    if root.left:
        print(rv, "L:")
        ppre(root.left)
    if root.right:
        print(rv, "R:")
        ppre(root.right)

