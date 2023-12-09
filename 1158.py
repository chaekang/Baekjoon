import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())

ls = deque(range(1, N+1))
result = [1] * N


for i in range(len(ls)):
    for _ in range(K-1):
        ls.append(ls.popleft())
    result[i] = ls.popleft()

print("<" + str(result)[1: -1] + ">")