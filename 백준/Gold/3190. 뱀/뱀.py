# 큐 - 뱀 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/3190

from collections import deque

def turn(dir):
    global direction
    if dir == "L":
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4

if __name__ == "__main__":
    n = int(input())
    k = int(input())

    arr=[[0]*(n+1) for i in range(n+1)]
    for i in range(k):
        x, y = map(int, input().split())
        arr[x][y] = 1

    l = int(input())
    command = dict()
    for i in range(l):
        x, c = map(str, input().split())
        command[int(x)] = c
    
    snake = deque()
    snake.append((1, 1))

    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    i = 1
    j = 1
    ans=0
    direction = 0

    while True:
        i+=dx[direction]
        j+=dy[direction]
        ans+=1

        if (i > n or j > n or i <= 0 or j <= 0):
            break

        if ((i,j) in snake):
            break

        snake.append((i,j))

        if arr[i][j] != 1:
            snake.popleft()
        else:
            arr[i][j] = 0
        
        if (ans in command):
            turn(command[ans])

    print(ans)