# 정수론 - 제곱 ㄴㄴ 수 (백준 골드1)
# 문제 링크: https://www.acmicpc.net/problem/1016

import sys

if __name__ == "__main__":
    min, max = map(int, sys.stdin.readline().split())

    size = max-min+1
    check=[False]*size

    i=2
    while(i*i<=max):
        square=i*i
        start = ((min + square - 1) // square) * square
        for j in range(start, max+1, square):
            if j%square == 0:
                check[j-min]=True
        i+=1

    print(check.count(False))