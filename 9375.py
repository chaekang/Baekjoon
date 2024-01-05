# 1월 7

import sys

n = int(sys.stdin.readline())

for i in range(n):
    m = int(sys.stdin.readline())
    closet = dict()
    for j in range(m):
        clth, sort = sys.stdin.readline().split()
        if sort in closet:
            closet[sort].append(clth)
        else:
            closet[sort] = [clth]

    cnt = 1

    for key in closet:
        cnt *= len(closet[key]) + 1
        
    print(cnt-1)