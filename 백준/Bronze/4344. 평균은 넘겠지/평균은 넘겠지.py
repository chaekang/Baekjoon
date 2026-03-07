# 배열 - 평균은 넘겠지 (백준 브론즈1)
# 문제 링크: https://www.acmicpc.net/problem/4344

c=int(input())

for _ in range(c):
    m=list(map(int, input().split()))
    n=m[0]
    score=[0]*(n)
    for i in range(1, n+1):
        score[i-1]=m[i]

    avg=0
    for i in range(n):
        avg+=score[i]
    avg/=n

    ans=0
    for i in range(n):
        if (score[i]>avg):
            ans+=1
    ans/=n
    ans*=100
    print(str(f"{ans:.3f}")+"%")