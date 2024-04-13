# 1월 11
import sys

n = int(sys.stdin.readline())

company = dict()
result = []

for i in range(n):
    name, status = map(str, sys.stdin.readline().split())

    company[name] = status

for key, value in company.items():
    if value == "enter":
        result.append(key)
        
result.sort(reverse=True)
print(*result, sep='\n')