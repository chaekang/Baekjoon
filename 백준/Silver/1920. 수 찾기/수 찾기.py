# 이분탐색 - 수 찾기 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/1920

def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while (left <= right):
        mid = (left + right) // 2
        if (arr[mid] == target):
            return True
        elif (arr[mid] < target):
            left = mid + 1
        else:
            right = mid - 1
    return False

if __name__ == "__main__":
    n = int(input())
    arr=list(map(int, input().split()))

    m_num = int(input())
    m = list(list(map(int, input().split())))

    arr.sort()

    for i in m:
        if (binary_search(arr, i)):
            print(1)
        else:
            print(0)