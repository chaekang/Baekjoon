# 링크드리스트 - 에디터 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1406

from collections import deque

if __name__ == "__main__":
    string = input()
    dq=deque(string)

    n = int(input())
    str=list()
    for _ in range(n):
        x = input()
        str.append(x)

    cursor = len(dq)
    count = 0

    for s in str:
        arr = list(s.split())
        if arr[0] == 'L':
            if cursor == 0:
                continue
            else:
                cursor -= 1
                count -= 1
                dq.rotate(1)
        elif arr[0] == "D":
            if cursor == len(dq):
                continue
            else:
                cursor += 1
                count += 1
                dq.rotate(-1)
        elif arr[0] == "B":
            if cursor == 0:
                continue
            else:
                dq.pop()
                cursor -= 1
        else:
            dq.append(arr[1])
            cursor += 1
    
    dq.rotate(count)

    print(''.join(dq))