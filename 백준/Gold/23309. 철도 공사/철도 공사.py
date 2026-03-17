# 링크드리스트 - 철도 공사 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/23309

import sys

def insert_after(a, b):
    global nxt, prv, ans

    c = nxt[a]
    ans.append(c)
    nxt[a]=b
    nxt[b]=c

    prv[b]=a
    prv[c]=b

def insert_before(a, b):
    global nxt, prv, ans

    c = prv[a]
    ans.append(c)
    prv[a]=b
    prv[b]=c

    nxt[c]=b
    nxt[b]=a

def delete_after(a):
    global nxt, prv, ans

    b = nxt[a]
    c = nxt[b]
    ans.append(b)

    nxt[a]=c
    prv[c]=a

def delete_before(a):
    global nxt, prv, ans

    b = prv[a]
    c = prv[b]
    ans.append(b)

    prv[a]=c
    nxt[c]=a

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    station = list(map(int, sys.stdin.readline().split()))

    prv = [0] * 1000001
    nxt = [0] * 1000001
    ans = list()

    for i in range(n):
        nxt[station[i]]=station[(i+1) % n]
        prv[station[i]]=station[i-1]

    for i in range(m):
        c = list(sys.stdin.readline().split())
        
        if (c[0] == "BN"):
            insert_after(int(c[1]), int(c[2]))
        elif (c[0] == "BP"):
            insert_before(int(c[1]), int(c[2]))
        elif (c[0] == "CP"):
            delete_before(int(c[1]))
        else:
            delete_after(int(c[1]))

    print("\n".join(map(str, ans)))