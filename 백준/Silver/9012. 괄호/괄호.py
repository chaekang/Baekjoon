T = int(input())
arr = list()


for i in range(T):
    ps = input()
    if len(ps)<2 or len(ps)>50:
        print("NO")
    else:
        arr.append(ps)
    
for ch in arr:
    ps_arr = list(ch)
    stack = list()
    num = 0
    for e in ps_arr:
        if e == "(":
            stack.append(e)
        elif e == ")":
            if not stack:
                num += 1
            else:    
                stack.pop()
                
    if not stack and num == 0:
        print("YES")
    else:
        print("NO")