# 정수론 - 골드바흐의 추측 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/9020

import sys
import math

t = int(sys.stdin.readline())

arr=list()

def isPrime(n):
    if n < 2:
        return False
    
    for i in range(2, int(math.sqrt(n)+1)):
        if (n%i == 0):
            return False
    return True

for i in range(2, 5000):
    if (isPrime(i)):
        arr.append(i)

for _ in range(t):
    n = int(sys.stdin.readline())

    a = n//2
    b = n//2
    while True:
        if (isPrime(a) and isPrime(b)):
            if (a+b == n):
                print(str(a)+" "+str(b))
                break
        a-=1
        b+=1