# 1월 10
import sys

n, m = map(int, sys.stdin.readline().split())

a = set(map(int, sys.stdin.readline().split()))
b = set(map(int, sys.stdin.readline().split()))

result = a ^ b

print(len(result))