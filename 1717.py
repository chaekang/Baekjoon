# 1월 6
# union-find 알고리즘
import sys
sys.setrecursionlimit(100000)  # 재귀의 최대 깊이 설정

n, m = map(int, sys.stdin.readline().split())

parent = list(range(n+1))

def getParent(parent, x):
    if parent[x] == x:
        return x
    parent[x] = getParent(parent, parent[x])
    return parent[x]

def unionParent(parent, a, b):
    a = getParent(parent, a)
    b = getParent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b
        
for i in range(m):
    u, a, b = map(int, sys.stdin.readline().split())
    if u == 0:
        unionParent(parent, a, b)
    else:
        a = getParent(parent, a)
        b = getParent(parent, b)

        if a == b:
            print("YES")
        else:
            print("NO")