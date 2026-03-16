# 해시 테이블 - 세 수의 합 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/2295

def binary_search(arr, target):
    left = 0
    right = len(arr)-1

    while (left <= right):
        mid = (left + right) // 2
        if (arr[mid] == target):
            return arr[mid]
        elif (arr[mid] < target):
            left = mid + 1
        else:
            right = mid - 1
    return -1

if __name__ == "__main__":
    n = int(input())
    arr = list()
    for _ in range(n):
        x = int(input())
        arr.append(x)
    arr.sort()

    two_sum = list()

    for i in range(n):
        for j in range(n):
            two_sum.append(arr[i]+arr[j])
    two_sum.sort()
    
    for i in range(n-1, -1, -1):
        for j in range(i+1):
            target = arr[i]-arr[j]
            if (binary_search(two_sum, target) != -1):
                print(arr[i])
                exit()