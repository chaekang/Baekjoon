# 큐 - 카드2 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/2164

from collections import deque

if __name__ == "__main__":
    n = int(input())
    arr = list()
    for i in range(n):
        arr.append(i+1)

    dp = deque(arr)

    while (len(dp) > 1):
        dp.popleft()

        x = dp.popleft()
        dp.append(x)
    print(str(dp[0]))