# 1월 12

import sys

string = sys.stdin.readline().strip()

bomb = sys.stdin.readline().strip()

stack = []

for i in range(len(string)):
    stack.append(string[i])
    if ''.join(stack[-len(bomb):]) == bomb:
        for _ in range(len(bomb)):
            stack.pop()
    
if stack:
    print(''.join(stack))
else:
    print("FRULA")