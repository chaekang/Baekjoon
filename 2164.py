import sys
from collections import deque

N = int(sys.stdin.readline())
deque = deque()
temp1 = list(range(N))
temp2 = [1] * N

for i in range(N):
    deque.append(temp1[i] + temp2[i])
    
while len(deque) > 1:
    deque.popleft()
    deque.rotate(-1)
    
print(deque[0])