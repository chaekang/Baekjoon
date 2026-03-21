# 그래프, DFS, BFS - 바이러스 (백준 실버3)
# 문제 링크: https://www.acmicpc.net/problem/2606

from collections import deque

def bfs(graph, x, visited):
    cnt=0
    q = deque()
    q.append(x)
    visited[x] = True

    while q:
        p = q.pop()
        for i in range(len(graph[p])):
            v = graph[p][i]
            if visited[v]:
                continue

            q.append(v)
            visited[v]=True
            cnt += 1
    
    return cnt

if __name__ == "__main__":
    v = int(input())
    e = int(input())

    graph = {i: [] for i in range(v+1)}

    for _ in range(e):
        u, m = map(int, input().split())
        graph[u].append(m)
        graph[m].append(u)

    visited = [False] * (v+1)

    print(bfs(graph, 1, visited))

