# 그리디 - 동전 0 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/11047

if __name__ == "__main__":
    n, k = map(int, input().split())

    arr = [0]*n

    for i in range(n):
        arr[i]=int(input())

    arr.sort(reverse=True)
    
    count = 0
    for i in range(len(arr)):
        used = k//arr[i]
        count += used
        k %= arr[i]

    print(count)