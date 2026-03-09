# 문자열 - 단어 공부 (백준 브론즈1)
# 문제 링크: https://www.acmicpc.net/problem/1157

s=input()
alphabet=[0]*26

s=s.upper()
for i in s:
    idx=ord(i)-ord('A')
    alphabet[idx]+=1

ans=alphabet.index(max(alphabet))

if (alphabet.count(max(alphabet)) != 1):
    print("?")
else:
    print(chr(ans+ord('A')))