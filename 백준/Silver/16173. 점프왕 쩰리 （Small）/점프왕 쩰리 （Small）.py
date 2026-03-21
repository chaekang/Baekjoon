# 그래프, DFS, BFS - 점프왕 쩰리 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/16173

def dfs(xx, yy, visited):
    global arr, dx, dy, n

    if (xx == n-1 and yy == n-1):
        return True

    visited[xx][yy] = True

    for i in range(2):
        nx = xx + (dx[i] * arr[xx][yy])
        ny = yy + (dy[i] * arr[xx][yy])

        if (nx < 0 or ny < 0 or nx >= n or ny >= n):
            continue

        if visited[nx][ny]:
            continue

        if dfs(nx, ny, visited):
            return True
    return False


if __name__ == "__main__":
    n = int(input())

    arr = []

    for i in range(n):
        tmp = list(map(int, input().split()))
        arr.append(tmp)

    dx = [1, 0]
    dy = [0, 1]

    visited = [[False] * n for _ in range(n)]

    if (dfs(0, 0, visited)):
        print("HaruHaru")
    else:
        print("Hing")