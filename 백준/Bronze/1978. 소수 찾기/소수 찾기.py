# 정수론 - 소수 찾기 (백준 브론즈2)
# 문제 링크: https://www.acmicpc.net/problem/1978

import math

n = int(input())
arr=list(map(int, input().split()))

prime=list()

def is_prime(n):
    if (n<2):
        return False
    
    for i in range(2, n):
        if (n%i==0):
            return False
    return True

ans=0
for a in arr:
    if (is_prime(a)):
        ans+=1


print(ans)