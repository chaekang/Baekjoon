# 1월 12

import sys

string = list(map(str, sys.stdin.readline().split()))

bomb = list(map(str, sys.stdin.readline().split()))

result = []

for ch in string:
    if ch not in bomb:
        result.append(ch)
        
print(result)