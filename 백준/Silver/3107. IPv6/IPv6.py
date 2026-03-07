# 문자열 - IPv6 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/3107

arr=input()


if ('::' in arr):
    left, right = arr.split('::')
    left=left.split(':')
    right=right.split(':')

    temp=["0000"]
    arr = left
    for i in range(8-len(left)-len(right)):
        arr+=temp
    arr+=right
else:
    arr=arr.split(':')

for i in range(8):
    if (len(arr[i])<4):
        tmp=''
        for j in range(4-len(arr[i])):
            tmp+='0'
        arr[i]=tmp+arr[i]

ans=':'.join(arr)
print(ans)