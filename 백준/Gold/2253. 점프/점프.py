INF = 10**9

if __name__ == "__main__":
    n, m = map(int, input().split())
    blocked = set(int(input()) for _ in range(m))

    if 2 in blocked:
        print(-1)
        exit()

    max_jump = int((2 * n) ** 0.5) + 2
    dp = [[INF] * (max_jump + 1) for _ in range(n + 1)]
    dp[1][0] = 0

    for i in range(2, n + 1):
        if i in blocked:
            continue

        limit = int((2 * i) ** 0.5) + 1
        for j in range(1, limit + 1):
            prev = i - j
            if prev < 1:
                break

            best = dp[prev][j]

            if j - 1 >= 0:
                best = min(best, dp[prev][j - 1])

            if j + 1 <= max_jump:
                best = min(best, dp[prev][j + 1])

            if best != INF:
                dp[i][j] = best + 1

    ans = min(dp[n])
    print(ans if ans != INF else -1)