# DP - LCS (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/9251

INF = 1e9

if __name__ == "__main__":
    a1 = input()
    a2 = input()

    dp = [[0]*(len(a2)+1) for _ in range(len(a1)+1)]

    for i in range(1, len(a1)+1):
        for j in range(1, len(a2)+1):
            if a1[i-1] == a2[j-1]:
                dp[i][j] = dp[i-1][j-1]+1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    print(dp[len(a1)][len(a2)])