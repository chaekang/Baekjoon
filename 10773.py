import sys

K = int(sys.stdin.readline())
arr = [0] * K
n = 0

for i in range(K):
    num = int(sys.stdin.readline())
    if num != 0:
        arr[n] = num
        n += 1
    else:
        arr[n-1] = 0
        n -= 1
        
print(sum(arr))