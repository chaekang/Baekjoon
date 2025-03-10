import sys

N = int(sys.stdin.readline())
A_arr = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
M_arr = list(map(int, sys.stdin.readline().split()))

A_arr.sort()
for target in M_arr:
    start, end = 0, N - 1
    is_Exist = False
    
    while start <= end:
        mid = (start + end) // 2
        
        if A_arr[mid] == target:
            is_Exist = True
            print(1)
            break
        elif A_arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    if not is_Exist:
        print(0)