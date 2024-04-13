# 1월 1
import sys
from collections import deque

string = deque(list(sys.stdin.readline().strip()))
M = int(sys.stdin.readline())

count = 0
cursor = len(string)

for i in range(M):
    order = sys.stdin.readline().strip()
    ch = order.split()
    
    if ch[0] == "L":
        if cursor == 0:
            continue
        else:
            string.rotate(1)
            count += 1
            cursor -= 1
    elif ch[0] == "D":
        if cursor == len(string):
            continue
        else:
            string.rotate(-1)
            count -= 1
            cursor += 1
    elif ch[0] == "B":
        if cursor == 0:
            continue
        else:
            string.pop()
            cursor -= 1
    elif ch[0] == "P":
        string.append(ch[1])
        cursor += 1

string.rotate(-count)   
print(''.join(string))