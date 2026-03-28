# 그리디 - 회의실 배정 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/1931

if __name__ == "__main__":
    n = int(input())

    arr = list()
    for i in range(n):
        start, end = map(int, input().split())
        arr.append((start, end))

    arr.sort(key=lambda x:(x[1], x[0]))

    cnt = 0
    end_time=0
    for i in range(n):
        start, end = arr[i]

        if end_time <= start:
            end_time = end
            cnt += 1

    print(cnt)