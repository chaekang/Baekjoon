# 그리디 - 잃어버린 괄호 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1541

if __name__ == "__main__":
    formula = input().strip()

    parts = formula.split('-')
    nums = list()

    for p in parts:
        tmp = sum(map(int, p.split('+')))
        nums.append(tmp)

    ans = nums[0]
    for i in range(1, len(nums)):
        ans -= nums[i]

    print(ans)