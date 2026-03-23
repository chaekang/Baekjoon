# 그래프, DFS, BFS - DFS와 BFS (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1260

from collections import deque

def dfs(graph, start, visited):
    visited.append(start)

    for i in range(len(graph[start])):
        cur = graph[start][i]
        if cur not in visited:
            dfs(graph, cur, visited)

    return visited

def bfs(graph, start, visited):
    q = deque()
    q.append(start)
    visited.append(start)

    while q:
        x = q.popleft()
        for i in range(len(graph[x])):
            cur = graph[x][i]

            if cur not in visited:
                q.append(cur)
                visited.append(cur)

    return visited

if __name__ == "__main__":
    n, m, v = map(int, input().split())
    graph = {i:[] for i in range(n+1)}

    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    for i in range(1, n+1):
        graph[i].sort()
    
    print(*dfs(graph, v, []))
    print(*bfs(graph, v, []))