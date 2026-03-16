# 해시 테이블 - 민균이의 비밀번호 (백준 브론즈1)
# 문제 링크: https://www.acmicpc.net/problem/9933

if __name__ == "__main__":
    n = int(input())
    arr = list()
    for _ in range(n):
        x = input()
        arr.append(x)

    for i in arr:
        for j in arr:
            if (i == j[::-1]):
                print(str(len(i)) + " " + str(i[len(i) // 2]))
                exit()