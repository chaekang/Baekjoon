# 그래프, DFS, BFS - 연결 요소의 개수 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/11724

def dfs(graph, start):
    global visited
    visited[start]=True

    for i in range(len(graph[start])):
        cur = graph[start][i]
        if not visited[cur]:
            dfs(graph, cur)

if __name__ == "__main__":
    n, m = map(int, input().split())

    graph = {i:[] for i in range(n+1)}

    for i in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * (n+1)
    ans=0

    for i in range(1, n+1):
        if not visited[i]:
            dfs(graph, i)
            ans+=1
    
    print(ans)