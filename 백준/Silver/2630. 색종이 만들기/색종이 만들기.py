# 분할정복 - 색종이 만들기 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/2630

def color_paper(x, y, k):
    global white
    global blue

    global arr
    is_cut = False
    first_color = arr[x][y]
    for i in range(x, x+k):
        for j in range(y, y+k):
            if (first_color != arr[i][j]):
                is_cut=True
                break
    
    if (is_cut):
        color_paper(x, y, k//2)
        color_paper(x + k//2, y, k//2)
        color_paper(x, y + k//2, k//2)
        color_paper(x + k//2, y + k//2, k//2)
    else:
        if (first_color == 0):
            white += 1
        else:
            blue += 1

if __name__ == "__main__":
    n = int(input())

    arr = list()
    for _ in range(n):
        x = list(map(int, input().split()))
        arr.append(x)

    white = 0
    blue = 0

    color_paper(0, 0, n)
    print(white)
    print(blue)