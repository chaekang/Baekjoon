# 1월 9
import sys

n = int(sys.stdin.readline())
tower = list(map(int, sys.stdin.readline().split()))

stack = []
result = [0] * n

for i in range(n-1):
    stack.append(n-1-i)
    while tower and tower[stack[-1]] < tower[-2-i]:
        result[stack.pop()] = stack[-1]
        
print(*result)