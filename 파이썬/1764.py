import sys

N, M = map(int, sys.stdin.readline().split())

hear = set()
see = set()

for i in range(N):
    hear.add(sys.stdin.readline().strip()) # strip으로 개형문자 없애기

for i in range(M):
    see.add(sys.stdin.readline().strip())

result = hear & see

result = list(result)
result.sort()

print(len(result))

for i in result:
    print(i)