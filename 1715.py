# 1월 8
import sys
import heapq

n = int(sys.stdin.readline())
heap = []
cnt = 0

for i in range(n):
    num = int(sys.stdin.readline())
    heapq.heappush(heap, num)

while len(heap) > 1:
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)

    result = a + b
    cnt += result
    heapq.heappush(heap, result)
    
print(cnt)