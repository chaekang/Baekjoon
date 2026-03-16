# 링크드리스트 - 에디터 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1406

from collections import deque

if __name__ == "__main__":
    string = input()

    n = int(input())
    s = list()
    for _ in range(n):
        x = input()
        s.append(x)

    dq = deque(string)

    count = 0
    cursor = len(dq)

    for i in range(n):
        command = list(s[i].split())

        if (command[0] == 'L'):
            if cursor == 0:
                continue
            else:
                dq.rotate(1)
                cursor -= 1
                count -= 1
        elif (command[0] == 'D'):
            if cursor == len(dq):
                continue
            else:
                dq.rotate(-1)
                cursor += 1
                count += 1
        elif (command[0] == "B"):
            if cursor == 0:
                continue
            else:
                dq.pop()
                cursor -= 1
        else:
            dq.append(command[1])
            cursor +=1
    
    dq.rotate(count)

    print(''.join(dq))