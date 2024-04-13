import sys
from collections import deque

T = int(sys.stdin.readline())

for i in range(T):
    error = False
    p = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    num_list = deque(sys.stdin.readline().strip()[1:-1].split(','))
    R = 0 
    if n == 0:
        num_list = deque()

    for ch in p:
        if ch == "R":
            R += 1
        elif ch == "D":
            if not num_list:
                error = True
                break
            else:
                if R % 2 == 0:
                    num_list.popleft()
                else:
                    num_list.pop()
    
    if error:
        print("error")
    else:
        if R % 2 == 0:
            print('[' +  ','.join(num_list) + ']')
        else:
            num_list.reverse()
            print('[' +  ','.join(num_list) + ']')