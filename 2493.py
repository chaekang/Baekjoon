# 1월 9
import sys

n = int(sys.stdin.readline())
tower = list(map(int, sys.stdin.readline().split()))

stack = []
result = []

for i in range(n):
    while stack:
        if stack[-1][1] < tower[i]:
            stack.pop()
        else:
            result.append(stack[-1][0] + 1)
            break
    if not stack:
        result.append(0)
    stack.append([i, tower[i]])
            
print(*result)