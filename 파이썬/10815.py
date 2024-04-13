import sys
from collections import Counter

N = int(sys.stdin.readline())
list1 = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
list2 = list(map(int, sys.stdin.readline().split()))

count = Counter(list1)
result = [0] * M

for i in range(M):
    if list2[i] in count:
        result[i] = count[list2[i]]

print(*result)