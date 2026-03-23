# 그래프, DFS, BFS - 점프왕 쩰리 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/16173

def dfs(x, y, visited):
    global arr, dx, dy, n

    if x == n-1 and y == n-1:
        return True

    visited[x][y]=True

    for i in range(2):
        nx = x + (dx[i] * arr[x][y])
        ny = y + (dy[i] * arr[x][y])

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue

        if visited[nx][ny]:
            continue

        if dfs(nx, ny, visited):
            return True
        
    return False

if __name__ == "__main__":
    n = int(input())
    arr = list()
    for i in range(n):
        tmp = list(map(int, input().split()))
        arr.append(tmp)

    visited = [[False]*n for i in range(n)]

    dx = [1, 0]
    dy = [0, 1]

    if (dfs(0, 0, visited)):
        print("HaruHaru")
    else:
        print("Hing")