# 큐 - 카드2 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/2164
from collections import deque

n = int(input())

arr = list()
for i in range(1, n+1):
    arr.append(i)

q = deque(arr)

while (len(q) > 1):
    q.popleft()
    x = q.popleft()
    q.append(x)

print(q[0])