import sys
from collections import deque

K = int(sys.stdin.readline())

for _ in range(K):
    N, M = map(int, sys.stdin.readline().split())
    ls = deque(list(map(int, sys.stdin.readline().split())))
    
    count = 0  # 회전한 횟수
    
    while ls:
        if ls[0] == max(ls):  # 첫번째 값이 가장 큰 값이면
            count += 1
            if M == 0:  # 내가 찾는 값이 가장 먼저 나와 있으면
                print(count)
                break
            else: # 내가 찾는 값이 아닌 값이면
                ls.popleft() # 삭제
                M -= 1 # 회전
        else:
            ls.append(ls.popleft())
            if M == 0:
                M = len(ls) - 1
            else:
                M -= 1
