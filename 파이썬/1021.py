# 1월 2
import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
ls = list(map(int, sys.stdin.readline().split()))

dq = deque(range(1, N + 1))
count = 0

for i in range(M):
    while True:
        if dq[0] == ls[i]:
            dq.popleft()
            break
        else:
            if dq.index(ls[i]) < len(dq)/2:
                while dq[0] != ls[i]:
                    dq.rotate(-1)
                    count += 1
            else:
                while dq[0] != ls[i]:
                    dq.rotate(1)
                    count += 1
                
print(count)