# 1월 4
import sys

N = int(sys.stdin.readline())
ls = list(map(int, sys.stdin.readline().split()))
stack = [0]
result = [-1] * N

for i in range(1, N):
    while stack and ls[stack[-1]] < ls[i]:
        result[stack.pop()] = ls[i]
    stack.append(i)
    
print(*result)