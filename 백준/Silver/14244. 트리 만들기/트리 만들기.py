# 트리 - 트리 만들기 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/14244

if __name__ == "__main__":
    n, m = map(int, input().split())

    last = n-m

    for i in range(last+1):
        print(f"{i} {i+1}")
    
    for i in range(last + 1, n - 1):
        print(f"{last} {i+1}")