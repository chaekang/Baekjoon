# 1월 3
import sys
from collections import deque

N = int(sys.stdin.readline())
K = int(sys.stdin.readline())

board = [[0 for j in range(N)] for i in range(N)]
# i = row, j = col

# 회전하는 방향
drow = [0, 1, 0, -1]
dcol = [1, 0, -1, 0]

for _ in range(K):
    row, col = map(int, sys.stdin.readline().split())
    board[row-1][col-1] = 1
    
L = int(sys.stdin.readline())
dirCh = dict()

for _ in range(L):
    x, c = sys.stdin.readline().split()
    dirCh[int(x)] = c

cnt = 0  # 초
row, col = 0, 0  # 뱀의 위치

direction = 0

snake = deque()
snake.append((0, 0))
board[row][col] = 2

def Turn(dir):
    global direction
    if dir == "L":
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4

while True:
    cnt += 1
    row += drow[direction]
    col += dcol[direction]
    
    if row < 0 or col < 0 or row >= N or col >= N:
        break
    
    if board[row][col] == 1:
        board[row][col] == 2
        snake.append((row, col))
        if cnt in dirCh:
            Turn(dirCh[cnt])
            
    elif board[row][col] == 0:
        board[row][col] = 2
        snake.append((row, col))
        prow, pcol = snake.popleft()
        board[prow][pcol] = 0
        if cnt in dirCh:
            Turn(dirCh[cnt])

    else:
        break
    
print(cnt)