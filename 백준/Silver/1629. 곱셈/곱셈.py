# 분할정복 - 곱셈 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/1629

def _pow(a, b, c):
    if (b == 0):
        return 1
    
    if (b < 0):
        return 1 / _pow(a,-b, c)

    half = _pow(a, b//2, c)
    if (b % 2 == 0):
        return (half*half) % c
    else:
        return (half*half*a) % c

if __name__ == "__main__":
    a, b, c = map(int, input().split())

    ans = _pow(a, b, c)
    
    print(ans)