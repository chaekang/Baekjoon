import sys
from collections import deque

N = int(sys.stdin.readline())
ls = deque()

for i in range(N):
    ch = sys.stdin.readline().split()
    
    if ch[0] == "push":
        ls.append(ch[1])
    elif ch[0] == "pop":
        if len(ls) == 0:
            print(-1)
        else:
            print(ls.popleft())
    elif ch[0] == "size":
        print(len(ls))
    elif ch[0] == "empty":
        if len(ls) == 0:
            print(1)
        else:
            print(0)
    elif ch[0] == "front":
        if len(ls) == 0:
            print(-1)
        else:
            print(ls[0])
    elif ch[0] == "back":
        if len(ls) == 0:
            print(-1)
        else:
            print(ls[-1])