# 1월 7

import sys

n = int(sys.stdin.readline())
cloth = dict()

for i in range(n):
    m = int(sys.stdin.readline())
    for j in range(m):
        clth, sort = sys.stdin.readline().split()
        cloth[clth] = sort
        
