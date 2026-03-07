# 파이썬 문법 - 최댓값 (백준 브론즈3)
# 문제 링크: https://www.acmicpc.net/problem/2562

num=[0]*9

for i in range(9):
    num[i]=int(input())

ans=0
index=0

for i in range(9):
    if (num[i]>ans):
        ans=num[i]
        index=i+1

print(ans)
print(index)