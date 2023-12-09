import heapq
import sys

N = int(sys.stdin.readline())
ls = []

for i in range(N):
    x = int(sys.stdin.readline())
    if x != 0:
        heapq.heappush(ls, x)
    else:
        if not ls:
            print("0")
        else:
            print(heapq.heappop(ls))
