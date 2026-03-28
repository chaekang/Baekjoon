# 그리디 - 동전 0 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/11047

if __name__ == "__main__":
    n, k = map(int, input().split())
    arr=list()
    for i in range(n):
        arr.append(int(input()))

    arr.sort(reverse=True)

    ans=0
    for a in arr:
        used = k // a
        ans += used
        k %= a

    print(ans)