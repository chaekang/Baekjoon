# DP - 점프 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/2253

INF = int(1e9)

if __name__ == "__main__":
    n, m = map(int, input().split())

    blocked = set(int(input()) for _ in range(m))

    max_jump = int((2 * n) ** 0.5) + 2
    dp = [[INF] * (max_jump + 1) for _ in range(n + 1)]

    dp[1][0] = 0

    if 2 not in blocked:
        dp[2][1] = 1


    for i in range(3, n + 1):
        if i in blocked:
            continue

        for j in range(1, max_jump + 1):
            prev = i - j
            if prev < 1:
                continue

            tmp1 = INF
            tmp2 = INF
            tmp3 = INF
            if j-1 > 0:
                tmp1 = dp[prev][j-1]
            
            tmp2 = dp[prev][j]
            if j+1 <= max_jump:
                tmp3 = dp[prev][j+1]

            dp[i][j] = min(tmp1, tmp2, tmp3)+1

    ans = min(dp[n])

    if ans != INF:
        print(ans)
    else:
        print(-1)