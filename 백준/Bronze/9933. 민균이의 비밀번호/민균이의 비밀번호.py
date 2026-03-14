# 해시 테이블 - 민균이의 비밀번호 (백준 브론즈1)
# 문제 링크: https://www.acmicpc.net/problem/9933

n = int(input())
arr=list()
for i in range(n):
    x = input()
    arr.append(x)

def Solve():
    for i in arr:
        for j in arr:
            if (i == j[::-1]):
                print(str(len(i)) + " " + str(i[len(i) // 2]))
                return
            
Solve()