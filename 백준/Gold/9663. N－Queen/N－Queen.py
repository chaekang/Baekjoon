# 백트래킹 - N-Queen (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/9663

n=int(input())

arr=[0]*n

ans=0

def isPossible(col):
    for i in range(col):
        if (arr[i] == arr[col]):
            return False
        elif (abs(i-col)==abs(arr[i]-arr[col])):
            return False
        
    return True

def NQueen(row):
    global ans
    if (row == n):
        ans += 1
        return
    
    for i in range(n):
        arr[row]=i
        if (isPossible(row)):
            NQueen(row+1)

NQueen(0)
print(ans)