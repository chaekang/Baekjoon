# 그리디 - 신입 사원 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/1946

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())
        arr = list()
        for i in range(n):
            doc, inter = map(int, input().split())

            arr.append((doc, inter))

        arr.sort()
        ans=0
        score=n+1

        for i in range(n):
            doc, inter = arr[i]
            if inter < score:
                ans += 1
                score=inter
        
        print(ans)