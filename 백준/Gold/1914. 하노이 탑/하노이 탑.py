# 재귀함수 - 하노이 탑 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/1914

n = int(input())

arr=[0]*101
arr[1]=1

for i in range(2, 101):
    arr[i]=arr[i-1]*2+1

print(arr[n])

def hanoi(n, fr, mid, to):
    if (n==1):
        print(str(fr)+" "+str(to))
        return

    hanoi(n-1, fr, to, mid)
    print(str(fr)+" "+str(to))
    hanoi(n-1, mid, fr, to)

if (n<=20):
    hanoi(n, 1, 2, 3)
