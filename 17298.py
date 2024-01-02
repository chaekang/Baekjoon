# 1월 4
import sys

N = int(sys.stdin.readline())
ls = list(map(int, sys.stdin.readline().split()))
result = []
stack = [-1] * N

for i in range(N):
    stack[i] = ls[i]