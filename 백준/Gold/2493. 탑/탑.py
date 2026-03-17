# 스택 - 탑 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/2493


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    stack = list()
    ans = list()

    for i in range(n):
        while stack:
            if (arr[i] > stack[-1][1]):
                stack.pop()
            else:
                ans.append(stack[-1][0] + 1)
                break
        if not stack:
            ans.append(0)
        stack.append([i, arr[i]])

    print(*ans)