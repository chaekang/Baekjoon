import sys
import heapq

N = int(sys.stdin.readline())
plus_heap = []
minus_heap = []

for i in range(N):
    x = int(sys.stdin.readline())
    
    if x > 0:
        heapq.heappush(plus_heap, x)
    elif x < 0:
        heapq.heappush(minus_heap, -x)
    else:
        if len(plus_heap) == 0 and len(minus_heap) == 0:
            print(0)
        elif len(plus_heap) != 0 and len(minus_heap) == 0:
            print(heapq.heappop(plus_heap))
        elif len(plus_heap) == 0 and len(minus_heap) != 0:
            print(-heapq.heappop(minus_heap))
        else:
            plus = plus_heap[0]
            minus = -minus_heap[0]
            if abs(plus) < abs(minus):
                print(heapq.heappop(plus_heap))
            else:
                print(-heapq.heappop(minus_heap))