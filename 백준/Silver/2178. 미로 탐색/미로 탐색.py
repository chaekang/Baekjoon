# BFS - 미로 탐색 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/2178

from collections import deque

def bfs(x, y, visited):
    global n, m, graph
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    dp = [[0] * m for i in range(n)]

    q = deque()
    q.append((x, y))
    visited[x][y] = True
    dp[x][y] += 1

    while q:
        xx, yy = q.popleft()
        for i in range(4):
            nx = xx+dx[i]
            ny = yy+dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            if graph[nx][ny]==0:
                continue

            if visited[nx][ny]:
                continue

            q.append((nx, ny))
            visited[nx][ny]=True
            dp[nx][ny] = dp[xx][yy] + 1
    
    return dp

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = list()
    for i in range(n):
        tmp = list(map(int, input().strip()))
        graph.append(tmp)

    visited = [[False] * m for i in range(n)]
    ans = bfs(0,0, visited)
    print(ans[n-1][m-1])