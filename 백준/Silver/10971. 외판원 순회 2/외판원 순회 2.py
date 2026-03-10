# 백트래킹 - 외판원 순회 2 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/10971

n=int(input())

arr = [0]*n
visited = [False] * n

for i in range(n):
    arr[i]= list(map(int, input().split()))

result=list()
ans=999999999
def tsp(start, end, cost, depth):
    global ans
    if (depth == n and end == start):
        ans = min(ans, cost + arr[end][start])
        return

    for i in range(n):
        if (not visited[i] and arr[end][i]!=0):
            visited[i]=True
            tsp(start, i, cost + arr[end][i], depth+1)
            visited[i]=False

for i in range(0, n):
    tsp(i, i, 0, 0)
    visited[:] = [False]*n


print(ans)