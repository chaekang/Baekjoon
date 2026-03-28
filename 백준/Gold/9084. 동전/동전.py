# DP - 동전 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/9084

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        m = int(input())

        dp = [0] * (m+1)
        dp[0] = 1

        for a in arr:
            for i in range(a, m+1):
                dp[i] += dp[i-a]

        print(dp[m])