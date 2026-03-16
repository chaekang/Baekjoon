# 이분탐색 - 수 찾기 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/1920

def binary_search(arr, target):
    left = 0
    right = len(arr)-1

    while (left <= right):
        mid = (left+right) // 2
        if (arr[mid] == target):
            return True
        elif (arr[mid] < target):
            left = mid + 1
        else:
            right = mid - 1
    return False

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    m = int(input())
    m_list = list(map(int, input().split()))

    for i in m_list:
        if (binary_search(a, i)):
            print(1)
        else:
            print(0)