# 백트래킹 - 비숍 (백준 플래5)
# 문제 링크: https://www.acmicpc.net/problem/1799

import sys

n=0
arr=list()
diag1=list()
diag2=list()
black=list()
white=list()

def Bishop(idx, count, cand):
    global ans
    if idx == len(cand):
        ans=max(ans, count)
        return
    
    x, y=cand[idx]
    d1=x-y+(n-1)
    d2=x+y

    if not diag1[d1] and not diag2[d2]:
        diag1[d1]=True
        diag2[d2]=True
        Bishop(idx+1, count+1, cand)
        diag1[d1]=False
        diag2[d2]=False
    Bishop(idx+1, count, cand)

if __name__ == "__main__":
    n = int(input())
    diag1 = [False] * (2*n)
    diag2 = [False] * (2*n)

    for i in range(n):
        arr.append(list(map(int, sys.stdin.readline().split())))

    for i in range(n):
        for j in range(n):
            if (arr[i][j]==1):
                if ((i+j)%2==0):
                    black.append((i,j))
                else:
                    white.append((i,j))
    ans=0
    Bishop(0,0,black)
    black_ans=ans

    ans=0
    diag1 = [False] * (2*n)
    diag2 = [False] * (2*n)
    Bishop(0,0,white)
    white_ans=ans
    print(black_ans+white_ans)
