import sys
from collections import Counter

N = int(sys.stdin.readline())
list1 = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
list2 = list(map(int, sys.stdin.readline().split()))

result = [0] * M

count = Counter(list1)

for i in range(M):
    if list1[i] in count:
        result[i] = count[list2[i]]
    else:
        result[i] = 0
        
print(*result)