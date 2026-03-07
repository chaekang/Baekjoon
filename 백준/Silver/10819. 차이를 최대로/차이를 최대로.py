# 완전탐색 - 차이를 최대로 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/10819
from itertools import permutations

n=int(input())
arr=list(map(int, input().split()))
p=list(permutations(arr, n))
ans=0

for i in p:
    tmp=0
    for j in range(n-1):
        tmp+=abs(i[j]-i[j+1])
    ans=max(ans, tmp)

print(ans)