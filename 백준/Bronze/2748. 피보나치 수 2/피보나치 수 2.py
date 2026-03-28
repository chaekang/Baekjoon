# DP - 피보나치 수 2 (백준 브론즈 1)
# 문제 링크: https://www.acmicpc.net/problem/2748

def solve(n):
    if n <= 2:
        return 1
    
    dp = [0] * (n+1)

    dp[0]=0
    dp[1]=1
    dp[2]=1

    for i in range(3, n+1):
        dp[i] = dp[i-1]+dp[i-2]

    return dp[n]

if __name__ == "__main__":
    n = int(input())
    print(solve(n))