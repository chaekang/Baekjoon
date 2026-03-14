# 스택 - 스택 (백준 실버 4)
# 문제 링크: https://www.acmicpc.net/problem/10828

def stack(arr, str):
    s = list(str.split())

    if s[0] == "push":
        arr.append(s[1])
    elif s[0] == "pop":
        if arr:
            x = arr.pop()
            print(x)
        else:
            print("-1")
    elif s[0] == "size":
        print(len(arr))
    elif s[0] == "empty":
        if arr:
            print("0")
        else:
            print("1")
    elif s[0] == "top":
        if arr:
            print(arr[-1])
        else:
            print("-1")


if __name__ == "__main__":

    n = int(input())
    arr=list()

    for _ in range(n):
        x = input()
        stack(arr, x)