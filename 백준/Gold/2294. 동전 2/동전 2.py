# BFS - 동전 2 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/2294

from collections import deque

def bfs(arr, target):
    q = deque()
    dp = [int(1e9)] * (target + 1)

    q.append((0, 0))
    dp[0] = 0

    while q:
        money, cnt = q.popleft()
        for a in arr:
            cur = money + a
            if cur > target:
                continue

            if dp[cur] > cnt + 1:
                dp[cur] = cnt + 1
                q.append((cur, cnt+1))
    return dp

if __name__ == "__main__":
    n, k = map(int, input().split())
    arr = list()
    for i in range(n):
        x = int(input())
        arr.append(x)

    ans = bfs(arr, k)

    if ans[k] == 1e9:
        print(-1)
    else:
        print(ans[k])