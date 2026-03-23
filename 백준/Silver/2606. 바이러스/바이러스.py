# 그래프, DFS, BFS - 바이러스 (백준 실버3)
# 문제 링크: https://www.acmicpc.net/problem/2606

from collections import deque

def bfs(graph, start, visited):
    q = deque()
    q.append(start)
    visited[start] = True
    ans = 0

    while q:
        x = q.popleft()
        for i in range(len(graph[x])):
            cur = graph[x][i]
            if visited[cur]:
                continue
            q.append(cur)
            visited[cur]=True
            ans += 1
    return ans

if __name__ == "__main__":
    c = int(input())
    n = int(input())
    arr = {i:[] for i in range(c + 1)}

    for i in range(n):
        u, v = map(int, input().split())
        arr[u].append(v)
        arr[v].append(u)

    visited = [False] * (c+1)
    print(bfs(arr, 1, visited))