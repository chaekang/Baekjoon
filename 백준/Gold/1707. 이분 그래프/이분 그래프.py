# DFS - 이분 그래프 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/1707
import sys
sys.setrecursionlimit(100000)

def dfs(graph, start, color, visited):
    visited[start] = color
    
    for i in range(len(graph[start])):
        cur = graph[start][i]

        if visited[cur] == -1:
            if not dfs(graph, cur, 1-color, visited):
                return False
        elif visited[cur] == color:
            return False
        
    return True

if __name__ == "__main__":
    k = int(input())

    for _ in range(k):
        v, e = map(int, input().split())
        graph = {i:[] for i in range(v+1)}
        visited = [-1] * (v+1)

        for i in range(e):
            x, y = map(int, input().split())
            graph[x].append(y)
            graph[y].append(x)

        ans = True
        for i in range(1, v+1):
            if visited[i] == -1:
                ans = dfs(graph, i, 0, visited)
                if not ans:
                    break

        if ans:
            print("YES")
        else:
            print("NO")