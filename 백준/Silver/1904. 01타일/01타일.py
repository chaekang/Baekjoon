# DP - 01타일 (백준 실버3)
# 문제 링크: https://www.acmicpc.net/problem/1904

MOD = 15746

def solve(n):
    if n <=2:
        return n
    
    dp = [0] *(n+1)
    dp[0]=0
    dp[1]=1
    dp[2]=2

    for i in range(3, n+1):
        dp[i] = (dp[i-1]%MOD) + (dp[i-2]%MOD)
    
    return (dp[i]%MOD)

if __name__ == "__main__":
    n = int(input())

    print(solve(n))