# 트리 - 이진 검색 트리 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/5639

import sys
sys.setrecursionlimit(100000)

def postorder(start, end):
    if start > end:
        return
    
    root = arr[start]

    mid = end + 1

    for i in range(start+1, end+1):
        if arr[i] > root:
            mid = i
            break
    
    postorder(start+1, mid -1)
    postorder(mid, end)
    print(root)

if __name__ == "__main__":
    arr = list()

    while True:
        try:
            x = int(sys.stdin.readline())
            arr.append(x)
        except:
            break

    postorder(0, len(arr)-1)
