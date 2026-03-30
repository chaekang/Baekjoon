# DP - 평범한 배낭 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/12865

if __name__ == "__main__":
    n, k = map(int, input().split())

    arr=list()
    for i in range(n):
        w, v = map(int, input().split())
        arr.append((w, v))

    dp = [0]*(k+1)
    dp[0] = 0
    for w, v in arr:
        for i in range(k, w-1, -1):
            dp[i] = max(dp[i], dp[i-w]+v)

    print(dp[k])